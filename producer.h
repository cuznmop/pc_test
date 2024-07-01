#pragma once

#include <vector>
#include <mutex>
#include "shareddata.h"

class Producer
{
public:
    Producer(int freq, SharedData &sharedData) : frequency(freq), sharedData_(sharedData) {}
    void produce();

private:
    int frequency;
    SharedData &sharedData_;
};
