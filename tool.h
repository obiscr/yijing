#ifndef TOOL_H
#define TOOL_H

#include <math.h>
#include <QString>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>

typedef struct gua
{
    QString top;
    QString left;
    QString right;
    QString bottom;

    QString gua_ci;
    QString tuan_ci;

    QString da_xiang;
    QString xiang_ci;
    QString xiao_xiang_1;
    QString xiao_xiang_2;
    QString xiao_xiang_3;
    QString xiao_xiang_4;
    QString xiao_xiang_5;
    QString xiao_xiang_6;
    QString xiao_xiang_7;

    QString yao_ci;
    QString yao_1;
    QString yao_2;
    QString yao_3;
    QString yao_4;
    QString yao_5;
    QString yao_6;

    QString yao_7;
} Gua;


class Tool
{
public:
    Tool();
    int bin2dec(long long n);
    Gua readJson(QString string);
};

#endif // TOOL_H
