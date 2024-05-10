// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

#define DLL_EXPORT __declspec(dllexport)

// add headers that you want to pre-compile here
#include "framework.h"

#include <cstdio>

#include <random>

#include "Types.h"

#include "VaText.h"

#include "Logger.h"

using namespace Utility;

#ifdef EOS_VER
#define EOS_BUILD_DLL 1

#include "eos_init.h"
#include "eos_types.h"
#include "eos_connect.h"
#include "eos_anticheatclient_types.h"
#include "eos_logging.h"

extern "C" DLL_EXPORT EOS_HAntiCheatClient EOS_Platform_GetAntiCheatClientInterface( EOS_HPlatform Handle );
#else
extern "C" DLL_EXPORT PVOID CreateGameClient( const char* interfaceName );

extern "C" DLL_EXPORT PVOID CreateClientAuth(const char* interfaceName);
#endif

#endif //PCH_H
