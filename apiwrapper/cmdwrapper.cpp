#include "cmdwrapper.h"
#include "cmonitor.h"

CMdWrapper::CMdWrapper()
{

}

bool CMdWrapper::IsConnect()
{
    return mIsConnect;
}

CUserInfo &CMdWrapper::GetUserInfo()
{
    return mUserInfo;
}

void CMdWrapper::SubMd(const QString &id, CStrategy *ts)
{

}

void CMdWrapper::SetConnectOn()
{
    mIsConnect = true;
}

void CMdWrapper::SetConnectOff()
{
    mIsConnect = false;
}
