#include <cpr/cpr.h>
#include <iostream>
#include <nlohmann/json.hpp>

int main()
{
    cpr::Response r = cpr::Get(cpr::Url{"https://api.binance.com/api/v3/ticker/price?symbol=BTCUSDT"});
    if (r.status_code == 200)
    {
        auto j = nlohmann::json::parse(r.text);
        std::cout << "BTC: " << j["price"] << std::endl;
    }
    else
    {
        std::cout << "Error: " << r.status_code << std::endl;
    }

    return 0;
}