#pragma once
#include "List.h"
#include "Apartment.h"
class Flat
{
public:

	Flat();
	Flat(string name);
	void Print();
	~Flat();
	int GetCount();
	string GetName();

	List Iterator_rooms(bool(*action)(Apartment, int), const int rooms);
	List Iterator_space(bool(*action)(Apartment, float), const float space);

	List Iterator_str(bool(*action)(Apartment, string), const string smth);

	Flat& operator+(Apartment obj);
	Flat& operator-(Apartment obj);
	Flat& operator=(const Flat& obj);

private:
	string _name;
	int _count;
	List _list;

};
