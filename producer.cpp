#include "producer.h"
#include <iostream>
#include <chrono>
#include <thread>

void Producer::produce()
{
    int i = 0;
    printf("the frequecy is %d", this->frequency);
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds((int)(1000 / this->frequency)));
        std::lock_guard<std::mutex> lock(this->sharedData_.mtx);
        this->sharedData_.data.push_back(i++); // 示例数据
        std::cout << "Produced data\n";
    }
}