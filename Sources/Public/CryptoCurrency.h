// Created by Przemek2122 @ https://github.com/Przemek2122/SquirrelTradeBot

#pragma once

#include <thread>
#include <iostream>
#include <string>

/** Base class for each crypto-cryptocurrency */
class CryptoCurrency
{
public:
    CryptoCurrency(const std::string& InURL, const std::string& InSymbol);

    /** Work done on other thread than original */
    void StartThreaded(const std::stop_token& st);

private:
    std::string UrlWithSymbol;

    /** Thread - should be last as other data should be initialized first */
    std::jthread worker;
};
