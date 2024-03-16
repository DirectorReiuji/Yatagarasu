#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Yatagarasu {
	class YATAGARASU_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}


// Macros for core logging
#define YG_CORE_TRACE(...)	::Yatagarasu::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define YG_CORE_INFO(...)	::Yatagarasu::Log::GetCoreLogger()->info(__VA_ARGS__)
#define YG_CORE_WARN(...)	::Yatagarasu::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define YG_CORE_ERROR(...)	::Yatagarasu::Log::GetCoreLogger()->error(__VA_ARGS__)
#define YG_CORE_FATAL(...)	::Yatagarasu::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Macros for client logging
#define YG_TRACE(...)		::Yatagarasu::Log::GetClientLogger()->trace(__VA_ARGS__)
#define YG_INFO(...)		::Yatagarasu::Log::GetClientLogger()->info(__VA_ARGS__)
#define YG_WARN(...)		::Yatagarasu::Log::GetClientLogger()->warn(__VA_ARGS__)
#define YG_ERROR(...)		::Yatagarasu::Log::GetClientLogger()->error(__VA_ARGS__)
#define YG_FATAL(...)		::Yatagarasu::Log::GetClientLogger()->fatal(__VA_ARGS__)