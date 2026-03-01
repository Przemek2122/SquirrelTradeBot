// Created by Przemek2122 @ https://github.com/Przemek2122/SquirrelTradeBot

#include "Public/bot_lib.h"

#include <cpr/cpr.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <thread>
#include <chrono>

void Bot::Start()
{
    const std::string EndPointAddress = "https://api.binance.com/api/v3/ticker/price?symbol=BTCUSDT";

    try
    {
        cpr::Session session;
        session.SetUrl(cpr::Url{EndPointAddress});

        for (int i = 0; i < 20; i++)
        {
            std::chrono::time_point<std::chrono::steady_clock> RequestStartTime = std::chrono::steady_clock::now();
            cpr::Response r = session.Get();
            if (r.status_code == 200)
            {
                auto j = nlohmann::json::parse(r.text);
                std::cout << "BTC: " << j["price"] << std::endl;
            }
            else
            {
                std::cout << "Error: " << r.status_code << std::endl;
            }
            std::chrono::time_point<std::chrono::steady_clock> RequestEndTime = std::chrono::steady_clock::now();

            const long diff_ms = std::chrono::duration_cast<std::chrono::milliseconds>(RequestEndTime - RequestStartTime).count();
            std::cout << "Time of request: " << diff_ms << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(1000 - diff_ms));
        }
    }
    catch (std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
