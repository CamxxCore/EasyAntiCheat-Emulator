#include "pch.h"

void IGameClientBase::Initialize(void* progressFunc, void* initFunc, void* a3) {

	OutputDebugStringA("Call to GameClientBase->Initialize");

	if (initFunc)
		((void(*)(EACAsyncResult result, const char* szMessage, void* pCallbackParameter))initFunc)(InitSuccess, nullptr, a3);
}

void IGameClientBase::Destroy() {

	OutputDebugStringA("Call to GameClientBase->Destroy");
}

void IGameClientBase::zxy()
{ }

bool IGameClientBase::GetMessageData(char** data, unsigned int* len) {

	return false;
}

void IGameClientBase::zzx()
{ }

void IGameClientBase::OnIntegrityViolation(void* a1, __int64 a2, void* a3)
{ }

void IGameClientBase::xyz()
{ }

void IGameClientBase::xxz()
{ }

void IGameClientBase::yxx()
{ }

void IGameClientBase::yxz()
{ }

void IGameClientBase::xzy(void* a1, void* a2) {

	OutputDebugStringA("Call to GameClientBase->PreInit");
}
