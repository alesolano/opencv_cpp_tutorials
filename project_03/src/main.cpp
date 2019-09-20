#include "opencv2/highgui/highgui.hpp"
#include <iostream>

// Not necessary: included in "opencv2/highgui/highgui.hpp"
//#include <string>
//#include <vector>

/**
SLICING
Exploring the () operator:
https://github.com/opencv/opencv/blob/master/modules/core/include/opencv2/core/mat.hpp#L1614-L1640
**/

void show_image(cv::InputArray img, const std::string& window_name)
{
  cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
  cv::imshow(window_name, img);

  cv::waitKey(0);
  cv::destroyWindow(window_name);
}

int main( int argc, char** argv )
{
    cv::Mat img = cv::imread(argv[1],-1);
    if( img.empty() ) return -1;

    cv::Size img_size = img.size(); // Size int32
    int img_h = img_size.height;
    int img_w = img_size.width;
    std::cout << "\nHeight: " << img_h << "\nWidth: " << img_w << std::endl;

    // Mat operator()( Range rowRange, Range colRange ) const;
    cv::Mat subimg_0 = img(cv::Range(0, img_h/2), cv::Range(0, img_w/2));
    show_image(subimg_0, "W0");

    // Mat operator()( const Rect& roi ) const;
    // Rect_ (_Tp _x, _Tp _y, _Tp _width, _Tp _height);
    cv::Mat subimg_1 = img(cv::Rect(0, 0, img_h/2, img_w/2));
    show_image(subimg_1, "W1");

    // Mat operator()( const Range* ranges ) const;
    cv::Range ranges[2] = {cv::Range(0, img_h/2), cv::Range(0, img_w/2)};
    cv::Mat subimg_2 = img(ranges);
    show_image(subimg_2, "W2");

    // Mat operator()(const std::vector<Range>& ranges) const;
    std::vector<cv::Range> v_ranges = {cv::Range(0, img_h/2), cv::Range(0, img_w/2)};
    cv::Mat subimg_3 = img(v_ranges);
    show_image(subimg_3, "W3");

    return 0;
}
