#pragma once

#ifndef SPDLOG_ACTIVE_LEVEL
#ifdef NDEBUG
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO
#else
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#endif
#endif

#include <spdlog/logger.h>

namespace logger {

void Init(const std::string& log_path, const std::string& log_name);
spdlog::logger& GetInstance();

}  // namespace logger

template <typename... Args>
inline void LogTrace(const char* fmt, const Args&... args) {
#if SPDLOG_ACTIVE_LEVEL <= SPDLOG_LEVEL_TRACE
    logger::GetInstance().trace(fmt, args...);
#endif
}

template <typename... Args>
inline void LogDebug(const char* fmt, const Args&... args) {
#if SPDLOG_ACTIVE_LEVEL <= SPDLOG_LEVEL_DEBUG
    logger::GetInstance().debug(fmt, args...);
#endif
}

template <typename... Args>
inline void LogInfo(const char* fmt, const Args&... args) {
#if SPDLOG_ACTIVE_LEVEL <= SPDLOG_LEVEL_INFO
    logger::GetInstance().info(fmt, args...);
#endif
}

template <typename... Args>
inline void LogWarn(const char* fmt, const Args&... args) {
#if SPDLOG_ACTIVE_LEVEL <= SPDLOG_LEVEL_WARN
    logger::GetInstance().warn(fmt, args...);
#endif
}

template <typename... Args>
inline void LogError(const char* fmt, const Args&... args) {
#if SPDLOG_ACTIVE_LEVEL <= SPDLOG_LEVEL_ERROR
    logger::GetInstance().error(fmt, args...);
#endif
}

template <typename... Args>
inline void LogCritical(const char* fmt, const Args&... args) {
#if SPDLOG_ACTIVE_LEVEL <= SPDLOG_LEVEL_CRITICAL
    logger::GetInstance().critical(fmt, args...);
#endif
}
