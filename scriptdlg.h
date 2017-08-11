#ifndef SCRIPTDLG_H
#define SCRIPTDLG_H

#include <QDialog>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>

class scriptDlg : public QDialog
{
    Q_OBJECT
public:
    explicit scriptDlg(QWidget *parent = 0);
signals:
public slots:

public:
    QString Sql;
private:
    QLabel *label0;
    QTextEdit *textEditSQL;
    QPushButton *execBtn, *cancelBtn;
private slots:
    void execBtnClicked();
    void cancelBtnClicked();

};

#endif // SCRIPTDLG_H
