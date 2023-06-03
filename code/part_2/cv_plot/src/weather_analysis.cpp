#define CVPLOT_HEADER_ONLY
#include <CvPlot/cvplot.h>
#include <rapidcsv.h>

#include <iostream>
#include <string>
#include <vector>

auto main() -> int
{
    // Dataset from: https://www.ncei.noaa.gov/metadata/geoportal/rest/metadata/item/gov.noaa.ncdc:C00947/html
    // Dataset documentation: https://www.ncei.noaa.gov/data/global-summary-of-the-year/doc/GSOM_GSOY_Description_Document_v1.0.2_20200219.pdf
    // available stations: https://www.ncei.noaa.gov/pub/data/ghcn/daily/ghcnd-stations.txt
    rapidcsv::Document doc(std::string(RESOURCEPATH) + "/GME00102404.csv", rapidcsv::LabelParams(0, 0),
                           rapidcsv::SeparatorParams(), rapidcsv::ConverterParams(true));

    auto dates = doc.GetColumn<int>("DATE");
    auto tavg = doc.GetColumn<float>("TAVG");
    auto emxt = doc.GetColumn<float>("EMXT");

    // prepare axes object
    auto axes = CvPlot::makePlotAxes();

    // plot the average temperature
   axes.create<CvPlot::Series>(dates, tavg, "-g");

    // plot the extreme max temperature
    axes.create<CvPlot::Series>(dates, emxt, "-b");

    // some settings for the plot
    axes.title("Weather analysis over years in Konstanz");
    axes.yLabel("temperature in degrees C");
    axes.xLabel("year");

    // write the plot to file
    cv::Mat mat = axes.render(600, 800);
    cv::imwrite("avg_temperatures_konstanz.jpg", mat);

    return 0;
}   