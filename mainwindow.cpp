#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_solve_button_clicked()
{
    qreal a = ui->a_line->text().toFloat();
    qreal b = ui->b_line->text().toFloat();
    qreal c = ui->c_line->text().toFloat();

    if ( a == 0){
        qreal x = -1*(c/b);
        ui->result_line->setText("X = " + QString::number(x));
    }
    else{
        qreal D=qPow(b,2)-(4*a*c);
        if (D<0){
            ui->result_line->setText("Can't Get X");
        }
        else if(D==0){
            qreal x = (-1*b)/(2*a);
            ui->result_line->setText("X = " + QString::number(x));
        }
        else{
            qreal x1=((-1*b)+(qSqrt(D)))/(2*a);
            qreal x2=((-1*b)-(qSqrt(D)))/(2*a);
            ui->result_line->setText("X1 = " + QString::number(x1) + " , " +  "X2 = " + QString::number(x2));
        }
    }
}

void MainWindow::on_solve_button_2_clicked()
{
    qint32 a2 = ui->a_line_2->text().toInt();
    qint32 b2 = ui->b_line_2->text().toInt();
    qint32 c2 = 0;
    qreal angle = ui->angle_line->text().toFloat();
    qreal angle_set = 0;
    if(ui->degree_button->isChecked()){

        angle_set = angle;
    }
    else if(ui->radian_button->isChecked()){
        angle_set =  angle * 180/3.14;
    }
    if (angle_set>90){
        c2 = qSqrt(qPow(a2,2) + qPow(b2,2) - 2*a2*b2 * (-1*qCos(angle_set)));
    }
    else{
        c2 = qSqrt(qPow(a2,2) + qPow(b2,2) - 2*a2*b2 * qCos(angle_set));
    }
    ui->result_line_2->setText("c = " + QString::number(c2));
}


void MainWindow::on_move_text_button_clicked()
{
    QString text_st = ui->Text_1->toPlainText();
    ui->Text_2->document()->setPlainText(text_st);
}


void MainWindow::on_change_text_button_clicked()
{
    QString text_st1 = ui->Text_1->toPlainText();
    QString text_st2 = ui->Text_2->toPlainText();
    ui->Text_1->document()->setPlainText(text_st2);
    ui->Text_2->document()->setPlainText(text_st1);
}


void MainWindow::on_code_button_clicked()
{
    QString html = "<font color='red'>Hello</font>";
    ui->Text_2->document()->setHtml(html);
}

