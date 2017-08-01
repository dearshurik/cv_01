//
// Created by kuznetsov on 22.06.17.
//

#ifndef CV_01_VIDEOENGINE_H
#define CV_01_VIDEOENGINE_H

class VideoEngine
{
public:
    VideoEngine();
    virtual ~VideoEngine();

    virtual bool register_plugin() noexcept;




};

#endif //CV_01_VIDEOENGINE_H
