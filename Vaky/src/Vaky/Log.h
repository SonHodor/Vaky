#pragma once

#include <memory>

#include "Core.h"
#include "spdlog\spdlog.h"

namespace Vaky {

	class VAKY_API Log
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

// Core log macros
#define VK_CORE_TRACE(...)    ::Vaky::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VK_CORE_INFO(...)     ::Vaky::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VK_CORE_WARN(...)     ::Vaky::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VK_CORE_ERROR(...)    ::Vaky::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VK_CORE_FATAL(...)    ::Vaky::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define VK_TRACE(...)         ::Vaky::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VK_INFO(...)          ::Vaky::Log::GetClientLogger()->info(__VA_ARGS__)
#define VK_WARN(...)          ::Vaky::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VK_ERROR(...)         ::Vaky::Log::GetClientLogger()->error(__VA_ARGS__)
#define VK_FATAL(...)         ::Vaky::Log::GetClientLogger()->fatal(__VA_ARGS__)