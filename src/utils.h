#ifndef UTILS_H
#define UTILS_H
#include <QString>
#include <vector>
#include "image.h"
#include "opencv2/opencv.hpp"

void calculate_intensity_histogram(Image& source);
void show_histogram(std::vector<double> histogram);
void object_tracking(std::vector<Image> images, int number_of_frames, cv::Rect roi, cv::Mat roi_histogram, int search_window_area, int search_window_speed);
double dot_product(const std::vector<double>& v1, const std::vector<double>& v2);
double norm(const std::vector<double>& v);
double cosine_similarity(const std::vector<double>& vec1, const std::vector<double>& vec2);
double intersection(const std::vector<double>& hist1, const std::vector<double>& hist2);
double euclidean_distance(const std::vector<double>& vec1, const std::vector<double>& vec2);
double mean(const std::vector<double>& vec);
double correlation(const std::vector<double>& vec1, const std::vector<double>& vec2);
#endif // UTILS_H
