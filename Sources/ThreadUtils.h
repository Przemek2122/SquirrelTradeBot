// Created by Przemek2122 @ https://github.com/Przemek2122/SquirrelTradeBot

#pragma once

class ThreadUtils
{
public:
    static void PinToCore(int CoreId);
    static int GetCoresCount();
};
