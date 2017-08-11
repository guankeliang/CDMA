#include "logindlg.h"
#include <QGridLayout>
#include <QPalette>
#include <QMessageBox>

loginDlg::loginDlg(QWidget *parent) : QDialog(parent)
{
    islogin = false;//初始化登录对话框是置islogin为false

    label0 = new QLabel;
    label0->setText(tr("用户名"));

    label1 = new QLabel;
    label1->setText(tr("密码"));

    label2 = new QLabel;
    label2->setText(tr("数据库名称"));

    label3 = new QLabel;
    label3->setText(tr("服务器IP"));

    lineEditUserID = new QLineEdit;
    lineEditPasswd = new QLineEdit;
    lineEditPasswd->setEchoMode(QLineEdit::Password);
    lineEditDbName = new QLineEdit;
    lineEditHostIP = new QLineEdit;

    loginBtn = new QPushButton;
    loginBtn->setText(tr("登录"));
    logoutBtn = new QPushButton;
    logoutBtn->setText(tr("取消"));

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(label0, 0, 0);
    layout->addWidget(lineEditUserID, 0, 1);
    layout->addWidget(label1, 1, 0);
    layout->addWidget(lineEditPasswd, 1, 1);
    layout->addWidget(label2, 2, 0);
    layout->addWidget(lineEditDbName, 2, 1);
    layout->addWidget(label3, 3, 0);
    layout->addWidget(lineEditHostIP, 3, 1);
    layout->addWidget(loginBtn, 4, 0);
    layout->addWidget(logoutBtn, 4, 1);
    layout->setColumnStretch(0,1);
    layout->setColumnStretch(1, 1);
    setWindowTitle(tr("登录"));
    setWindowIcon(QIcon("timg.jpg"));
    layout->setMargin(15);
    layout->setSpacing(10);
    layout->setSizeConstraint(QLayout::SetFixedSize);

    setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap("5.jpg")));
    setPalette(palette);

    connect(loginBtn, SIGNAL(clicked(bool)), this, SLOT(loginBtnOnclick()));
    connect(logoutBtn, SIGNAL(clicked(bool)), this, SLOT(logoutBtnOnclick()));
}

void loginDlg::loginBtnOnclick()
{
   userid = lineEditUserID->text();
   passwd = lineEditPasswd->text();
   dbname = lineEditDbName->text();
   hostip = lineEditHostIP->text();
   islogin = true;
   close();
}
void loginDlg::logoutBtnOnclick()
{
     close();
}

