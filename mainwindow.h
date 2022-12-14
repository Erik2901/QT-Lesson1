#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_solve_button_clicked();

    void on_solve_button_2_clicked();

    void on_move_text_button_clicked();

    void on_change_text_button_clicked();

    void on_code_button_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
