#ifndef CARDWINDOW_H
#define CARDWINDOW_H

#include <QDialog>
#include "card.h"

namespace Ui {
class CardWindow;
}

class CardWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CardWindow(Card* card, QWidget *parent = nullptr);
    ~CardWindow();
    void fillWindow(Card* card);

private:
    Ui::CardWindow *ui;
    Card* card_;

private slots:
    void on_printButton_clicked();
    void on_cancelButton_clicked();
};



#endif // CARDWINDOW_H
