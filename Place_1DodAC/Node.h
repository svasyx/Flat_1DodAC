
#pragma once
#include "Header.h"
#include "Apartment.h"
class Node
{
	friend class List;
public:
	Apartment Get_data();

private:
	Apartment _data;
	Node* _next;
	Node(string address, int rooms, float space);
};
