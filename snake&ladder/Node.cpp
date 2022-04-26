#include"Node.h"
// Default constructor
Node::Node()
{
    this->data = 0;
    this->next = NULL;
    this->Up_Down = NULL;
    this->state = 0;
}
// Parameterised Constructor
Node::Node(int data)
{
    this->data = data;
    this->next = NULL;
    this->Up_Down = NULL;
    this->state = 0;
}