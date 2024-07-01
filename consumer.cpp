#include "consumer.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <fstream>

void Consumer::consume()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(10));
        std::lock_guard<std::mutex> lock(this->sharedData_.mtx);
        std::ofstream file("data.txt", std::ios::app);
        for (int d : this->sharedData_.data)
        {
            file << d << "\n";
        }
        this->sharedData_.data.clear();
        std::cout << "Consumed data\n";
    }
}
