#ifndef IMAGE_H
#include "opencv2/opencv.hpp"


class Image
{
public:
    cv::Mat mat;
    std::vector<double> histogram;
};

#endif // IMAGE_H

