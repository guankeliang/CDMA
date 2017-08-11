#include "scriptdlg.h"
#include <QGridLayout>

scriptDlg::scriptDlg(QWidget *parent)
{
    label0 = new QLabel;
    label0->setText(tr("请输入SQL语句"));
    textEditSQL = new QTextEdit;
    execBtn = new QPushButton;
    execBtn->setText(tr("执行"));
    cancelBtn = new QPushButton;
    cancelBtn->setText(tr("取消"));

    QGridLayout *layout1 = new QGridLayout(this);
    layout1->addWidget(label0, 0, 0);
    layout1->addWidget(textEditSQL, 1, 0);
    QGridLayout *layout2 = new QGridLayout;
    layout2->addWidget(execBtn);
    layout2->addWidget(cancelBtn);
    layout1->addLayout(layout2, 2, 0);

    connect(execBtn, SIGNAL(clicked()), this, SLOT(execBtnClicked()));
    connect(cancelBtn, SIGNAL(clicked()), this, SLOT(cancelBtnClicked()));
}

void scriptDlg::execBtnClicked()
{
    Sql = textEditSQL->toPlainText();
    close();
}

void scriptDlg::cancelBtnClicked()
{
    close();
}

