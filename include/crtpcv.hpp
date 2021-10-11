#ifndef _CRTP_H_
#define _CRTP_H_
#include <tuple>
#include <utility>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <type_traits>

template<typename D>
struct ImgOps
{
//    template<cv::Mat img, cv::Mat imgk>
    void Run(cv::Mat img, cv::Mat imgk)
    {
        D* ptr = static_cast<D*>(this);
        ptr->Imp(img, imgk);
    }
};

struct ImgOpsGray : public ImgOps<ImgOpsGray>
{
//    template<typename TI>
    void Imp(cv::Mat img, cv::Mat imgk)
    {
        cv::namedWindow("ImgOpsGray", cv::WINDOW_AUTOSIZE);
        cv::cvtColor(img, imgk, cv::COLOR_BGR2GRAY);
        cv::imshow("ImgOpsGray", imgk);
        cv::waitKey(0);
    }

};


struct ImgOpsCanny : public ImgOps<ImgOpsCanny>
{
//    template<typename TI>
    void Imp(cv::Mat img, cv::Mat imgk)
    {
        cv::namedWindow("ImgOpsCanny", cv::WINDOW_AUTOSIZE);
        cv::Canny(img, imgk, 10, 100, 3, true);
        cv::imshow("ImgOpsCanny", imgk);
        cv::waitKey(0);
    }
};

struct ImgOpsBlur : public ImgOps<ImgOpsBlur>
{
//    template<typename TI>
    void Imp(cv::Mat img, cv::Mat imgk)
    {
        cv::namedWindow("ImgOpsBlur", cv::WINDOW_AUTOSIZE);
        cv::GaussianBlur(img, imgk, cv::Size(5,5), 3,3);
        cv::imshow("ImgOpsBlur", imgk);
        cv::waitKey(0);
    }
};
#endif
