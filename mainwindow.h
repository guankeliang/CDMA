#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QCloseEvent>
#include <QMdiArea>
#include "my_sql.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showsub();
    void closeEvent(QCloseEvent * event);
private:
    void createMenus();
    void createActions();
    void showview();
    void showmoudle();
private:
    my_sql db;
    QMdiArea *mdiArea;
    QMenu *adminMenu;
    QMenu *dataMenu;
    QMenu *windowMenu;
    QMenu *helpMenu;

    QAction *loginAction;
    QAction *logoutAction;
    QAction *exitAction;

    QAction *scriptAction;

    QAction *cascadeAction;
    QAction *tileAction;

    QAction *helpAction;
    QAction *aboutAction;



private slots:
    void on_login();
    void on_logout();
    void on_exit();
    void on_script();

    void cascadeSubWindows();
    void tileSubWindows();

    void on_help();
    void on_about();
};

#endif // MAINWINDOW_H
