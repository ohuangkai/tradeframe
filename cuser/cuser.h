#ifndef CUSER_H
#define CUSER_H

#include <QString>
#include <QJsonObject>
#include "cuser_global.h"
#include "../../common/cuserinfo.h"

class CApiInterface;
class CUSERSHARED_EXPORT CUser : public CUserInfo
{

public:
    explicit CUser(const QString& name);
    ~CUser();
    void load();
    void save();
    const QString& CfgPath();
    const QString& LogPath();
    CApiInterface *GetMd();
    CApiInterface *GetTd();

private:
    CUser();
    void read();
    void write();
    CApiInterface *mMd = nullptr;
    CApiInterface *mTd = nullptr;
    QString mCfgPath;
    QString mLogPath;
    QString mCfgFilename;
    QJsonObject mJson;
};

#endif // CUSER_H
