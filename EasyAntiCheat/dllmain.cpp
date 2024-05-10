// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#ifdef EOS_VER

EOS_HPlatform g_hPlatform;

EOS_HConnect g_hConnect;

EOS_HAntiCheatClient g_hAnticheatClient;

EOS_DECLARE_FUNC( EOS_EResult ) EOS_Initialize( const EOS_InitializeOptions * Options ) {

    LOG( __FUNCTION__ ": Initializing EOS - Product Name: %s Version: %s", Options->ProductName, Options->ProductVersion );

    return EOS_EResult::EOS_Success;
}

EOS_DECLARE_FUNC( EOS_EResult ) EOS_Logging_SetCallback( EOS_LogMessageFunc Callback ) {

    LOG( __FUNCTION__ ": Setting Log Callback..." );

    return EOS_EResult::EOS_Success;
}

EOS_DECLARE_FUNC( EOS_EResult ) EOS_Logging_SetLogLevel( EOS_ELogCategory LogCategory, int32_t LogLevel )
{
    LOG( __FUNCTION__ ": Setting Log Level: %i", LogLevel );

    return EOS_EResult::EOS_Success;
}

EOS_DECLARE_FUNC( EOS_HPlatform ) EOS_Platform_Create( const EOS_Platform_Options * Options ) {

    LOG( __FUNCTION__ ": Creating EOS Platform..." );

    return g_hPlatform;
}

EOS_DECLARE_FUNC( void ) EOS_Platform_Tick( EOS_HPlatform Handle ) {

    // doing work... (not really)
}

EOS_DECLARE_FUNC( EOS_HConnect ) EOS_Platform_GetConnectInterface( EOS_HPlatform Handle ) {

    LOG( __FUNCTION__ ": Creating faux EOS Connect Handle..." );

    return g_hConnect;
}

EOS_DECLARE_FUNC( void ) EOS_Connect_Login( EOS_HConnect Handle, const EOS_Connect_LoginOptions* Options, void* ClientData, const EOS_Connect_OnLoginCallback CompletionDelegate ) {

    if ( CompletionDelegate ) {

        LOG( __FUNCTION__ ": Calling CompletionDelegate with faux completion data..." );

        EOS_Connect_LoginCallbackInfo info{};
        info.ClientData = ClientData;
        info.LocalUserId = EOS_ProductUserId{};
        info.ResultCode = EOS_EResult::EOS_Success;

        CompletionDelegate( &info );
    }
}

EOS_DECLARE_FUNC( void ) EOS_Connect_CreateUser( EOS_HConnect Handle, const EOS_Connect_CreateUserOptions* Options, void* ClientData, const EOS_Connect_OnCreateUserCallback CompletionDelegate ) {

    if ( CompletionDelegate ) {

        LOG( __FUNCTION__ ": Calling CompletionDelegate with faux completion data..." );

        EOS_Connect_CreateUserCallbackInfo info{};
        info.ClientData = ClientData;
        info.LocalUserId = EOS_ProductUserId{};
        info.ResultCode = EOS_EResult::EOS_Success;

        CompletionDelegate( &info );
    }
}

EOS_DECLARE_FUNC( EOS_NotificationId ) EOS_Connect_AddNotifyAuthExpiration( EOS_HConnect Handle, const EOS_Connect_AddNotifyAuthExpirationOptions* Options, void* ClientData, const EOS_Connect_OnAuthExpirationCallback Notification ) {

    if ( Notification ) {
        LOG( __FUNCTION__ ": Calling Notification with faux notification data..." );

        EOS_Connect_AuthExpirationCallbackInfo info = { 0 };
        info.ClientData = ClientData;
        info.LocalUserId = EOS_ProductUserId{};
        Notification( &info );
    }

    LOG( __FUNCTION__ ": Returning faux EOS_NotificationId..." );

    std::random_device dev;
    std::mt19937 rng( dev() );
    std::uniform_int_distribution<std::mt19937::result_type> dist6( 1, 199 );

    return static_cast<EOS_NotificationId>( dist6( rng ) );
}

EOS_DECLARE_FUNC( EOS_EResult ) EOS_Connect_CopyIdToken( EOS_HConnect Handle, const EOS_Connect_CopyIdTokenOptions* Options, EOS_Connect_IdToken** OutIdToken ) {

    return EOS_EResult::EOS_Connect_InvalidToken;
}

EOS_DECLARE_FUNC( void ) EOS_Connect_IdToken_Release( EOS_Connect_IdToken* IdToken ) {

}

