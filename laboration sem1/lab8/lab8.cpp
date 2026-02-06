//#include <iostream>
//
//struct Node {
//    int data;
//    Node* next;
//};
//
//Node* MAKE(int value) {
//    Node* p = new Node;
//    p->data = value;
//    return p;
//}
//
//void ADD(Node* head, int value) {
//    Node* p = MAKE(value);
//    p->next = head->next;
//    head->next = p;
//}
//
//void DELETE(Node* head) {
//    Node* p = head;
//    while (p->next != nullptr) {
//        if (p->next->data % 2 == 1) {
//            Node* tmp = p->next;
//            p->next = p->next->next;
//            delete tmp;
//        }
//        else {
//            p = p->next;
//        }
//    }
//}
//
//void CLEAR(Node* head) {
//    Node* p = head;
//    while (p->next != nullptr) {
//        Node* tmp = p->next;
//        p->next = p->next->next;
//        delete tmp;
//    }
//}
//
//void DUBLICATE_EVEN(Node* head) {
//    Node* p = head->next;
//    while (p != nullptr) {
//        if (p->data % 2 == 0 ) {
//            ADD(p, p->data);
//            p = p->next->next;
//        }
//        p = p->next->next;
//    }
//}
//
//void PRINT(Node* head) {
//    Node* p = head->next;
//    while (p != nullptr) {
//        std::cout << p->data << std::endl;
//        p = p->next;
//    }
//}
//int main(){
//    Node head;
//    head.next = nullptr;
//    
//    ADD(&head, 1);
//    ADD(&head, 2);
//    ADD(&head, 3);
//    ADD(&head, 4);
//    
//    DELETE(&head);
//    PRINT(&head);
//    CLEAR(&head);
//}
#include <iostream>
#include <string>

using namespace std;

struct Season {
    string name;
    string month1;
    string month2;
    string month3;
    Season* next;
};

Season* head = nullptr;
int cntseason = 0;

void createSeasons() {
    Season* winter = new Season;
    winter->name = "Зима";
    winter->month1 = "Декабрь";
    winter->month2 = "Январь";
    winter->month3 = "Февраль";
    winter->next = nullptr;

    Season* spring = new Season;
    spring->name = "Весна";
    spring->month1 = "Март";
    spring->month2 = "Апрель";
    spring->month3 = "Май";
    spring->next = nullptr;

    Season* summer = new Season;
    summer->name = "Лето";
    summer->month1 = "Июнь";
    summer->month2 = "Июль";
    summer->month3 = "Август";
    summer->next = nullptr;

    Season* autumn = new Season;
    autumn->name = "Осень";
    autumn->month1 = "Сентябрь";
    autumn->month2 = "Октябрь";
    autumn->month3 = "Ноябрь";
    autumn->next = nullptr;

    head = winter;
    winter->next = spring;
    spring->next = summer;
    summer->next = autumn;

    cntseason = 4;
}

void printSeason() {
    system("cls");
    int season;
    cout << "Введите номер сезона для просмотра (1-4): ";
    cin >> season;
    if (season < 1 || season > cntseason) {
        cout << "Неверный номер сезона!\n";
        return;
    }
    Season* p = head;
    for (int i = 1; i < season; i++) {
        p = p->next;
    }

    cout << "Сезон: " << p->name << endl;
    cout << "Месяцы: [" << p->month1 << "," << p->month2 << "," << p->month3 << "]" << endl;
}
void swapMonths() {
    int Aseason, Bseason;
    int Amonth, Bmonth;
    cout << "\n Обменять месяцами местами \n";
    cout << "Введите номер первого сезона (1-4): ";
    cin >> Aseason;
    cout << "Введите номер месяца в первом сезоне (1-3): ";
    cin >> Amonth;
    cout << "Введите номер второго сезона (1-4): ";
    cin >> Bseason;
    cout << "Введите номер месяца во втором сезоне (1-3): ";
    cin >> Bmonth;
    if (Aseason < 1 || Aseason > cntseason ||
        Bseason < 1 || Bseason > cntseason ||
        Amonth < 1 || Amonth > 3 ||
        Bmonth < 1 || Bmonth > 3) {
        cout << "Неверные значения!\n";
        return;
    }
    Season* seasonA = head;
    for (int i = 1; i < Aseason; i++) {
        seasonA = seasonA->next;
    }
    Season* seasonB = head;
    for (int i = 1; i < Bseason; i++) {
        seasonB = seasonB->next;
    }
    string dotatime;
    switch (Amonth) {
    case 1:
        switch (Bmonth) {
        case 1:
            dotatime = seasonA->month1;
            seasonA->month1 = seasonB->month1;
            seasonB->month1 = dotatime;
            break;
        case 2:
            dotatime = seasonA->month1;
            seasonA->month1 = seasonB->month2;
            seasonB->month2 = dotatime;
            break;
        case 3:
            dotatime = seasonA->month1;
            seasonA->month1 = seasonB->month3;
            seasonB->month3 = dotatime;
            break;
        }
        break;

    case 2:
        switch (Bmonth) {
        case 1:
            dotatime = seasonA->month2;
            seasonA->month2 = seasonB->month1;
            seasonB->month1 = dotatime;
            break;
        case 2:
            dotatime = seasonA->month2;
            seasonA->month2 = seasonB->month2;
            seasonB->month2 = dotatime;
            break;
        case 3:
            dotatime = seasonA->month2;
            seasonA->month2 = seasonB->month3;
            seasonB->month3 = dotatime;
            break;
        }
        break;

    case 3:
        switch (Bmonth) {
        case 1:
            dotatime = seasonA->month3;
            seasonA->month3 = seasonB->month1;
            seasonB->month1 = dotatime;
            break;
        case 2:
            dotatime = seasonA->month3;
            seasonA->month3 = seasonB->month2;
            seasonB->month2 = dotatime;
            break;
        case 3:
            dotatime = seasonA->month3;
            seasonA->month3 = seasonB->month3;
            seasonB->month3 = dotatime;
            break;
        }
        break;
    }
    cout << "Месяцы успешно обменены!\n";
}

void printYear() {
    system("cls");
    cout << "Весь год начиная с зимы \n";
    Season* p = head;
    while (p) {
        cout << p->name << "[" << p->month1 << ", "
            << p->month2 << ", " << p->month3 << "] \n";
        p = p->next;
    }
    cout << endl;
}

int main() {
    std::setlocale(LC_ALL, "Russian");
    createSeasons();
    int a;
    bool z = true;

    while (z) {
        cout << "----------------------------------------------\n";
        cout << "1. Просмотреть один сезон\n";
        cout << "2. Обменять месяца местами\n";
        cout << "3. Вывести весь год (начиная с зимы)\n";
        cout << "4. Выход\n";
        cout << "Выбери действие: ";
        cin >> a;
        if (a == 1) {
            printSeason();
        }
        else if (a == 2) {
            swapMonths();
        }
        else if (a == 3) {
            printYear();
        }
        else if (a == 4) {
            z = false;
            cout << "Выход из программы...\n";
        }
        else {
            system("cls");
            cout << "Неверный выбор! Попробуйте снова.\n";
        }
    }
    return 0;
}