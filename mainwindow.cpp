#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "progRes.h"

const unsigned short prec = 3;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Установка заголовка-названия программы
    this->setWindowTitle("Vector Calculator");

    // Установка ограничения на ввод только значений с плавующей точкой от -999999.999 до 999999.999
    QRegularExpression regex("^(-)?([0-9]{1,4})(\\.[0-9]{1," + QString::number(prec) + "})?$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    ui->a_x->setValidator(validator);
    ui->a_y->setValidator(validator);
    ui->a_z->setValidator(validator);
    ui->b_x->setValidator(validator);
    ui->b_y->setValidator(validator);
    ui->b_z->setValidator(validator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Вычисление данных по нажатие клавиши
void MainWindow::on_calculate_clicked()
{
    Calculations Calc;
    // Считывание данных от пользователя
    Calc.A.x = ui->a_x->text().toDouble();
    Calc.A.y = ui->a_y->text().toDouble();
    Calc.A.z = ui->a_z->text().toDouble();
    Calc.B.x = ui->b_x->text().toDouble();
    Calc.B.y = ui->b_y->text().toDouble();
    Calc.B.z = ui->b_z->text().toDouble();

    // Расчет данных
    Calc.Sum = Calc.A + Calc.B;
    Calc.Diff = Calc.A - Calc.B;
    Calc.CrossProd = Calc.A.crossProd(Calc.B);
    Calc.dotProd = Calc.A.dotProd(Calc.B);
    Calc.sumLength = Calc.Sum.len();
    Calc.diffLength = Calc.Diff.len();
    Calc.cosinus = Calc.A.cosBetween(Calc.B);
    Calc.angle = Calc.A.angle(Calc.B);

    // Вывод данных на экран
    ui->sum_x->setText(QString::number(Calc.Sum.x, 10, prec));
    ui->sum_y->setText(QString::number(Calc.Sum.y, 10, prec));
    ui->sum_z->setText(QString::number(Calc.Sum.z, 10, prec));

    ui->diff_x->setText(QString::number(Calc.Diff.x, 10, prec));
    ui->diff_y->setText(QString::number(Calc.Diff.y, 10, prec));
    ui->diff_z->setText(QString::number(Calc.Diff.z, 10, prec));

    ui->mul_x->setText(QString::number(Calc.CrossProd.x, 10, prec));
    ui->mul_y->setText(QString::number(Calc.CrossProd.y, 10, prec));
    ui->mul_z->setText(QString::number(Calc.CrossProd.z, 10, prec));

    ui->sumLen->setText(QString::number(Calc.sumLength, 10, prec));
    ui->diffLen->setText(QString::number(Calc.diffLength, 10, prec));
    ui->dotProd->setText(QString::number(Calc.dotProd, 10, prec));

    // Вывод угла между векторами, если значения не существует
    if (std::isnan(Calc.cosinus) || std::isnan(Calc.angle))
    {
        ui->cosAngle->setText("Не существует");
        ui->angle->setText("Не существует");
    }
    else
    {
        ui->cosAngle->setText(QString::number(Calc.cosinus, 10, prec));
        ui->angle->setText(QString::number(Calc.angle * 180 / 3.14159, 10, prec) + "°");
    }
}

