
#include "Node.h"

Apartment Node::Get_data()
{
    return _data;
}



Node::Node(string address, int rooms, float space) :_data(address, rooms, space)
{
    cout <<  _data.GetAddress();
    this->_next = _next;
}
