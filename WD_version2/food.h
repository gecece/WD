#ifndef FOOD_H
#define FOOD_H

#include "goods.h"

class Food : public Goods
{
public:
    Food();
    Food(int id, QString goodsName, int amount, double price, QString owner, QDate produceDate, QDate validityDate, QDate reduceDate, double reduceRate);

    QDate getProduceDate();
    QDate getValidityDate();
    QDate getReduceDate();
    double getReduceRate();

    double reducedPrice();
    goodsClass getClass();
    friend QDataStream &operator>>(QDataStream &in, Food &);
    friend QDataStream &operator<<(QDataStream &out, const Food &);

private:
    QDate produceDate;
    QDate validityDate;
    QDate reduceDate;
    double reduceRate;
};


#endif // FOOD_H