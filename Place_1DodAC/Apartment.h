#pragma once

#include "Header.h"

class Apartment
{
	friend ostream& operator<<(std::ostream& out, const Apartment& object);
	friend istream& operator>>(std::istream& in, Apartment& object);
	
public:
	Apartment();//����������� ��� ���������
	Apartment(string address, int rooms, float space);//����������� � �����������
	Apartment(const Apartment& copy);//����������� ���������
	Apartment(string address);
	void SetAddress(string address);//����� ������� �������� ������
	void SetSpace(float space);//����� ������� ������� �����
	void SetRooms(int rooms);//����� ������� ����� ��������
	string GetAddress();//����� ��������� �������� ������
	string GetAddress(string newaddress, int size);//����� ��������� ������� ������
	int GetRooms();//����� ��������� ������� �����
	float GetSpace();//����� ��������� ����� ��������
	void InputAddress();//����� ������� ������ � ���������
	void InputRooms();//����� ������� ������� ����� � ���������
	void InputSpace();//����� ������� ����� � ���������

	bool operator==(Apartment obj);
	bool operator!=(Apartment obj);


	~Apartment();//����������
	void Print();//����� ������ �� �����
private:
	string _address;
	int _rooms;
	float _space;
	//������ �������� ��������� �������
	int checkCount(int count);
};
