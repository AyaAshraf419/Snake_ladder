#include"Node.h"
Node::Node()
{
    this->data = 0;
    this->next = NULL;
    this->Up_Down = NULL;
    this->state = 0;
}
Node::Node(int data)
{
    this->data = data;
    this->next = NULL;
    this->Up_Down = NULL;
    this->state = 0;
}