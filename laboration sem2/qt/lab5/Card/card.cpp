#include "card.h"
#include <QDebug>

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

QString RuP::Craft() const {
    QString result = "ПРОПУСК\n\n";
    result += "Фамилия: " + surname_ + "\n";
    result += "Имя: " + name_ + "\n";
    result += "Отчество: " + (patronymic_.isEmpty() ? "-" : patronymic_) + "\n";
    result += "Дата рождения: " +
              QString::number(day_).rightJustified(2, '0') + "." +
              QString::number(month_).rightJustified(2, '0') + "." +
              QString::number(year_);
    return result;
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

QString AmP::Craft() const {
    QString result = "ПРОПУСК\n\n";
    result += "Имя: " + name_ + "\n";
    result += "Второе имя: " + secondName_ + "\n";
    result += "Фамилия: " + surname_ + "\n";
    result += "Дата рождения: " +
              QString::number(day_).rightJustified(2, '0') + "." +
              QString::number(month_).rightJustified(2, '0') + "." +
              QString::number(year_);
    return result;
}
