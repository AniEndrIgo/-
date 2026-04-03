#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QRegularExpression>
#include <QMessageBox>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->airline->setChecked(true);
    ui->irrevocable->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_reset_clicked()
{
    ui->line_for_cargo->clear();
    ui->line_for_country->clear();
    ui->line_for_delivery->clear();
    ui->line_for_weight->clear();
    ui->airline->setChecked(true);
    ui->irrevocable->setChecked(true);
    ui->new_2->setChecked(false);
    ui->damage->setChecked(false);
}

bool isRegularCargo(const QString& text, QString& errorMessage){
    if(text.isEmpty()){
        errorMessage = "Поле груза или страны пустое";
        return false;
    }

    QRegularExpression regular("^[A-ZА-Я][a-zа-я]*( [A-ZА-Я][a-zа-я]*)*$");

    if (!regular.match(text).hasMatch()) {
        errorMessage = "Некорректный формат!\n"
                       "Требования:\n"
                       "• Только русские и английские буквы\n"
                       "• Каждое слово с заглавной буквы или все с заглавной и максимум по 1 пробелу(проверьте что бы в конце не было пробела)";


        return false;
    }

    errorMessage = "";
    return true;
}
bool isRegularCountry(const QString& text, QString& errorMessage){
    if(text.isEmpty()){
        errorMessage = "Поле страны пустое";
        return false;
    }

    // Вариант 1: все заглавные (РОССИЯ)
    // Вариант 2: первая заглавная, остальные строчные (Россия)
    QRegularExpression regular("^([A-ZА-ЯЁ]+|[A-ZА-ЯЁ][a-zа-яё]*)([ ]+([A-ZА-ЯЁ]+|[A-ZА-ЯЁ][a-zа-яё]*))*$");

    if (!regular.match(text).hasMatch()) {
        errorMessage = "Некорректный формат!\n"
                       "Требования:\n"
                       "• Только русские и английские буквы\n"
                       "• Все буквы заглавные или только первая заглавная";
        return false;
    }

    errorMessage = "";
    return true;
}

bool isRegularWeight(const QString& text, QString& errorMessage)
{
    if (text.isEmpty()) {
        errorMessage = "Поле веса пустое";
        return false;
    }

    bool ok;
    int value = text.toInt(&ok);

    if (!ok || value <= 0) {
        errorMessage = "Вес недействительный";
        return false;
    }

    errorMessage = "";
    return true;
}

bool isRegularDelivery(const QString& text, QString& errorMessage)
{
    if (text.isEmpty()) {
        errorMessage = "Поле цены пустое";
        return false;
    }

    bool ok;
    double totalDelivery = text.toDouble(&ok);

    if (!ok || totalDelivery < 0) {
        errorMessage = "Стоимость недействительная";
        return false;
    }

    errorMessage = "";
    return true;
}


void MainWindow::on_save_clicked()
{
    QString qcargo = ui->line_for_cargo->text();
    QString qcountry = ui->line_for_country->text();
    QString qweight = ui->line_for_weight->text();
    QString qdelivery = ui->line_for_delivery->text();

    QString errorMsg;

    if (!isRegularCargo(qcargo, errorMsg)) {
        QMessageBox::warning(this, "Ошибка в поле 'Груз'", errorMsg);
        return;
    }

    if (!isRegularCountry(qcountry, errorMsg)) {
        QMessageBox::warning(this, "Ошибка в поле 'Страна'", errorMsg);
        return;
    }

    if (!isRegularWeight(qweight, errorMsg)) {
        QMessageBox::warning(this, "Ошибка в поле 'Вес'", errorMsg);
        return;
    }

    if (!isRegularDelivery(qdelivery, errorMsg)) {
        QMessageBox::warning(this, "Ошибка в поле 'Стоимость'", errorMsg);
        return;
    }

    int weight = qweight.toInt();
    double delivery = qdelivery.toDouble();
    double pricePerKg = delivery / weight;

    if (pricePerKg > 100000.0) {
        QString loseMsg = "Цена за кг (" + QString::number(pricePerKg, 'f', 2) + " руб/кг) превышает лимит 100 000 руб/кг!";
        QMessageBox::warning(this, "Ошибка", loseMsg);
        return;
    }

    std::ofstream file("data.txt", std::ios::trunc);

    if (file.is_open()) {
        file << "Груз: " + qcargo.toStdString() + "\n";
        file << "Страна: " + qcountry.toStdString() + "\n";
        file << "Вес: " + qweight.toStdString() + "\n";
        file << "Цена: " + qdelivery.toStdString() + "\n";

        if (ui->airline->isChecked()) {
            file << "Способ доставки: Самолет\n";
        } else {
            file << "Способ доставки: Корабль\n";
        }

        if (ui->damage->isChecked() || ui->irrevocable->isChecked() || ui->new_2->isChecked()) {
            file << "Маркеры: ";
            if (ui->damage->isChecked()) {
                file << "Повреждение ";
            }
            if (ui->irrevocable->isChecked()) {
                file << "Новинка ";
            }
            if (ui->new_2->isChecked()) {
                file << "Безвозвратное ";
            }
        }

        file.close();

        QMessageBox::information(this, "Успех", "Данные записаны в файл data.txt");

        QApplication::quit();
    }
}


