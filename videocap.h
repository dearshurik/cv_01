//
// Created by kuznetsov on 21.06.17.
//

#ifndef CV_01_VIDEOCAP_H
#define CV_01_VIDEOCAP_H


template <class T>
class VideoCap {
public:
    VideoCap()
    {
        m_cap.open(cv::CAP_ANY);
    }

    ~VideoCap() {}

    void operator() (threadsafe_queue<T> &free_buf, threadsafe_queue<T> &full_buf)
    {
        while(1) {
            auto ptr = free_buf.pop();
            if (ptr) {
                m_cap.read(*ptr);
                full_buf.push(ptr);
            }
        }
    }

private:
    cv::VideoCapture    m_cap;
};

#endif //CV_01_VIDEOCAP_H
