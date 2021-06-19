#include "tool.h"

Tool::Tool()
{

}

int Tool::bin2dec(long long n){
    int decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += static_cast<int>(remainder * pow(2,i));
        ++i;
    }
    return decimalNumber;
}

Gua Tool::readJson(QString string) {
    QString val;
    QFile file;
    file.setFileName(":bagua.json");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject guaMap = d.object();
    QJsonValue guaMapValue = guaMap.value(QString("guaMap"));
    QJsonObject item = guaMapValue.toObject();
    QJsonObject nodeObject = item.value(string).toObject();

    Gua nodeEntity;
    nodeEntity.top          =   nodeObject.value("top").toString();
    nodeEntity.left         =   nodeObject.value("left").toString();
    nodeEntity.right        =   nodeObject.value("right").toString();
    nodeEntity.bottom       =   nodeObject.value("bottom").toString();
    nodeEntity.gua_ci       =   nodeObject.value("guaCi").toString();
    nodeEntity.tuan_ci      =   nodeObject.value("tuanCi").toString();
    nodeEntity.da_xiang     =   nodeObject.value("daXiang").toString();
    nodeEntity.xiang_ci     =   nodeObject.value("xiangCi").toString();
    nodeEntity.xiao_xiang_1 =   nodeObject.value("xiaoXiang_1").toString();
    nodeEntity.xiao_xiang_2 =   nodeObject.value("xiaoXiang_2").toString();
    nodeEntity.xiao_xiang_3 =   nodeObject.value("xiaoXiang_3").toString();
    nodeEntity.xiao_xiang_4 =   nodeObject.value("xiaoXiang_4").toString();
    nodeEntity.xiao_xiang_5 =   nodeObject.value("xiaoXiang_5").toString();
    nodeEntity.xiao_xiang_6 =   nodeObject.value("xiaoXiang_6").toString();
    nodeEntity.xiao_xiang_7 =   nodeObject.value("xiaoXiang_7").toString();
    nodeEntity.yao_ci       =   nodeObject.value("yaoCi").toString();
    nodeEntity.yao_1        =   nodeObject.value("yao_1").toString();
    nodeEntity.yao_2        =   nodeObject.value("yao_2").toString();
    nodeEntity.yao_3        =   nodeObject.value("yao_3").toString();
    nodeEntity.yao_4        =   nodeObject.value("yao_4").toString();
    nodeEntity.yao_5        =   nodeObject.value("yao_5").toString();
    nodeEntity.yao_6        =   nodeObject.value("yao_6").toString();
    nodeEntity.yao_7        =   nodeObject.value("yao_7").toString();
    return nodeEntity;
}
