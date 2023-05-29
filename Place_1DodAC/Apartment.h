#pragma once

#include "Header.h"

class Apartment
{
	friend ostream& operator<<(std::ostream& out, const Apartment& object);
	friend istream& operator>>(std::istream& in, Apartment& object);
	
public:
	Apartment();//Конструктор без параметрів
	Apartment(string address, int rooms, float space);//Конструктор з параметрами
	Apartment(const Apartment& copy);//Конструктор копіювання
	Apartment(string address);
	void SetAddress(string address);//Метод задання значення адреси
	void SetSpace(float space);//Метод задання кількості кімнат
	void SetRooms(int rooms);//Метод задання площі квартири
	string GetAddress();//Метод отримання значення адреси
	string GetAddress(string newaddress, int size);//Метод отримання значеня адреси
	int GetRooms();//Метод отримання кількості кімнат
	float GetSpace();//Метод отримання площі квартири
	void InputAddress();//Метод задання адреси з клавіатури
	void InputRooms();//Метод задання кількості кімнат з клавіатури
	void InputSpace();//Метод задання площі з клавіатури

	bool operator==(Apartment obj);
	bool operator!=(Apartment obj);


	~Apartment();//Деструктор
	void Print();//Метод виводу на екран
private:
	string _address;
	int _rooms;
	float _space;
	//Методи перевірки отриманих значень
	int checkCount(int count);
};
