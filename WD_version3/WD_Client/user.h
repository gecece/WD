#ifndef USER_H
#define USER_H

#include <QString>
#include <QVector>
#include <QStringList>

enum UserClass {BUYER, MEMBER, SELLER};

class User
{
public:
    User();
    User(int id, QString userName, QString password, double balance = 0.0);
    virtual ~User();

    int getId() const;
    QString getUserName() const;
    QString getPassword() const;
    double getBalance() const;
    double recharge(double money);
    virtual UserClass getClass() = 0;

protected:
    int id;
    QString userName;
    QString password;
    double balance;
};

#endif // USER_H