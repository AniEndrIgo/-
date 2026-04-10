#include "mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QHeaderView>
#include <QGroupBox>
#include <QDialog>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setupUI();
}

MainWindow::~MainWindow() {
    clearCards();
}

void MainWindow::clearCards() {
    for (Card* c : cards_) {
        delete c;
    }
    cards_.clear();
}

void MainWindow::setupUI() {
    setWindowTitle(" ");
    setFixedSize(600, 450);

    QWidget* centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout* mainLayout = new QVBoxLayout(centralWidget);

    QGroupBox* groupBox = new QGroupBox(this);
    groupBox->setTitle("");

    QVBoxLayout* groupLayout = new QVBoxLayout(groupBox);

    table = new QTableWidget(this);
    table->setColumnCount(3);
    table->setHorizontalHeaderLabels({""});
    table->verticalHeader()->setVisible(false);
    table->horizontalHeader()->setVisible(false);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setShowGrid(false);
    groupLayout->addWidget(table);

    mainLayout->addWidget(groupBox);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    loadButton = new QPushButton("Загрузить", this);
    loadButton->setMinimumHeight(35);
    loadButton->setStyleSheet("font-size: 14px; padding: 5px;");
    mainLayout->addWidget(loadButton);

    connect(loadButton, &QPushButton::clicked, this, &MainWindow::onLoadButtonClicked);
    connect(table, &QTableWidget::cellDoubleClicked, this, &MainWindow::onTableDoubleClicked);
}

void MainWindow::onLoadButtonClicked() {
    QString filename = QFileDialog::getOpenFileName(this, "Выберите файл", "", "Текстовые файлы (*.txt)");

    if (!filename.isEmpty()) {
        loadFromFile(filename);
    }
}

void MainWindow::loadFromFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл!");
        return;
    }

    clearCards();

    QTextStream in(&file);
    int lineNum = 1;
    int loadedCount = 0;

    RuP* ru = new RuP();
    if (ru->readFile(in, lineNum)) {
        cards_.append(ru);
        loadedCount++;
    } else {
        delete ru;
    }

    AmP* am = new AmP();
    if (am->readFile(in, lineNum)) {
        cards_.append(am);
        loadedCount++;
    } else {
        delete am;
    }

    file.close();

    if (cards_.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Не удалось загрузить данные!");
    } else {
        updateTable();
        QMessageBox::information(this, "Успех", QString("Загружено %1 записей").arg(cards_.size()));
    }
}

void MainWindow::updateTable() {
    table->setRowCount(cards_.size());

    for (int i = 0; i < cards_.size(); i++) {
        Card* c = cards_[i];

        RuP* ru = dynamic_cast<RuP*>(c);
        if (ru) {
            QString fullName = ru->getSurname_() + " " + ru->getName_();
            table->setItem(i, 0, new QTableWidgetItem(fullName));
            table->setItem(i, 1, new QTableWidgetItem(ru->getPatrnumic_().isEmpty() ? "-" : ru->getPatrnumic_()));
        } else {
            AmP* am = dynamic_cast<AmP*>(c);
            if (am) {
                QString fullName = am->getName_() + " " + am->getSurname_();
                table->setItem(i, 0, new QTableWidgetItem(fullName));
                table->setItem(i, 1, new QTableWidgetItem(am->getSecondName()));
            }
        }

        QString dateStr = QString::number(c->getDay_()).rightJustified(2, '0') + "." + QString::number(c->getMonth_()).rightJustified(2, '0') + "." + QString::number(c->getYear_());
        table->setItem(i, 2, new QTableWidgetItem(dateStr));
    }

    table->setColumnWidth(0, 250);
    table->setColumnWidth(1, 150);
    table->setColumnWidth(2, 120);
}

void MainWindow::onTableDoubleClicked(int row, int column) {
    Q_UNUSED(column);

    if (row < 0 || row >= cards_.size()) return;

    Card* c = cards_[row];

    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Карточка");
    dialog->setMinimumSize(400, 300);
    dialog->setModal(true);

    QVBoxLayout* layout = new QVBoxLayout(dialog);

    QLabel* titleLabel = new QLabel("<h2>ИНФОРМАЦИЯ</h2>", dialog);
    titleLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(titleLabel);

    QLabel* infoLabel = new QLabel(c->Craft(), dialog);
    infoLabel->setWordWrap(true);
    infoLabel->setStyleSheet("font-size: 12pt; padding: 10px;");
    layout->addWidget(infoLabel);

    QHBoxLayout* buttonLayout = new QHBoxLayout();

    QPushButton* cancelButton = new QPushButton("Отмена", dialog);
    cancelButton->setMinimumHeight(35);
    cancelButton->setStyleSheet("font-size: 12px; padding: 5px; background-color: #f44336; color: white; border-radius: 5px;");
    buttonLayout->addWidget(cancelButton);

    QPushButton* printButton = new QPushButton("Печать", dialog);
    printButton->setMinimumHeight(35);
    printButton->setStyleSheet("font-size: 12px; padding: 5px; background-color: #4CAF50; color: white; border-radius: 5px;");
    buttonLayout->addWidget(printButton);

    layout->addLayout(buttonLayout);

    connect(cancelButton, &QPushButton::clicked, dialog, &QDialog::accept);

    connect(printButton, &QPushButton::clicked, [this, row, dialog]() {
        if (row >= 0 && row < cards_.size()) {
            delete cards_[row];
            cards_.removeAt(row);
        }
        updateTable();
        dialog->accept();
    });

    dialog->exec();
    delete dialog;
}
