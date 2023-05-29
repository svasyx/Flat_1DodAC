#define _CRT_SECURE_NO_WARNINGS
#include "windows.h"
#include "apartment.h"
#include "iostream"
using namespace ::std;
#define DEBUG
//����������� ��� ���������
Apartment::Apartment()
{
	_address = "";
	_rooms = 1;
	_space = 20;
#ifdef DEBUG
	std::cout << "\n#���������� ������������ ��� ��������� - " << this << std::endl;
#endif
}
//����������� � �����������
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
	std::cout << "\n#���������� ������������ � ����������� - " << this << std::endl;
#endif
}

//����������� ���������
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

//����� ������� �������� ������
void Apartment::SetAddress(string address)
{

	string newAddress;
	newAddress =  address;
		this->_address = newAddress;
	
}

//����� ������� ������� �����
void Apartment::SetRooms(int rooms)
{
	if (checkCount(rooms))
		_rooms = rooms;
	else
	{
#ifdef DEBUG
		std::cout << "\n������������ ����! " << this << "\n" << std::endl;
#endif
	}
}
//����� ������� ����� ��������
void Apartment::SetSpace(float space)
{
	if (checkCount(space))
		_space = space;
	else
	{
#ifdef DEBUG
		std::cout << "\n������������ ����! " << this << "\n" << std::endl;
#endif
	}
}
//����� ��������� �������� ������
string Apartment::GetAddress()
{
	
	string address;
	address = _address;
	
	return address;
}
//����� ��������� ������� ������ (����� �2)
string Apartment::GetAddress(string newaddress, int size)
{
	newaddress = _address;
	return newaddress;
}
//����� ��������� ������� �����
int Apartment::GetRooms()
{
	return _rooms;
}
//����� ��������� ����� ��������
float Apartment::GetSpace()
{
	return _space;
}
//����� ������� ������ � ���������
void Apartment::InputAddress()
{
	string address;
	do {
		cin >> address;
		if (address[0] == '\n')
		{
			std::cout << "\n����� �� ������� ���� ������, ��������� �� ��� \n" << std::endl;
		}
	} while (address[0] == '\n');
	
	SetAddress(address);
}
//����� ������� ������� ����� � ���������
void Apartment::InputRooms()
{
	int rooms;
	while (scanf_s("%d", &rooms) != 1)
	{
		printf("������� �������� �� � ����������, ��������� �� ���: ");
		while ((getchar()) != '\n');
	}
	SetRooms(rooms);
}
//����� ������� ����� � ���������
void Apartment::InputSpace()
{
	float space;
	while (scanf_s("%f", &space) != 1)
	{
		printf("������� �������� �� � ����������, ��������� �� ���: ");
		while ((getchar()) != '\n');
	}
	SetSpace(space);
}
//����������
Apartment::~Apartment()
{
	_address = "";
	

}
//����� ������ �� �����
void Apartment::Print()
{
#ifdef DEBUG
	std::cout << "������:" << this->_address << std::endl;
	std::cout << "������� �����:" << this->_rooms << std::endl;
	std::cout << "����� ��������: " << this->_space << " ����� ����������" << std::endl;
#endif
}
//������ �������� ��������� �������
int Apartment::checkCount(int count)
{
	if (count <= 0)
	{
#ifdef DEBUG
		std::cout << "��� ������� �� ���������" << std::endl;
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
