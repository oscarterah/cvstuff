#include "include/crtpcv.hpp"

int main(int argc, char** argv)
{
    std::string path = std::string(argv[1]);
    cv::Mat img = cv::imread(path);
    cv::Mat imgk {};
    ImgOps<ImgOpsGray>* GrayImg = new ImgOpsGray();
    ImgOps<ImgOpsCanny>* CannyImg = new ImgOpsCanny();
    ImgOps<ImgOpsBlur>* BlurImg = new ImgOpsBlur();
    typedef std::tuple<ImgOps<ImgOpsGray>*, ImgOps<ImgOpsCanny>*, ImgOps<ImgOpsBlur>*> ptr;
    ptr arr = std::make_tuple(GrayImg, CannyImg, BlurImg);

    std::apply([=](auto&&... args) {((args->Run(img, imgk)), ...);}, arr);

}
