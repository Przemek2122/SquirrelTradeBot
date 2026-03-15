// Created by Przemek2122 @ https://github.com/Przemek2122/SquirrelTradeBot

#include <utility>

#include "Public/CryptoCurrency.h"
#include <nlohmann/json.hpp>
#include "cpr/response.h"
#include "cpr/session.h"

CryptoCurrency::CryptoCurrency(const std::string& InURL, const std::string& InSymbol)
    : UrlWithSymbol(InURL + InSymbol)
    , worker(std::jthread(&CryptoCurrency::StartThreaded, this))
{
}

void CryptoCurrency::StartThreaded(const std::stop_token& st)
{
    //while (!st.stop_requested())
    {
        try
        {
            cpr::Session session;
            session.SetUrl(cpr::Url{UrlWithSymbol});

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
}
