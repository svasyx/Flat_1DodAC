#pragma once
#include "Node.h"

class List
{
public:
    List();
    List(const Apartment object);
    List(const List& list);

    int GetSize()const;

    void Delete_list();

    List Iterator_space(bool(*action)(Apartment, float), const float rooms);
    List Iterator_rooms(bool(*action)(Apartment, int), const int rooms);
    List Iterator_str(bool(*action)(Apartment, string), const string address);

    Apartment& operator[](const int index);
    List& operator+(const Apartment object);
    List& operator-(const Apartment object);
    List& operator=(const List& list);
    bool operator==(const List& list);
    ~List();
private:
    void Add(string address, int rooms, float space);
    Node* _head;
};

