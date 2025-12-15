#include "Logger.h"

int main() {
    logger::Init("./logs", "logs.log");

    LogInfo("Hello, world!");

    return 0;
}
