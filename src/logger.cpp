#include "logger.h"

#include <spdlog/async.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/spdlog.h>

namespace logger {

static std::string log_dir_path = "./log/";
static std::string log_file_name = "log.log";

void Init(const std::string& log_path, const std::string& log_name) {
    log_dir_path = log_path;
    log_file_name = log_name;
}

spdlog::logger& GetInstance() {
    static std::shared_ptr<spdlog::logger> instance = []() {
        const std::string log_path = log_dir_path + "/" + log_file_name;
        auto logger = spdlog::basic_logger_mt<spdlog::async_factory>("order_log", log_path);

        spdlog::flush_every(std::chrono::seconds(5));

        return logger;
    }();

    return *instance;
}

}  // namespace logger
