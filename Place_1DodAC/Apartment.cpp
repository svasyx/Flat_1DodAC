#define _CRT_SECURE_NO_WARNINGS
#include "windows.h"
#include "apartment.h"
#include "iostream"
using namespace ::std;
#define DEBUG
//Конструктор без параметрів
Apartment::Apartment()
{
	_address = "";
	_rooms = 1;
	_space = 20;
#ifdef DEBUG
	std::cout << "\n#Викликався коснструктор без параметрів - " << this << std::endl;
#endif
}
//Конструктор з параметрами
Apartment::Apartment(string address, int rooms, float space)
{

	_address =  address;
	if (checkCount(rooms))
		_rooms = rooms;
	else
		_rooms = 1;
	if (checkCount(space))
		_space = space;
	else
		_space = 1.0;
#ifdef DEBUG
	std::cout << "\n#Викликався коснструктор з параметрами - " << this << std::endl;
#endif
}

//Конструктор копіювання
Apartment::Apartment(const Apartment& copy)
{
	string newAddress;
	
		newAddress = copy._address;
		_address = newAddress;
		_rooms = copy._rooms;
		_space = copy._space;

	
}
Apartment::Apartment(string address)
{

	_address = address;
}

//Метод задання значення адреси
void Apartment::SetAddress(string address)
{

	string newAddress;
	newAddress =  address;
		this->_address = newAddress;
	
}

//Метод задання кількості кімнат
void Apartment::SetRooms(int rooms)
{
	if (checkCount(rooms))
		_rooms = rooms;
	else
	{
#ifdef DEBUG
		std::cout << "\nНекорректний ввод! " << this << "\n" << std::endl;
#endif
	}
}
//Метод задання площі квартири
void Apartment::SetSpace(float space)
{
	if (checkCount(space))
		_space = space;
	else
	{
#ifdef DEBUG
		std::cout << "\nНекорректний ввод! " << this << "\n" << std::endl;
#endif
	}
}
//Метод отримання значення адреси
string Apartment::GetAddress()
{
	
	string address;
	address = _address;
	
	return address;
}
//Метод отримання значеня адреси (спосіб №2)
string Apartment::GetAddress(string newaddress, int size)
{
	newaddress = _address;
	return newaddress;
}
//Метод отримання кількості кімнат
int Apartment::GetRooms()
{
	return _rooms;
}
//Метод отримання площі квартири
float Apartment::GetSpace()
{
	return _space;
}
//Метод задання адреси з клавіатури
void Apartment::InputAddress()
{
	string address;
	do {
		cin >> address;
		if (address[0] == '\n')
		{
			std::cout << "\nТекст не повинен бути пустим, спробуйте ще раз \n" << std::endl;
		}
	} while (address[0] == '\n');
	
	SetAddress(address);
}
//Метод задання кількості кімнат з клавіатури
void Apartment::InputRooms()
{
	int rooms;
	while (scanf_s("%d", &rooms) != 1)
	{
		printf("Введене значення не є допустимим, спробуйте ще раз: ");
		while ((getchar()) != '\n');
	}
	SetRooms(rooms);
}
//Метод задання площі з клавіатури
void Apartment::InputSpace()
{
	float space;
	while (scanf_s("%f", &space) != 1)
	{
		printf("Введене значення не є допустимим, спробуйте ще раз: ");
		while ((getchar()) != '\n');
	}
	SetSpace(space);
}
//Деструктор
Apartment::~Apartment()
{
	_address = "";
	

}
//Метод виводу на екран
void Apartment::Print()
{
#ifdef DEBUG
	std::cout << "Адреса:" << this->_address << std::endl;
	std::cout << "кількість кімнат:" << this->_rooms << std::endl;
	std::cout << "площа квартири: " << this->_space << " метрів квадратних" << std::endl;
#endif
}
//Методи перевірки отриманих значень
int Apartment::checkCount(int count)
{
	if (count <= 0)
	{
#ifdef DEBUG
		std::cout << "Дані введено не правильно" << std::endl;
#endif
		return 0;
	}
	else
	{
		return 1;
	}
}


bool Apartment::operator==(Apartment obj)
{

	if (_address == obj._address && _rooms == obj._rooms && _space == obj._space)
	{
		return true;

	}
	else
	{
		return false;
	}

}
bool Apartment::operator!=(Apartment obj)
{
	if (_address != obj._address || _rooms != obj._rooms || _space != obj._space)
	{
		return true;

	}
	else
	{
		return false;
	}
}
