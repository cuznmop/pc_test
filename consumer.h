#pragma once

#include <vector>
#include <mutex>
#include "shareddata.h"

class Consumer
{
public:
    Consumer(SharedData &sharedData) : sharedData_(sharedData) {}
    void consume();

private:
    SharedData &sharedData_;
};