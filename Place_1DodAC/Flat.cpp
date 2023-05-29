#include "Flat.h"

Flat::Flat()
{
    _name = "\0";
    _count = 0;

}
Flat::Flat(string name)
{
    _name = name;

}

void Flat::Print()
{

    for (int i = 0; i < _list.GetSize(); i++)
    {
        cout << _list[i] << endl;
    }

}

Flat::~Flat()
{
    _list.Delete_list();
}


int Flat::GetCount()
{
    return _count;
}

string Flat::GetName()
{
    return _name;
}



Flat& Flat::operator+(Apartment obj)
{
    _list + obj;
    _count++;
    return *this;
}

Flat& Flat::operator=(const Flat& obj)
{
    _list = obj._list;
    this->_count = obj._count;
    return *this;
}

Flat& Flat::operator-(Apartment obj)
{
    _list - obj;
    _count--;
    return *this;
}

List Flat::Iterator_rooms(bool(*action)(Apartment, int), const int rooms)
{
    List obj = _list.Iterator_rooms(action, rooms);

    return obj;
}
List Flat::Iterator_space(bool(*action)(Apartment, float), const float space)
{
    List obj = _list.Iterator_space(action, space);

    return obj;
}


List Flat::Iterator_str(bool(*action)(Apartment, string), const string smth)
{
    List obj = _list.Iterator_str(action, smth);

    return obj;
}
