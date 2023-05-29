#include "Apartment.h"
#include "List.h"
#include "Node.h"
#include "Flat.h"

#include "Header.h"

ostream& operator<<(std::ostream& out, const Apartment& object)
{
    return out << object._address << " " << object._rooms << " " << object._space << endl;
}
istream& operator>>(std::istream& in, Apartment& object)
{
    in >> object._address >> object._rooms >> object._space;
    if (!in)
    {
        object = Apartment();
    }
    return in;
}

bool action_space(Apartment object, float space)
{
    if (object.GetSpace() == space)
    {
        return 1;
    }
    return 0;
}

bool action_space1(Apartment object, float space)
{
    if (object.GetSpace() >= space)
    {
        return 1;
    }
    return 0;
}

bool action_rooms(Apartment object, int rooms)
{
    if (object.GetRooms() == rooms)
    {
        return 1;
    }
    return 0;
}

bool action_address(Apartment object, string name)
{
    if (object.GetAddress() == name)
    {
        return 1;
    }
    return 0;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int option = 0;
    float space = 0;
    int check = 0;
    int rooms = 0;
    string name;
    string address;
    Apartment c;
    Flat fl("flat1");

    do {
        cout << "1.Створити об'єкт класу" << endl;
        cout << "2.Показати загальну кількість квартир" << endl;
        cout << "3.Додати квартиру до бази даних" << endl;
        cout << "4.Видалити квартиру(адреса, к-сть кімнат, площа)" << endl;
        cout << "5.Вивести дані" << endl;
        cout << "6.Скопіювати дані та вивести їх" << endl;
        cout << "7.Вивести кількість квартир із заданою площею" << endl;
        cout << "8.Вивести квартиру із заданою адресою" << endl;
        cout << "9.Вивести квартиру із заданою к-стю кімнат" << endl;
        cout << "10.Завершити роботу програми" << endl;
        do {
            cin >> option;
            if (option <= 0 || option >= 11) {
                cout << "Значення невірне, введіть ще раз: ";
            }
        } while (option <= 0 || option >= 11);
        cout << endl;
        switch (option)
        {
        case 1:
            cout << "Введіть дані(адреса, к-сть кімнат, площа) через пробіл: ";
            cin >> c;
            fl + c;
            cout << "Створено!" << endl << endl;
            break;
        case 2:
            cout << "Загальна кількість кімнат:" << fl.GetCount() << endl << endl;
            break;
        case 3:
            cout << "Введіть квартиру, яку додати(адреса, к-сть кімнат, площа) через пробіл: ";
            cin >> c;
            fl + c;
            cout << "Додано!" << endl;
            break;
        case 4:
            cout << "Введіть квартиру, яку видалити(адреса, к-сть кімнат, площа) через пробіл: ";
            cin >> c;
            fl - c;
            cout << "Видалено!" << endl;
            break;
        case 5:
            cout << "Кооператив "<< fl.GetName() << '\n'  << endl;
            cout << endl << "К-сть квартир: " << fl.GetCount() << endl;
            fl.Print();

            cout << endl;
            break;
        case 7:
        {
            cout << "Введіть space: " << endl;
            cin >> space;
            List tmp = fl.Iterator_space(action_space, space);

            for (int i = 0; i < tmp.GetSize(); i++)
            {
                cout << tmp[i] << endl;
            }

            break;
        }
        case 8:
        {
            cout << "Введіть adress: " << endl;
            cin >> address;
            List tmp = fl.Iterator_str(action_address, address);

            for (int i = 0; i < tmp.GetSize(); i++)
            {
                cout << tmp[i] << endl;
            }
            break;
        }
        case 9:
        {
            cout << "Введіть к-сть кімнат: " << endl;
            cin >> rooms;
            List tmp = fl.Iterator_rooms(action_rooms, rooms);
            for (int i = 0; i < tmp.GetSize(); i++)
            {
                cout << tmp[i] << endl;
            }
            break;
        }
        }
        if (option == 6)
        {
            Flat fl_tmp(fl);
            cout << "flat: " << endl;
            fl_tmp.Print();
            cout << endl;
        }
    } while (option != 10);

    return 0;
}

