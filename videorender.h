//
// Created by kuznetsov on 28.06.17.
//

#ifndef CV_01_VIDEORENDER_H
#define CV_01_VIDEORENDER_H

template <class T>
class VideoRender {
public:
    VideoRender()  {}
    ~VideoRender() {}

    void operator() (threadsafe_queue<T> &free_buf, threadsafe_queue<T> &full_buf)
    {
        while(1) {
            auto frame = full_buf.pop();
            if (frame) {
                cv::imshow("Live", *frame);
                free_buf.push(frame);
                cv::waitKey(1);
            }
        }
    }
};


#endif //CV_01_VIDEORENDER_H
