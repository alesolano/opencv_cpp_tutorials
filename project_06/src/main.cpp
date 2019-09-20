#include <iostream>
#include <opencv2/imgproc.hpp>

int main()
{
    cv::Mat m_src, m_dst;

    // Random numbers
    //m_src = cv::Mat::zeros(10, 10, CV_8UC1);
    //cv::randu(m_src, 0, 255);
    //std::cout << "\nM:\n" << m_src << std::endl;

    // Sequential numbers
    m_src = cv::Mat::zeros(10, 10, CV_8UC1);
    for (uchar i=0; i<m_src.total(); ++i)
        m_src.at<uchar>(i) = i;
    std::cout << "\nM:\n" << m_src << std::endl;

    cv::resize(m_src, m_dst, cv::Size(5, 5), 0, 0, cv::INTER_LINEAR);
    std::cout << "\nM (LINEAR):\n" << m_dst << std::endl;

    cv::resize(m_src, m_dst, cv::Size(5, 5), 0, 0, cv::INTER_NEAREST);
    std::cout << "\nM (NEAREST):\n" << m_dst << std::endl;

    cv::resize(m_src, m_dst, cv::Size(5, 5), 0, 0, cv::INTER_AREA);
    std::cout << "\nM (AREA):\n" << m_dst << std::endl;

    cv::resize(m_src, m_dst, cv::Size(5, 5), 0, 0, cv::INTER_CUBIC);
    std::cout << "\nM (CUBIC):\n" << m_dst << std::endl;

    std::cout << "\n################" << std::endl;
    std::cout << "\nM:\n" << m_src << std::endl;

    // I don't know what the exact formula is.
    // It's a Gaussian filter of ? size
    // A Gaussian kernel follows a 2D normal distribution
    // But what's the sigma?
    // Example:
    //   [[1, 4, 1],
    // (  [4, 6, 4],  * imgpath ) / 16
    //    [1, 4, 1]]
    cv::pyrDown(m_src, m_dst, cv::Size(5, 5));
    std::cout << "\nM (PyrDown):\n" << m_dst << std::endl;

    // Building 4 pyramids out of m_src
    // Hey: pyramid 4 is the average of pyramid 3!
    std::vector<cv::Mat> m_pyrs;
    cv::buildPyramid(m_src, m_pyrs, 4);
    for (auto& pyr: m_pyrs)
        std::cout << "\n?:\n" << pyr << std::endl;



    return 0;
}

