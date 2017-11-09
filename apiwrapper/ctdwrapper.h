#ifndef CTDWRAPPER_H
#define CTDWRAPPER_H

#include "apiwrapper_global.h"
#include "capiinterface.h"

class APIWRAPPERSHARED_EXPORT CTdWrapper : public CApiInterface
{

public:
    CTdWrapper();
    virtual ~CTdWrapper();
    virtual QString GetApiTypename() = 0;
    virtual QString GetTradingday() = 0;

    virtual void Connect(const CUserInfo&) = 0;
    virtual void ReleaseConnect() = 0;

    virtual bool IsConnect() = 0;

    virtual CUserInfo& GetUserInfo() = 0;
};

#endif // CTDWRAPPER_H
