#include "mainwindow.h" 
#include <QMessageBox>
#include <QMdiSubWindow>
#include <QStandardItemModel>
#include <QTableView>
#include "logindlg.h"
#include "scriptdlg.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("CDMA无线基站管理系统");
    mdiArea = new QMdiArea;
    setCentralWidget(mdiArea);
    mdiArea->setBackground(Qt::NoBrush);
    mdiArea->setStyleSheet("background-image: url(1.jpg);"); //背景设置为1.jpg,子窗口大小可调整

    mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    setWindowIcon(QIcon("timg.jpg"));
    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenus()
{
    adminMenu = menuBar()->addMenu("管理"); //添加管理菜单
    adminMenu->addAction(loginAction);
    adminMenu->addAction(logoutAction);
    adminMenu->addSeparator(); //加入分隔符
    adminMenu->addAction(exitAction);

    dataMenu = menuBar()->addMenu("数据");
    dataMenu->addAction(scriptAction);

    windowMenu = menuBar()->addMenu("窗口");
    windowMenu->addAction(cascadeAction);
    windowMenu->addAction(tileAction);

    helpMenu = menuBar()->addMenu("关于软件");
    helpMenu->addAction(helpAction);
    helpMenu->addAction(aboutAction);
}

void MainWindow::createActions()
{
    loginAction = new QAction(tr("登录"), this);
    loginAction->setShortcut(tr("Ctrl + L"));
    connect(loginAction, SIGNAL(triggered()), this, SLOT(on_login()));

    logoutAction = new QAction(tr("注销"), this);
    logoutAction->setShortcut(tr("Ctrl + o"));
    connect(logoutAction, SIGNAL(triggered()), this, SLOT(on_logout()));

    exitAction = new QAction(tr("退出"), this);
    exitAction->setShortcut(tr("Ctrl + e"));
    connect(exitAction, SIGNAL(triggered()), this, SLOT(on_exit()));

    scriptAction = new QAction(tr("执行脚本"), this);
    scriptAction->setShortcut(tr("Ctrl + p"));
    connect(scriptAction, SIGNAL(triggered()), this, SLOT(on_script()));

    cascadeAction = new QAction(tr("层叠窗口"), this);
    cascadeAction->setShortcut(tr("ctrl + q"));
    connect(cascadeAction, SIGNAL(triggered()), this, SLOT(cascadeSubWindows()));

    tileAction = new QAction(tr("并列"), this);
    tileAction->setShortcut(tr("ctrl + t"));
    connect(tileAction, SIGNAL(triggered()), this, SLOT(tileSubWindows()));

    helpAction = new QAction(tr("帮助"), this);
    helpAction->setShortcut(tr("ctrl + h"));
    connect(helpAction, SIGNAL(triggered()), this, SLOT(on_help()));

    aboutAction = new QAction(tr("关于"), this);
    aboutAction->setShortcut(tr("ctrl + a"));
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(on_about()));

}

void MainWindow::on_login()
{
   loginDlg dlg;
   dlg.exec();
   if(dlg.islogin)
   {

       int res = db.sql_connect(dlg.hostip.toStdString().data(), dlg.userid.toStdString().data(),
                      dlg.passwd.toStdString().data(), dlg.dbname.toStdString().data());

       if(res == -1)
       {
           QMessageBox::information(this, "登录失败", db.geterror());
       }
       else
       {
            QMessageBox::information(this, "", "登录成功");
       }
       /*
       if((dlg.userid == "abc") && (dlg.passwd == "123456"))
       {
           QMessageBox::information(this, "", "登录成功");
       }
       else
       {
           QMessageBox::information(this, "", "登录失败");
       }
       */
   }
}

void MainWindow::on_logout()
{

    QMessageBox::StandardButton button = QMessageBox::question(this, "提示", "是否注销？",
                                                                          QMessageBox::Yes | QMessageBox::No );
    if(button == QMessageBox::Yes)
    {
        db.sql_disconnect();
    }
    //QMessageBox::information(this, "", "Hello World");
}

void MainWindow::on_exit()
{
    close();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton button = QMessageBox::question(this, "提示", "是否退出？",
                                                                          QMessageBox::Yes | QMessageBox::No );
    if(button == QMessageBox::Yes)
    {
        event->accept(); //接受退出
    }else
    {
        event->ignore(); //忽略退出
    }

}

void MainWindow::showsub()
{
    QWidget *w1 = new QWidget;
    w1->setAttribute(Qt::WA_DeleteOnClose); //代表关闭这个Widget时候，自动将这个Widget 删除
    mdiArea->addSubWindow(w1);
    w1->setWindowTitle("脚本");
    w1->setStyleSheet("background-image: url(5.jpg);");
    w1->show();
    mdiArea->activeSubWindow()->resize(width()-350, height()-250);
}

void MainWindow::on_script()
{
    scriptDlg dlg;
    dlg.exec();
    if (db.sql_exec(dlg.Sql.toStdString().data()) == -1)
    {
        QMessageBox::information(this, "执行失败", db.geterror());
    }else
    {
        QMessageBox::information(this, "提示", "执行成功");
    }
}

void MainWindow::cascadeSubWindows()
{
    mdiArea->cascadeSubWindows();
}

void MainWindow::tileSubWindows()
{
    mdiArea->tileSubWindows();
}

void MainWindow::on_help()
{
    QMessageBox::information(this, "帮助", "请参阅网站！");
}

void MainWindow::on_about()
{
     QMessageBox::information(this, "关于", "请参阅网站！");
}

void MainWindow::showview()
{
    QStandardItemModel *model = new QStandardItemModel(5, 3);//建立一个modle
    model->setHeaderData(0,Qt::Horizontal, "姓名");
    model->setHeaderData(1,Qt::Horizontal, "年龄");
    model->setHeaderData(2,Qt::Horizontal, "性别");
    //设置model的每一个单元格的内容
    model->setData(model->index(0,0, QModelIndex()), "张三");
    QTableView *view1 = new QTableView;
    view1->setAttribute(Qt::WA_DeleteOnClose);
    mdiArea->addSubWindow(view1);
    view1->setStyleSheet("background-image: url(5.jpg);");
    view1->setModel(model);
    view1->show();


}


