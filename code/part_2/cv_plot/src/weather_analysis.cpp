#define CVPLOT_HEADER_ONLY   // necessary to use CvPlot as a pure template library
#pragma GCC diagnostic push  // disable gcc warnings for cvplot
#pragma GCC diagnostic ignored "-Wcatch-value"
#include <CvPlot/cvplot.h>
#pragma GCC diagnostic pop
#include <rapidcsv.h>

#include <iostream>
#include <string>
#include <utility>
#include <vector>

/**
 * @brief create a custom drawable to be able to add a legend for the plots
 */
class LegendCustom : public CvPlot::Drawable
{
   public:
    /**
     * @brief override the render method from "drawable" -> this method is called when drawing the drawable into the
     * image
     */
    void render(CvPlot::RenderTarget &render_target) override
    {
        // create the points of the bounding box and project it to image coordinates
        auto tmp_p1 = render_target.project({legend_rect_.x, legend_rect_.y});
        auto tmp_p2 =
            render_target.project({legend_rect_.x + legend_rect_.width, legend_rect_.y - legend_rect_.height});
        // create the final opencv rectangle in the image
        cv::rectangle(render_target.innerMat(), cv::Rect2d(tmp_p1, tmp_p2), cv::Scalar(100, 100, 100), 1);

        // iterate over all legend entries and add them to the image
        int it_i = 0;
        for (auto itr = legend_entries_.begin(); itr < legend_entries_.end(); ++itr, ++it_i)
        {
            // the x position is always the left position of the rect + the distance to the border
            // the y position starts with the distance of the border and "decreases" with every entry by the font scale
            auto tmp_p3 = render_target.project(
                {legend_rect_.x + dist_b_entries_,
                 legend_rect_.y - it_i * (font_scale_ + dist_b_entries_) - dist_b_entries_ - font_scale_});
            cv::putText(render_target.innerMat(), itr->first, tmp_p3, cv::FONT_HERSHEY_PLAIN, font_scale_, itr->second);
        }
    }

    /**
     * @brief Imitate a copy constructor by using a pointer. The parent drawable has deleted the copy-constructor, so we
     * have to use a pointer for that.
     * @param legend_in pointer to existing LegendCustom object
     */
    explicit LegendCustom(const LegendCustom *legend_in)
        : legend_rect_(legend_in->legend_rect_),
          legend_entries_(legend_in->legend_entries_),
          dist_b_entries_(legend_in->dist_b_entries_),
          font_scale_(legend_in->font_scale_)
    {
    }

    /**
     * @brief Standard constructor which receives the position of the legend
     * @param legend_pos position of the legend
     */
    explicit LegendCustom(const cv::Point2d &legend_pos)
    {
        legend_rect_ = cv::Rect2d(legend_pos.x, legend_pos.y, initial_rect_width_, 0);
    }

    /**
     * @brief add an entry to the legend
     * @param entry content of the new entry
     * @param color color of the new entry
     */
    void add_legend_entry(const std::string &entry, const cv::Scalar &color)
    {
        legend_entries_.emplace_back(entry, color);
        legend_rect_.height =
            static_cast<double>(legend_entries_.size()) * (font_scale_ + dist_b_entries_) + dist_b_entries_;
    }

    /**
     * @brief set the new width of the legend bounding box
     * @param width new width
     */
    void set_width(double new_width)
    {
        legend_rect_.width = new_width;
    }

    /**
     * @brief set the new font scale of the legend entries
     * @param scale new font scale
     */
    void set_font_scale(int new_scale)
    {
        font_scale_ = new_scale;
    }

   private:
    cv::Rect2d legend_rect_;                                          // rectangle for the bounding box of the legend
    std::vector<std::pair<std::string, cv::Scalar>> legend_entries_;  // vector of entries
    int dist_b_entries_ = 1;                                          // distance between two entries and the borders
    int font_scale_ = 2;                                              // font scale of the legend entries
    int initial_rect_width_ = 10;                                     // width of the bounding box
};

auto main() -> int
{
    /**
     * The dataset for this evaluation was taken from
     * https://www.ncei.noaa.gov/metadata/geoportal/rest/metadata/item/gov.noaa.ncdc:C00947/html
     * The dataset for this documentation can be found at
     * https://www.ncei.noaa.gov/data/global-summary-of-the-year/doc/GSOM_GSOY_Description_Document_v1.0.2_20200219.pdf
     * The overview of all available weather stations is given in
     * https://www.ncei.noaa.gov/pub/data/ghcn/daily/ghcnd-stations.txt
     */

    /**
     * read in the csv document
     * ConverterParams need to take into account, because there are empty/invalid entries
     */
    rapidcsv::Document doc(std::string(RESOURCEPATH) + "/GME00102404.csv", rapidcsv::LabelParams(0, 0),
                           rapidcsv::SeparatorParams(), rapidcsv::ConverterParams(true));

    // read in the dates
    auto dates = doc.GetColumn<int>("DATE");
    // read in the average temperature of the year
    auto tavg = doc.GetColumn<float>("TAVG");
    // read in the max temperature of the year
    auto emxt = doc.GetColumn<float>("EMXT");
    // read in the min temperature of the year
    auto emnt = doc.GetColumn<float>("EMNT");

    // prepare axes object
    auto axes = CvPlot::makePlotAxes();
    // create a legend for the plot, position it an year 1940
    auto legend = LegendCustom(cv::Point2d(1940, 36));

    // plot the average temperature
    axes.create<CvPlot::Series>(dates, tavg, "-g");
    legend.add_legend_entry("avg temp", cv::Scalar(0, 255, 0));

    // plot the extreme max temperature
    axes.create<CvPlot::Series>(dates, emxt, "-b");
    legend.add_legend_entry("max temp", cv::Scalar(255, 0, 0));

    // plot the extreme max temperature
    axes.create<CvPlot::Series>(dates, emnt, "-r");
    legend.add_legend_entry("min temp", cv::Scalar(0, 0, 255));

    // add legend to axes
    legend.set_width(25);
    axes.create<LegendCustom>(&legend);

    // some settings for the plot
    axes.title("Weather analysis over years in Konstanz");
    axes.yLabel("Temperature in C");
    axes.xLabel("Year");

    // render the axes into a cv Mat
    cv::Mat mat = axes.render(600, 800);
    // write the plot to file
    cv::imwrite("weather_over_years_konstanz.png", mat);

    return 0;
}