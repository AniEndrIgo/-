#include "card.h"
#include <QDebug>
#include "cardwindow.h"
#include <QApplication>
#include "ui_cardwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

bool RuP::readFile(QTextStream& in, int& lineNum) {
    QString line = in.readLine();
    if (line.trimmed().isEmpty()) {
        lineNum++;
        return false;
    }

    QStringList words = line.split(',');
    if (words.size() < 7) {
        lineNum++;
        return false;
    }

    for (int i = 0; i < words.size(); i++) {
        words[i] = words[i].trimmed();
    }

    code_ = words[0].toInt();
    surname_ = words[1];
    name_ = words[2];
    patronymic_ = words[3];
    day_ = words[4].toInt();
    month_ = words[5].toInt();
    year_ = words[6].toInt();

    lineNum++;
    return true;
}

int RuP::Craft() const {
    CardWindow* window = new CardWindow(const_cast<RuP*>(this), nullptr);
    window->setAttribute(Qt::WA_DeleteOnClose);
    window->fillWindow(const_cast<RuP*>(this));

    int result = window->exec();  // ПОЛУЧАЕМ РЕЗУЛЬТАТ
    delete window;  // УДАЛЯЕМ ОКНО (setAttribute не нужен)

    return result;  // ВОЗВРАЩАЕМ 1 ЕСЛИ ПЕЧАТЬ, 0 ЕСЛИ ОТМЕНА
}

bool AmP::readFile(QTextStream& in, int& lineNum) {
    QString line = in.readLine();

    if (line.trimmed().isEmpty()) {
        lineNum++;
        return false;
    }

    QStringList words = line.split(',');
    if (words.size() < 7) {
        lineNum++;
        return false;
    }

    for (int i = 0; i < words.size(); i++) {
        words[i] = words[i].trimmed();
    }

    code_ = words[0].toInt();
    name_ = words[1];
    secondName_ = words[2];
    surname_ = words[3];
    month_ = words[4].toInt();
    day_ = words[5].toInt();
    year_ = words[6].toInt();

    lineNum++;
    return true;
}

int AmP::Craft() const {
    CardWindow* window = new CardWindow(const_cast<AmP*>(this), nullptr);
    window->fillWindow(const_cast<AmP*>(this));

    int result = window->exec();
    delete window;
    return result;
}
