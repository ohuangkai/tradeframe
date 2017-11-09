#ifndef CMDWRAPPER_H
#define CMDWRAPPER_H
#include <vector>
#include <map>
#include <QString>

#include "capiinterface.h"
#include "cuserinfo.h"
#include "cmarketdata.h"
#include "cstrategy.h"
#include "apiwrapper_global.h"



class APIWRAPPERSHARED_EXPORT CMdWrapper : public CApiInterface
{
public:
    CMdWrapper();
    virtual ~CMdWrapper();
    QString GetApiTypename() override {}
    QString GetTradingday()  override {}

    void Connect(const CUserInfo&) override {}
    void ReleaseConnect() override {}

    bool IsConnect() override;

    CUserInfo &GetUserInfo()override ;

    void SubMd(const QString& id, CStrategy *ts);
    bool IsSubed(const QString& id);
    void OnTick(const CMarketData& tick);

protected:
    CUserInfo mUserInfo;
    void SetConnectOn();
    void SetConnectOff();

private:
    bool mIsConnect = false;
    std::multimap<QString,CStrategy *> mIdTs;
    std::map<QString,CStrategy::ptr>   mTicks;
};

#endif // CMDWRAPPER_H
