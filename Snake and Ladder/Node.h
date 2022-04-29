//Node of Linked List
#pragma once
#include<stdlib.h>
class Node  
{
public:
    int data;       // store data of node
    Node* next;     // pomter to next node in list
    Node* Up_Down;  // pointer to NULL if no snake or ladder
                    //    ~    ~  distination node if there is snake or ladder
    int state;      // variable has 0 if no snake or ladder
                    //     ~    ~   1 if there is ladder
                    //     ~    ~  -1 if there is snake
    Node();         // Default constructor
    Node(int);     // Parameterised Constructor
};