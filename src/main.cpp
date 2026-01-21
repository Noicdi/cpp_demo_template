#include "logger.h"
#include "utils.h"

int main() {
    logger::Init("./logs", "logs.log");

    LogInfo("Hello, world!");

    return 0;
}
