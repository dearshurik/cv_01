#include <opencv2/opencv.hpp>
#include <memory>
#include <thread>
#include <mutex>
#include <iostream>

#include "threadsafe_queue.h"
#include "videocap.h"
#include "videorender.h"


int main(int, char**)
{
    threadsafe_queue<std::shared_ptr<cv::Mat>> free_buf, full_buf;
    VideoCap<std::shared_ptr<cv::Mat>> vc;
    VideoRender<std::shared_ptr<cv::Mat>> vr;

    for(auto i = 0; i < 3; i++)
        free_buf.push(std::make_shared<cv::Mat>());


    std::thread vc_(vc, std::ref(free_buf), std::ref(full_buf));
    std::thread vr_(vr, std::ref(free_buf), std::ref(full_buf));


    while(1) {
        //cv::waitKey(1);
    }



    return 0;
}