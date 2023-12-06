#include "LogManager.h"
#include "Log.h"
#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    Stats stats;
    LogManager logManager(argv[1]);
    logManager.FillLog(stats);
    return 0;
}