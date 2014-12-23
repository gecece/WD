#include "goods.h"

Goods::Goods()
{
}

Goods::Goods(int id, QString foodName, int amount, double price, QString owner)
{
    this->id = id;
    this->goodsName = foodName;
    this->amount = amount;
    this->price = price;
    this->owner = owner;
}

Goods::~Goods()
{
}

int Goods::getId() const
{
    return id;
}

int Goods::getAmount() const
{
    return amount;
}

double Goods::getPrice() const
{
    return price;
}

QString Goods::getOwner() const
{
    return owner;
}

QString Goods::getGoodsName() const
{
    return goodsName;
}

void Goods::changeAmount(int amount)
{
    this->amount += amount;
}
