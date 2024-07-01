#pragma once
#include <vector>  
#include <mutex>  
  
class SharedData {  
public:  
    std::vector<int> data;  
    std::mutex mtx;  
}; 