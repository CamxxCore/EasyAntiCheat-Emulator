// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#ifdef EOS_VER

EOS_HPlatform g_hPlatform;

EOS_HAntiCheatClient g_hAnticheatClient;

EOS_DECLARE_FUNC( EOS_EResult ) EOS_Initialize( const EOS_InitializeOptions * Options ) {

    LOG( "Initializing EOS - Product Name: %s Version: %s", Options->ProductName, Options->ProductVersion );

    return EOS_EResult::EOS_Success;
}

EOS_DECLARE_FUNC( EOS_EResult ) EOS_Logging_SetCallback( EOS_LogMessageFunc Callback ) {

    LOG( "Setting Log Callback..." );

    return EOS_EResult::EOS_Success;
}

EOS_DECLARE_FUNC( EOS_EResult ) EOS_Logging_SetLogLevel( EOS_ELogCategory LogCategory, int32_t LogLevel )
{
    LOG( "Setting Log Level: %i", LogLevel );

    return EOS_EResult::EOS_Success;
}

EOS_DECLARE_FUNC( EOS_EResult ) EOS_Shutdown()
{
    LOG( "Shutting down EOS..." );

    return EOS_EResult::EOS_Success;
}

EOS_DECLARE_FUNC( EOS_HPlatform ) EOS_Platform_Create( const EOS_Platform_Options * Options ) {

    LOG( "Creating EOS Platform..." );

    return g_hPlatform;
}

EOS_DECLARE_FUNC( EOS_HAntiCheatClient ) EOS_Platform_GetAntiCheatClientInterface( EOS_HPlatform Handle ) {

    LOG( "Returning faux EOS game client interface" );

    return g_hAnticheatClient;
}

#else

IGameClientBase g_client;

IClientAuth g_client_auth;

extern "C" PVOID CreateGameClient( const char* interfaceName ) {

    LOG( "Returning faux game client interface" );

    return &g_client;
}

extern "C" PVOID CreateClientAuth(const char* interfaceName) {

    LOG("Returning faux game client auth interface");

    return &g_client_auth;
}
#endif

BOOL APIENTRY DllMain( HMODULE hModule,
    DWORD  ul_reason_for_call,
    LPVOID lpReserved
) {
    switch ( ul_reason_for_call ) {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

