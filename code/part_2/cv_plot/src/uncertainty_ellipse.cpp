#define CVPLOT_HEADER_ONLY
#include <CvPlot/cvplot.h>
#include <rapidcsv.h>

#include <armadillo>
#include <iostream>
#include <fstream>

auto main() -> int
{
    // define two arrays
    std::array<double, 1000> x_values;
    std::array<double, 1000> y_values;
    // create arma vectors with the auxiliary memory from the arrays
    auto x_vec = arma::vec(x_values.data(), x_values.size(), false);
    auto y_vec = arma::vec(y_values.data(), y_values.size(), false);
    // create random distributions.
    x_vec = arma::randn(x_vec.n_elem, 1, arma::distr_param( 5.0, 1.5));
    y_vec = arma::randn(y_vec.n_elem, 1, arma::distr_param( 7.0, 3.5));
    // write the element to csv
    fstream strm;
    strm.open("uncertain_point.csv", ios_base::out);
    strm << "x values, y values";
    for(int i = 0; i < x_values.size(); ++i)
    {
        strm << x_values[i] << "," << y_values[i];
    }
    strm.close()

    auto axes = CvPlot::plot(x_values, y_values, "go");
    axes.title("uncertain point with ellipse");
    axes.xLabel("x");
    axes.yLabel("y");
    //axes.setXLim();
    cv::Mat mat = axes.render(300, 400);

    cv::imwrite("uncertainty_ellipse.png", mat);



    return 0;
}