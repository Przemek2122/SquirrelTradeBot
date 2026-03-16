// Created by Przemek2122 @ https://github.com/Przemek2122/SquirrelTradeBot

#include "Public/bot_lib.h"

#include "ThreadUtils.h"
#include "Public/CryptoCurrency.h"

void Bot::Start()
{
    // 4 cores are required as minimal count
    if (ThreadUtils::GetCoresCount() < 4)
    {
        std::cerr << "Launch aborted." << std::endl;
        std::cerr << "We need at least 4 cores." << std::endl;

        return;
    }

    CryptoCurrency currency1("https://api.binance.com/api/v3/ticker/price?symbol=", "BTCUSDT");
}
