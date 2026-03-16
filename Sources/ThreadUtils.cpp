// Created by Przemek2122 @ https://github.com/Przemek2122/SquirrelTradeBot

#include "ThreadUtils.h"
#include <thread>
#include <pthread.h>
#include <iostream>

void ThreadUtils::PinToCore(const int CoreId)
{
    cpu_set_t CPUSet;
    CPU_ZERO(&CPUSet);
    CPU_SET(CoreId, &CPUSet);

    pthread_t CurrentThread = pthread_self();
    int Result = pthread_setaffinity_np(CurrentThread, sizeof(cpu_set_t), &CPUSet);

    if (Result != 0) {
        std::cerr << "PinToCore error: " << CoreId << "\n";
    } else {
        std::clog << "PinToCore thread pinned: " << CoreId << "\n";
    }
}

int ThreadUtils::GetCoresCount()
{
    return static_cast<int>(std::thread::hardware_concurrency());
}
