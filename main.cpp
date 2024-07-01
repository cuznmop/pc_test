#include <iostream>
#include <thread>
#include "producer.h"
#include "consumer.h"
#include "shareddata.h"

SharedData sd;

int main()
{
    Producer prod(10, sd); // 假设频率为10
    Consumer cons(sd);

    std::thread producerThread(&Producer::produce, &prod);
    std::thread consumerThread(&Consumer::consume, &cons);

    producerThread.join();
    consumerThread.join();

    return 0;
}