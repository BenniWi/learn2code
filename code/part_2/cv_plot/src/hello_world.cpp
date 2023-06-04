#define CVPLOT_HEADER_ONLY

#include <CvPlot/cvplot.h>

auto main() -> int
{
    auto axes = CvPlot::plot(std::vector<double>{3, 3, 4, 6, 4, 3}, "-o");
    axes.title("my first cvplot");
    axes.xLabel("x");
    axes.yLabel("y");
    cv::Mat mat = axes.render(300, 400);

    cv::imwrite("cvplot.png", mat);
    return 0;
}