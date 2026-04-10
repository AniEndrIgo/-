#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVector>
#include "card.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    QTableWidget* table;
    QPushButton* loadButton;
    QVector<Card*> cards_;

    void setupUI();
    void updateTable();
    void clearCards();

private slots:
    void onLoadButtonClicked();
    void onTableDoubleClicked(int row, int column);
    void loadFromFile(const QString& filename);

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
};

#endif
