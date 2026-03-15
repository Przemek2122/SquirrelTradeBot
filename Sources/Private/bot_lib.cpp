// Created by Przemek2122 @ https://github.com/Przemek2122/SquirrelTradeBot

#include "Public/bot_lib.h"
#include "Public/CryptoCurrency.h"

void Bot::Start()
{
    CryptoCurrency currency1("https://api.binance.com/api/v3/ticker/price?symbol=", "BTCUSDT");
}
