#define CVPLOT_HEADER_ONLY
#include <CvPlot/cvplot.h>
#include <rapidcsv.h>

#include <iostream>
#include <string>
#include <utility>
#include <vector>

struct LegendCustom : public CvPlot::Drawable
{
    void render(CvPlot::RenderTarget &render_target) override
    {
        auto tmp_p1 = render_target.project({legend_rect_.x, legend_rect_.y});
        auto tmp_p2 =
            render_target.project({legend_rect_.x + legend_rect_.width, legend_rect_.y - legend_rect_.height});
        cv::rectangle(render_target.innerMat(), cv::Rect2d(tmp_p1, tmp_p2), cv::Scalar(100, 100, 100), 1);

        int it_i = 1;
        for (auto itr = legend_entries_.begin(); itr < legend_entries_.end(); ++itr, ++it_i)
        {
            auto tmp_p3 = render_target.project(
                {legend_rect_.x + dist_b_entries_, legend_rect_.y - it_i * (font_size + dist_b_entries_)});
            cv::putText(render_target.innerMat(), itr->first, tmp_p3, cv::FONT_HERSHEY_PLAIN, font_size, itr->second);
        }
    }

   public:
    explicit LegendCustom(const LegendCustom *legend_in)
        : legend_rect_(legend_in->legend_rect_),
          legend_entries_(legend_in->legend_entries_),
          dist_b_entries_(legend_in->dist_b_entries_),
          font_size(legend_in->font_size)
    {
    }

    explicit LegendCustom(const cv::Point2d &legend_pos)
    {
        legend_rect_ = cv::Rect2d(legend_pos.x, legend_pos.y, 10, 10);
    }

    void add_legend_entry(const std::string &entry, const cv::Scalar &color)
    {
        legend_entries_.emplace_back(entry, color);
    }

   private:
    cv::Rect2d legend_rect_;
    std::vector<std::pair<std::string, cv::Scalar>> legend_entries_;
    int dist_b_entries_ = 1;

   public:
    int font_size = 2;
};

auto main() -> int
{
    // Dataset from: https://www.ncei.noaa.gov/metadata/geoportal/rest/metadata/item/gov.noaa.ncdc:C00947/html
    // Dataset documentation:
    // https://www.ncei.noaa.gov/data/global-summary-of-the-year/doc/GSOM_GSOY_Description_Document_v1.0.2_20200219.pdf
    // available stations: https://www.ncei.noaa.gov/pub/data/ghcn/daily/ghcnd-stations.txt
    rapidcsv::Document doc(std::string(RESOURCEPATH) + "/GME00102404.csv", rapidcsv::LabelParams(0, 0),
                           rapidcsv::SeparatorParams(), rapidcsv::ConverterParams(true));

    auto dates = doc.GetColumn<int>("DATE");
    auto tavg = doc.GetColumn<float>("TAVG");
    auto emxt = doc.GetColumn<float>("EMXT");

    // prepare axes object
    auto axes = CvPlot::makePlotAxes();
    auto legend = LegendCustom(cv::Point2d(1940, 36));

    // plot the average temperature
    axes.create<CvPlot::Series>(dates, tavg, "-g");

    // plot the extreme max temperature
    axes.create<CvPlot::Series>(dates, emxt, "-b");

    // test own drawable
    legend.add_legend_entry("test1", cv::Scalar(0, 255, 0));
    legend.add_legend_entry("test2", cv::Scalar(255, 0, 0));
    axes.create<LegendCustom>(&legend);

    // some settings for the plot
    axes.title("Weather analysis over years in Konstanz");
    axes.yLabel("temperature in degrees C");
    axes.xLabel("year");

    // write the plot to file
    cv::Mat mat = axes.render(600, 800);
    cv::imwrite("weather_over_years_konstanz.jpg", mat);

    return 0;
}