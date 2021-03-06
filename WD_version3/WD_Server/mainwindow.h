#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtNetwork>

#include "buyer.h"
#include "member.h"
#include "seller.h"
#include "food.h"
#include "electronics.h"
#include "dailynecessities.h"

namespace Ui
{
class MainWindow;
}

typedef enum {
    RegisterRequest, RegisterResponse,
    LoginRequest, LoginResponse,
    BuyRequest, BuyResponse,
    StockRequest, StockResponse,
    RechargeRequest, RechargeResponse,
    UpgradeRequest, UpgradeResponse,
    ExchangeRequest, ExchangeResponse,
    LogoutRequest, ServerExit
}UdpType;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    //void sendResponse(UdpType type);
    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;
    QUdpSocket* udpSocket;
    QHostAddress serverAddr;
    qint16 clientPort, serverPort;

    int USERID;
    int GOODSID;
    User *curUser;
    QList<Buyer> listBuyer;
    QList<Member> listMember;
    QList<Seller> listSeller;
    QList<Food> listFood;
    QList<Electronics> listElect;
    QList<DailyNecessities> listDaily;

    /*********************  Custom Functions *****************************/
    bool loadData();
    User *findUser(QString userName, int &pos);
    Goods *findGoods(int id, int &pos);
    QVector<QVector<QStringList> > getAllGoods();

private slots:
    void on_action_about_triggered();
    void on_action_help_triggered();
    void processPendingDatagrams();
};

#endif // MAINWINDOW_H
