#include "cardwindow.h"
#include "ui_cardwindow.h"
#include <QMessageBox>


CardWindow::CardWindow(Card* card, QWidget *parent): QDialog(parent), ui(new Ui::CardWindow), card_(card)
{
    ui->setupUi(this);

    setWindowTitle("Карточка");


}

void CardWindow::fillWindow(Card* card)
{
    RuP* ru = dynamic_cast<RuP*>(card);
    if (!card) return;
    if (ru) {
        ui->labelSurname->setText(ru->getSurname_());
        ui->labelName->setText(ru->getName_());
        ui->labelPatrnumic->setText(ru->getPatrnumic_().isEmpty() ? "-" : ru->getPatrnumic_());

        QString date = QString::number(ru->getDay_()).rightJustified(2, '0') + "." + QString::number(ru->getMonth_()).rightJustified(2, '0') + "." + QString::number(ru->getYear_());
        ui->labelDate->setText(date);
    }

    AmP* am = dynamic_cast<AmP*>(card);
    if (am) {
        ui->labelName->setText(am->getName_());
        ui->labelSecondName->setText(am->getSecondName());
        ui->labelSurname->setText(am->getSurname_());

        QString date = QString::number(am->getMonth_()).rightJustified(2, '0') + "/" + QString::number(am->getDay_()).rightJustified(2, '0') + "/" + QString::number(am->getYear_());
        ui->labelDate->setText(date);
    }
}

CardWindow::~CardWindow()
{
    delete ui;
}

void CardWindow::on_printButton_clicked()
{
    QMessageBox::information(this, "Печать",
                             "Отправлено на печать:\n\n");
    accept();
}

void CardWindow::on_cancelButton_clicked()
{
    reject();
}
