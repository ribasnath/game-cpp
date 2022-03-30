#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "game.h"
#include "about.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    About* about;

private slots:
    void on_Jogar_clicked();
    void start_game();

    void on_Sair_clicked();

    void on_Sobre_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
