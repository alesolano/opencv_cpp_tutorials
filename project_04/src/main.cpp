#include "opencv2/highgui/highgui.hpp"
#include <iostream>

// Types: https://github.com/opencv/opencv/blob/master/modules/core/include/opencv2/core/types.hpp
// ostream operator for types: // https://github.com/opencv/opencv/blob/master/modules/core/include/opencv2/core/cvstd.inl.hpp
// format: https://github.com/opencv/opencv/blob/master/modules/core/src/out.cpp

int main( int argc, char** argv )
{
    cv::Mat m0;
    if ( m0.empty() ) std::cout << "m0 is empty\n";

    // static MatExpr eye(int rows, int cols, int type);
    // All Mat types macros: https://docs.opencv.org/4.1.1/d1/d1b/group__core__hal__interface.html
    m0 = cv::Mat::eye(5, 5, CV_8U);
    std::cout << "m0:\n" << m0 << std::endl;

    // template<typename _Tp> const _Tp& at(int row, int col) const;
    std::cout << "m0[0, 0]: " << static_cast<int>(m0.at<uchar>(0, 0)) << std::endl;
    std::cout << "m0[0, 1]: " << static_cast<int>(m0.at<uchar>(0, 1)) << std::endl;

    // template<typename _Tp> _Tp& at(int row, int col);
    m0.at<uchar>(0, 0) = 5;
    std::cout << "m0:\n" << m0 << std::endl;

    // template<typename _Tp> const _Tp& at(int i0=0) const;
    std::cout << "m0[1, 1]: " << static_cast<int>(m0.at<uchar>(6)) << std::endl;
    //int row = 1, col = 1;
    //std::cout << "m0[1, 1]: " << static_cast<int>(m0.at<uchar>(row*m0.size().width + col)) << std::endl;

    // void pop_back(size_t nelems=1);
    m0.pop_back(1);
    std::cout << "New size: " << m0.size() << std::endl;
    std::cout << "m0:\n" << m0 << std::endl;


    return 0;
}