EOS_DECLARE_FUNC( EOS_EResult ) EOS_ProductUserId_ToString( EOS_ProductUserId AccountId, char* OutBuffer, int32_t* InOutBufferLength ) {

    if ( !AccountId ) {

        LOG( __FUNCTION__ ": Invalid AccountId parameter..." );

        return EOS_EResult::EOS_InvalidParameters;
    }

    LOG( __FUNCTION__ ": Returning stringified EOS_ProductUserId..." );

    uint64_t accountIdData = *(uint64_t*)AccountId;

    char buf[EOS_PRODUCTUSERID_MAX_LENGTH * sizeof( char )]{};

    sprintf_s(OutBuffer, *InOutBufferLength, "%llu", accountIdData );

    return EOS_EResult::EOS_Success;
}

EOS_DECLARE_FUNC( EOS_HAntiCheatClient ) EOS_Platform_GetAntiCheatClientInterface( EOS_HPlatform Handle ) {

    LOG( __FUNCTION__ ": Returning faux EOS game client interface" );

    return g_hAnticheatClient;
}

EOS_DECLARE_FUNC( EOS_EResult ) EOS_AntiCheatClient_BeginSession( EOS_HAntiCheatClient Handle, const EOS_AntiCheatClient_BeginSessionOptions * Options) {

    LOG( __FUNCTION__ ": Creating faux EOS Session..." );

    return EOS_EResult::EOS_Success;
}

EOS_DECLARE_FUNC( EOS_EResult ) EOS_AntiCheatClient_EndSession( EOS_HAntiCheatClient Handle, const EOS_AntiCheatClient_EndSessionOptions* Options ) {

    LOG( __FUNCTION__ ": Ending faux EOS Session..." );

    return EOS_EResult::EOS_Success;
}

EOS_DECLARE_FUNC( EOS_EResult ) EOS_AntiCheatClient_ReceiveMessageFromServer( EOS_HAntiCheatClient Handle, const EOS_AntiCheatClient_ReceiveMessageFromServerOptions* Options ) {

    LOG( __FUNCTION__ ": Receiving message from server..." );

    return EOS_EResult::EOS_Success;
}

EOS_DECLARE_FUNC( EOS_NotificationId ) EOS_AntiCheatClient_AddNotifyMessageToServer( EOS_HAntiCheatClient Handle, const EOS_AntiCheatClient_AddNotifyMessageToServerOptions* Options, void* ClientData, EOS_AntiCheatClient_OnMessageToServerCallback NotificationFn ) {

    if ( NotificationFn ) {
        LOG( __FUNCTION__ ": Calling NotificationFn with NULL message data..." );

        EOS_AntiCheatClient_OnMessageToServerCallbackInfo info = { 0 };
        info.ClientData = ClientData;

        NotificationFn( &info );
    }

    LOG( __FUNCTION__ ": Returning faux EOS_NotificationId..." );

    std::random_device dev;
    std::mt19937 rng( dev() );
    std::uniform_int_distribution<std::mt19937::result_type> dist6( 1, 199 );

    return static_cast<EOS_NotificationId>( dist6( rng ));
}

EOS_DECLARE_FUNC( EOS_NotificationId ) EOS_AntiCheatClient_AddNotifyClientIntegrityViolated( EOS_HAntiCheatClient Handle, const EOS_AntiCheatClient_AddNotifyClientIntegrityViolatedOptions* Options, void* ClientData, EOS_AntiCheatClient_OnClientIntegrityViolatedCallback NotificationFn ) {

    if ( NotificationFn ) {
        LOG( __FUNCTION__ ": Calling NotificationFn with NULL violation..." );

        EOS_AntiCheatClient_OnClientIntegrityViolatedCallbackInfo info = { 0 };
        info.ViolationType = EOS_EAntiCheatClientViolationType::EOS_ACCVT_Invalid;
        info.ClientData = ClientData;
        info.ViolationMessage = 0;

        NotificationFn( &info );
    }

    LOG( __FUNCTION__ ": Returning faux EOS_NotificationId..." );

    std::random_device dev;
    std::mt19937 rng( dev() );
    std::uniform_int_distribution<std::mt19937::result_type> dist6( 1, 199 );

    return static_cast<EOS_NotificationId>( dist6( rng ) );
}


EOS_DECLARE_FUNC( const char* ) EOS_EResult_ToString( EOS_EResult Handle ) {

    LOG( __FUNCTION__ ": Returning \"EOS_Success\"" );

    return "EOS_Success";
}

EOS_DECLARE_FUNC( EOS_EResult ) EOS_Shutdown()
{
    LOG( __FUNCTION__ ": Shutting down EOS..." );

    return EOS_EResult::EOS_UnexpectedError;
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
    case DLL_PROCESS_ATTACH: {

        char inBuf[MAX_PATH]{};
        GetModuleFileNameA( hModule, inBuf, MAX_PATH );
        LoadLibraryA( inBuf );
    }
                           break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH: {
        char inBuf[MAX_PATH]{};
        GetModuleFileNameA( hModule, inBuf, MAX_PATH );
        LoadLibraryA( inBuf );
    }
    break;
    }
    return TRUE;
}

