#include "pch.h"

void IGameClientBase::Initialize( void* progressFunc, void* initFunc, void* a3 ) {

    OutputDebugStringA( "Call to GameClientBase->Initialize" );

    if ( initFunc )
        ( ( void( * )( EACAsyncResult result, const char* szMessage, void* pCallbackParameter ) )initFunc )( InitSuccess, nullptr, a3 );
}

void IGameClientBase::Destroy() {

    OutputDebugStringA( "Call to GameClientBase->Destroy" );
}

void IGameClientBase::ConnectionReset()
{
    OutputDebugStringA("Call to GameClientBase->ConnectionReset");
}

bool IGameClientBase::PopNetworkMessage( char** data, unsigned int* len ) {

    OutputDebugStringA(va("Call to GameClientBase->PopNetworkMessage data: %llX len: %d", data, (len ? *len : 0)));

    return false;
}

void IGameClientBase::PushNetworkMessage(char* data, const unsigned int len)
{ 
    OutputDebugStringA(va("Call to GameClientBase->PushNetworkMessage data: %llX len: %d", data, len));
}

void IGameClientBase::PollStatus(bool(__fastcall*  OnIntegrityViolation)(const ClientIntegrityViolationType, const char*, const char*, void*), bool(__fastcall* OnServerHostValidate)(const ServerHostValidationResult, const char*, void*))
{
    OutputDebugStringA("Call to GameClientBase->PollStatus");

    //if (OnIntegrityViolation)
       // OnIntegrityViolation(ClientIntegrityViolationType::IntegrityViolationNone, 0, 0, 0);

    if (OnServerHostValidate)
        OnServerHostValidate(ServerHostAccountStatusOk, 0, 0);
}

void IGameClientBase::xyz()
{ }

void IGameClientBase::xxz()
{ }

void IGameClientBase::yxx()
{ }

void IGameClientBase::yxz()
{ }

bool IGameClientBase::InitLocalization(const char* a1, const char* a2)
{
    OutputDebugStringA("Call to GameClientBase->InitLocalization");

    return true;
}

void IClientAuth::xyz()
{
}

void IClientAuth::Destroy()
{
    OutputDebugStringA("Call to IClientAuth->Destroy");
}

void IClientAuth::zxy()
{
}

bool IClientAuth::GetAuthTicket(void* authInfo, char* szAuthTicketBuffer)
{
    OutputDebugStringA("Call to IClientAuth->GetAuthTicket");

    return true;
}
