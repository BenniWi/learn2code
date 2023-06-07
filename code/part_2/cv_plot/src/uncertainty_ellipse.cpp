#define CVPLOT_HEADER_ONLY
#include <CvPlot/cvplot.h>
#include <rapidcsv.h>

#include <armadillo>
#include <iostream>

// #define CREATE_CSV

#ifdef CREATE_CSV
#include <fstream>
#endif

/**
 * @brief create a custom drawable to be able to add an uncertainty ellipse
 */
class RotatedEllipse : public CvPlot::Drawable
{
   public:
    /**
     * @brief override the render method from "drawable" -> this method is called when drawing the drawable into the
     * image
     */
    void render(CvPlot::RenderTarget &render_target) override
    {
        // for opencv rotated rectangle we need 3 consecutive points of the rectangle
        arma::mat pt1 = means_.t() + (0.5 * eigvals_(0) * eigvecs_.col(0)) + (0.5 * eigvals_(1) * eigvecs_.col(1));
        arma::mat pt2 = means_.t() - (0.5 * eigvals_(0) * eigvecs_.col(0)) + (0.5 * eigvals_(1) * eigvecs_.col(1));
        arma::mat pt3 = means_.t() - (0.5 * eigvals_(0) * eigvecs_.col(0)) - (0.5 * eigvals_(1) * eigvecs_.col(1));

        // project all points into the image coordinates
        auto pro_pt1 = render_target.project(cv::Point2d(pt1(0), pt1(1)));
        auto pro_pt2 = render_target.project(cv::Point2d(pt2(0), pt2(1)));
        auto pro_pt3 = render_target.project(cv::Point2d(pt3(0), pt3(1)));

        // create a rotated rectangle
        auto rot_rect = cv::RotatedRect(pro_pt1, pro_pt2, pro_pt3);
        // render the rectangle to the image
        cv::ellipse(render_target.innerMat(), rot_rect, cv::Scalar(0, 0, 0), 1);
    }

    /**
     * @brief Standard constructor
     * @param means center of the ellipse
     * @param eigvals eigenvalues of the covariance matrix
     * @param eigvecs eigenvectors of the covariance matrix
     */
    explicit RotatedEllipse(const arma::mat &means, const arma::vec &eigvals, const arma::mat &eigvecs)
        : means_(means), eigvals_(eigvals), eigvecs_(eigvecs)
    {
    }

   private:
    arma::mat means_;
    arma::vec eigvals_;
    arma::mat eigvecs_;
};

auto main() -> int
{
#ifndef CREATE_CSV
    // read in the values from the file
    rapidcsv::Document doc(std::string(RESOURCEPATH) + "/uncertain_point.csv", rapidcsv::LabelParams(0, -1));
    auto x_values = doc.GetColumn<double>("x values");
    auto y_values = doc.GetColumn<double>("y values");

    // create vectors by reusing the auxiliary memory
    auto x_vec = arma::vec(static_cast<double *>(&x_values[0]), static_cast<int>(x_values.size()), false);
    auto y_vec = arma::vec(static_cast<double *>(&y_values[0]), static_cast<int>(y_values.size()), false);

    // create covariance matrix
    arma::mat points_mat = arma::join_rows(x_vec, y_vec);
    arma::mat cov_mat = arma::cov(points_mat);
    arma::mat means = arma::mean(points_mat);

    // get eigenvalues and eigenvectors
    arma::vec eigvals;
    arma::mat eigvecs;
    arma::eig_sym(eigvals, eigvecs, cov_mat);

    // calc vectors to plot
    // eigenvalues are the length of the main axis
    arma::mat veca1 = means.t() + (0.5 * eigvals(0) * eigvecs.col(0));
    arma::mat veca2 = means.t() - (0.5 * eigvals(0) * eigvecs.col(0));
    arma::mat vecb1 = means.t() + (0.5 * eigvals(1) * eigvecs.col(1));
    arma::mat vecb2 = means.t() - (0.5 * eigvals(1) * eigvecs.col(1));

    // create the plot for the values
    auto axes = CvPlot::plot(x_values, y_values, "r.");
    axes.create<CvPlot::Series>(std::vector<double>{veca1(0), veca2(0)}, std::vector<double>{veca1(1), veca2(1)}, "-g");
    axes.create<CvPlot::Series>(std::vector<double>{vecb1(0), vecb2(0)}, std::vector<double>{vecb1(1), vecb2(1)}, "-b");
    axes.create<RotatedEllipse>(means, eigvals, eigvecs);

    // set some settings to the axes
    axes.title("uncertain point with ellipse");
    axes.xLabel("x");
    axes.yLabel("y");
    axes.setFixedAspectRatio();

    // render the image
    cv::Mat mat = axes.render(600, 800);
    // write image to file
    cv::imwrite("uncertainty_ellipse.png", mat);

#else
    // define two arrays
    std::array<double, 1000> x_values;
    std::array<double, 1000> y_values;
    // create arma vectors with the auxiliary memory from the arrays
    auto x_vec = arma::vec(x_values.data(), x_values.size(), false);
    auto y_vec = arma::vec(y_values.data(), y_values.size(), false);
    // create random distributions.
    x_vec = arma::randn(x_vec.n_elem, 1, arma::distr_param(0.0, 2.0));
    y_vec = arma::randn(y_vec.n_elem, 1, arma::distr_param(0.0, 5.0));
    // create matrix to rotate them
    arma::mat point_mat = arma::join_cols(x_vec.t(), y_vec.t());
    // rotation matrix and rotate the points
    double phi = 30.0 * M_PI / 180.0;
    arma::mat rot = {{cos(phi), -sin(phi)}, {sin(phi), cos(phi)}};
    point_mat = rot * point_mat;
    // translate the points
    point_mat.row(0) = point_mat.row(0) + 5.0;
    point_mat.row(1) = point_mat.row(1) + 7.0;

    // write the element to csv
    // also copy elements to array for the use with cvplot
    std::fstream strm;
    strm.open("uncertain_point.csv", std::ios_base::out);
    strm << "x values,y values" << std::endl;
    for (size_t i = 0; i < point_mat.n_cols; ++i)
    {
        x_values[i] = point_mat(0, i);
        y_values[i] = point_mat(1, i);
        strm << x_values[i] << "," << y_values[i] << std::endl;
    }
    strm.close();

    // print the points to diagram
    auto axes = CvPlot::plot(x_values, y_values, "b.");
    axes.setFixedAspectRatio();
    cv::Mat mat = axes.render(300, 400);
    cv::imwrite("uncertainty_ellipse_points.png", mat);

#endif

    return 0;
}