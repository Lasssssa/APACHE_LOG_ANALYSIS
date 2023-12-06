#include "LogManager.h"
#include "Log.h"
#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    LogManager logManager;
    Stats stats;
    logManager.FillLog(stats);
    return 0;
}