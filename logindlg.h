#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class loginDlg : public QDialog
{
    Q_OBJECT
public:
    explicit loginDlg(QWidget *parent = 0);
signals:
private slots:
    void loginBtnOnclick();
    void logoutBtnOnclick();
private:
    QLabel *label0, *label1, *label2, *label3;
    QLineEdit *lineEditUserID, *lineEditPasswd, *lineEditDbName, *lineEditHostIP;
    QPushButton *loginBtn, *logoutBtn;

public:
    QString userid;
    QString passwd;
    QString dbname;
    QString hostip;
    bool islogin;
};

#endif // LOGINDLG_H
