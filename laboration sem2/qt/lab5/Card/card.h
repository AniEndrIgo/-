#ifndef CARD_H
#define CARD_H
#include <QString>
#include <QTextStream>
class Card{
public:
    Card() : code_(0), day_(0), month_(0), year_(0){}
    virtual ~Card(){}
    virtual QString Craft() const = 0;

    int getCode_() const { return code_; }
    QString getSurname_() const { return surname_; }
    QString getName_() const { return name_; }
    int getDay_() const { return day_; }
    int getMonth_() const { return month_; }
    int getYear_() const { return year_; }

protected:
    int code_;
    QString surname_;
    QString name_;
    int day_, month_, year_;
};

class RuP : public Card{
public:
    bool readFile(QTextStream& in, int& lineNum);
    QString Craft() const override;
    QString getPatrnumic_() const { return patronymic_; }

private:
    QString patronymic_;
};

class AmP : public Card{
public:
    bool readFile(QTextStream& in, int& lineNum);
    QString Craft() const override;
    QString getSecondName() const { return secondName_; }

private:
    QString secondName_;
};

#endif
