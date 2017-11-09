#include "cuser.h"
#include <QJsonObject>
#include <QDir>
#include <QFile>
#include <QByteArray>
#include <QJsonDocument>

CUser::CUser(const QString &name)
{
   mCfgPath = "../config/"+name;
   mLogPath = mCfgPath + "/log";
   mCfgFilename = mCfgPath + "/user.json";
}

CUser::~CUser()
{
}

void CUser::load()
{
    QFile file(mCfgFilename);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        const QString data = file.readAll();
        QJsonDocument doc(QJsonDocument::fromJson(data.toLatin1()));
        mJson = doc.object();
        read();
        file.close();
    }
}

void CUser::save()
{
    QDir dir(mCfgPath);
    if (! dir.exists())
        dir.mkpath(".");

    QDir logdir(mLogPath);
    if (! logdir.exists())
        logdir.mkpath(".");

    QFile file(mCfgFilename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate))
    {
        write();
        QString data = QJsonDocument(mJson).toJson();
        file.write(data.toLatin1());
        file.close();
    }
}

const QString& CUser::CfgPath()
{
    return mCfgPath;
}

const QString& CUser::LogPath()
{
    return mLogPath;
}

CApiInterface *CUser::GetMd()
{
    return mMd ;
}

CApiInterface *CUser::GetTd()
{
    return mTd;
}

void CUser::read()
{
    name     = mJson["name"].toString();
    brokerid = mJson["brokerid"].toString();
    account  = mJson["account"].toString();
    userid   = mJson["userid"].toString();
    apitype  = mJson["apitype"].toString();
    tdaddress= mJson["tdaddress"].toString();
    mdaddress= mJson["mdaddress"].toString();
    password = mJson["password"].toString();
    mdtopic  = mJson["mdtopic"].toString();
}

void CUser::write()
{
    mJson["name"]     = name;
    mJson["brokerid"] = brokerid;
    mJson["account"]  = account;
    mJson["userid"]   = userid;
    mJson["apitype"]  = apitype;
    mJson["tdaddress"]= tdaddress;
    mJson["mdaddress"]= mdaddress;
    mJson["password"] = password;
    mJson["mdtopic"]  = mdtopic;
}
