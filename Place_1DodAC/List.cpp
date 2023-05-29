#include "List.h"

#include "Header.h"

List::List()
{
    _head = nullptr;
}

List::List(Apartment obj)
{
    _head = nullptr;
    Add(obj.GetAddress(), obj.GetRooms(), obj.GetSpace());
}

List::~List()
{
    while (GetSize() != 0)
    {
        Node* cur = _head;
        _head = _head->_next;
        delete cur;
    }
}

List::List(const List& list)
{
    Node* tmp = list._head;
    for (int i = 0; i < list.GetSize(); i++)
    {
        Add(tmp->_data.GetAddress(), tmp->_data.GetRooms(), tmp->_data.GetSpace());
        tmp = tmp->_next;
    }
}

void List::Add(string address, int rooms, float space)
{
    if (_head == nullptr)
    {
        _head = new Node(address, rooms, space);
    }
    else
    {
        Node* cur = this->_head;
        while (cur->_next != nullptr)
        {
            cur = cur->_next;
        }
        cur->_next = new Node(address, rooms, space);
    }
}

void List::Delete_list()
{
    while (GetSize() != 0)
    {
        Node* cur = _head;
        _head = _head->_next;
        delete cur;
    }
}



List List::Iterator_rooms(bool(*action)(Apartment, int), const int rooms)
{
    List result;
    Node* tmp = _head;
    while (tmp != nullptr)
    {
        if (action(tmp->Get_data(), rooms) == 1)
        {
            result + tmp->Get_data();
        }
        tmp = tmp->_next;
    }
    return result;
}

List List::Iterator_space(bool(*action)(Apartment, float), const float space)
{
    List result;
    Node* tmp = _head;
    while (tmp != nullptr)
    {
        if (action(tmp->Get_data(), space) == 1)
        {
            result + tmp->Get_data();
        }
        tmp = tmp->_next;
    }
    return result;
}


List List::Iterator_str(bool(*action)(Apartment, string), const string str)
{
    List result;
    Node* tmp = _head;
    while (tmp != nullptr)
    {
        if (action(tmp->Get_data(), str) == 1)
        {
            result + tmp->Get_data();
        }
        tmp = tmp->_next;
    }
    return result;
}

int List::GetSize() const
{
    Node* tmp = this->_head;
    int counter = 0;
    if (this->_head == nullptr)
    {
        return 0;
    }
    else
    {
        while (tmp != nullptr)
        {
            counter++;
            tmp = tmp->_next;
        }
    }
    return counter;
}

Apartment& List::operator[](const int index)
{
    int counter = 0;
    Node* cur = this->_head;
    if (index >= GetSize() || GetSize() == 0)
    {
        exit(1);
    }
    while (cur != nullptr)
    {
        if (counter == index)
        {
            return cur->_data;
        }
        cur = cur->_next;
        counter++;
    }
}

List& List::operator+(Apartment object)
{
    Add(object.GetAddress(), object.GetRooms(), object.GetSpace());
    return *this;
}

List& List::operator-(const Apartment object)
{
    Node* cur = this->_head;
    Node* tmp = nullptr;
    if (GetSize() == 0)
    {
        exit(1);
    }
    if (cur->_data == object)
    {
        Node* cur = _head;
        _head = _head->_next;
        delete cur;
        return *this;
    }
    while (cur->_next != nullptr)
    {
        if (cur->_next->_data == object)
        {
            tmp = cur->_next->_next;
            delete cur->_next;
            cur->_next = tmp;
            return *this;
        }
        cur = cur->_next;
    }
}

List& List::operator=(const List& list)
{
    if (this == &list)
    {
        return *this;
    }
    while (GetSize() != 0)
    {
        Node* cur = _head;
        _head = _head->_next;
        delete cur;
    }
    this->_head = nullptr;
    Node* tmp = list._head;
    for (int i = 0; i < list.GetSize(); i++)
    {
        Add(tmp->_data.GetAddress(), tmp->_data.GetRooms(), tmp->_data.GetSpace());
        tmp = tmp->_next;
    }
    return *this;
}

bool List::operator==(const List& list)
{
    int counter = 0;
    Node* cur = this->_head;
    Node* temp = list._head;
    if (this->GetSize() < list.GetSize() || this->GetSize() > list.GetSize())
    {
        return 1;
    }
    while (cur != nullptr)
    {
        if (cur->_data == temp->_data)
        {
            counter++;
        }
        temp = temp->_next;
        cur = cur->_next;
    }
    if (counter != this->GetSize())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

