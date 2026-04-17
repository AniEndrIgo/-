#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "cardwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Table->setSelectionBehavior(QAbstractItemView::SelectRows);//что бы выделить всю строку а не только часть
    ui->Table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    setWindowTitle(" ");
    ui->Table->horizontalHeader()->setStretchLastSection(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearCards()
{
    for (int i = 0; i < cards_.size(); ++i) {
        delete cards_[i];
    }
    cards_.clear();

}

void MainWindow::loadFromFile(const QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл!");
        return;
    }

    clearCards();
    ui->Table->setRowCount(0);


    QTextStream in(&file);
    int lineNum = 1;

    // Читаем файл построчно
    while (!in.atEnd()) {
        // Сохраняем позицию для возможного отката
        QString line = in.readLine();

        // Создаём временный поток для этой строки
        QTextStream lineStream(&line);

        // Пробуем прочитать как RuP (русский формат)
        RuP* ru = new RuP();
        QTextStream tempStream(&line);
        int tempLineNum = lineNum;
        if (ru->readFile(tempStream, tempLineNum)) {
            cards_.append(ru);
            lineNum++;
            continue;
        }
        delete ru;

        // Пробуем прочитать как AmP (американский формат)
        AmP* am = new AmP();
        tempStream.seek(0);
        tempLineNum = lineNum;
        if (am->readFile(tempStream, tempLineNum)) {
            cards_.append(am);
            lineNum++;
            continue;
        }
        delete am;

        // Если ни один формат не подошёл, просто пропускаем строку
        lineNum++;
    }

    file.close();

    if (cards_.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Не удалось загрузить данные из файла!\nПроверьте формат строк.");
    } else {
        updateTable();
        QMessageBox::information(this, "Успех",
                                 QString("Загружено %1 записей").arg(cards_.size()));
    }
}

void MainWindow::updateTable()
{
    ui->Table->setRowCount(cards_.size());

    for (int i = 0; i < cards_.size(); i++) {
        Card* c = cards_[i];

        RuP* ru = dynamic_cast<RuP*>(c);
        if (ru) {
            // Русский формат: фамилия, имя, отчество
            ui->Table->setItem(i, 0, new QTableWidgetItem(ru->getSurname_()));
            ui->Table->setItem(i, 1, new QTableWidgetItem(ru->getName_()));
            ui->Table->setItem(i, 2, new QTableWidgetItem(
                                         ru->getPatrnumic_().isEmpty() ? "-" : ru->getPatrnumic_()));
        } else {
            AmP* am = dynamic_cast<AmP*>(c);
            if (am) {
                // Американский формат: фамилия, имя, второе имя
                ui->Table->setItem(i, 0, new QTableWidgetItem(am->getSurname_()));
                ui->Table->setItem(i, 1, new QTableWidgetItem(am->getName_()));
                ui->Table->setItem(i, 2, new QTableWidgetItem(
                                             am->getSecondName().isEmpty() ? "-" : am->getSecondName()));
            }
        }
        int day = c->getDay_();
        int month = c->getMonth_();
        int year = c->getYear_();
        // Дата рождения в 4-й колонке
        QString dateStr = QString::number(day).rightJustified(2, '0') + "." +
                          QString::number(month).rightJustified(2, '0') + "." +
                          QString::number(year);
        ui->Table->setItem(i, 3, new QTableWidgetItem(dateStr));
    }

    // Автоматическая высота строк
    ui->Table->resizeRowsToContents();
    ui->Table->resizeColumnsToContents();
}

void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Выберите файл с данными", "", "Текстовые файлы (*.txt);;Все файлы (*)");

    if (!filename.isEmpty()) {
        loadFromFile(filename);
    }
}
void MainWindow::on_Table_cellDoubleClicked(int row, int column)
{
    Q_UNUSED(column);

    if (row < 0 || row >= cards_.size()) return;

    Card* card = cards_[row];
    if (!card) return;

    int result = card->Craft();  // ТЕПЕРЬ ПОЛУЧАЕМ РЕЗУЛЬТАТ

    if (result == QDialog::Accepted) {  // 1 - печать
        delete cards_[row];
        cards_.removeAt(row);
        updateTable();
    }
}

