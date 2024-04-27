//ДЛЯ КОРРЕКТНОЙ РВАБОТЫ ИСПОЛЬЗУЙТЕ АНГЛИЙСКИЕ БУКВЫ


// Главная функция программы
#include "Tree.h"
int main() {
    setlocale(LC_ALL, "Russian");
    BinaryTree tree;
    int choice;

    do {
        cout << "Меню:" << endl;
        cout << "1. Добавить заявку" << endl;
        cout << "2. Удалить заявку" << endl;
        cout << "3. Вывести заявки по номеру рейса и дате вылета" << endl;
        cout << "4. Вывести все заявки" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие : ";
            cin >> choice;

        switch (choice) {
        case 1: {
            Ticket newTicket;
            cout << "Введите пункт назначения: ";
            cin >> newTicket.destination;
            cout << "Введите номер рейса: ";
            cin >> newTicket.flightNumber;
            cout << "Введите фамилию и инициалы пассажира: ";
            cin >> newTicket.passengerName;
            cout << "Введите желаемую дату вылета: ";
            cin >> newTicket.departureDate;
            tree.insert(newTicket);
            break;
        }
        case 2: {
            int flightNumberToDelete;
            string departureDateToDelete;
            cout << "Введите номер рейса для удаления: ";
            cin >> flightNumberToDelete;
            cout << "Введите дату вылета для удаления: ";
            cin >> departureDateToDelete;
            tree.deleteByFlightNumberAndDate(flightNumberToDelete, departureDateToDelete);
            break;
        }
        case 3: {
            int flightNumberToFind;
            string departureDateToFind;
            cout << "Введите номер рейса для поиска: ";
            cin >> flightNumberToFind;
            cout << "Введите дату вылета для поиска: ";
            cin >> departureDateToFind;
            tree.printByFlightNumberAndDate(flightNumberToFind, departureDateToFind);
            break;
        }
        case 4: {
            tree.printAll();
            break;
        }
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
