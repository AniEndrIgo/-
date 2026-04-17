#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QVector>
#include "card.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QVector<Card*> cards_;

    void updateTable();
    void clearCards();
    void loadFromFile(const QString& filename);
private slots:
    void on_pushButton_clicked();
    void on_Table_cellDoubleClicked(int row, int column);
};

#endif
