// Created by Przemek2122 @ https://github.com/Przemek2122/SquirrelTradeBot

#pragma once
#include <memory>
#include "CryptoCurrencyManager.h"

/**
 * Bot entry point,
 * Moved outside main for easy test case access
 */
class Bot
{
public:
    void Start();

private:
    std::unique_ptr<CryptoCurrencyManager> CryptoCurrencyManagerPtr;

};
