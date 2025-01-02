#define CVPLOT_HEADER_ONLY   // necessary to use CvPlot as a pure template library
#pragma GCC diagnostic push  // disable gcc warnings for cvplot
#pragma GCC diagnostic ignored "-Wcatch-value"
#include <CvPlot/cvplot.h>
#pragma GCC diagnostic pop

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