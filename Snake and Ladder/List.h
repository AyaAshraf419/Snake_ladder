#pragma once
#include<iostream>
#include<stdlib.h>
#include"Node.h"
class List
{
private:
    Node* head;                         // head pointer of LinkedList
public:
    List();                             // Default constructor
    void insertNode(int);               // fun to insert node in list
    void insert_30();                   // fun to store values from 1 to 30 in linked-list
    void insert_100();                  // fun to store values from 1 to 100 in linked-list    
    Node* search(int);                  // fun to search for a node in list and return pointer to this node
    void insert_snake(Node*, Node*);    // fun to insert snake from snake head to snake tail
    void insert_ladder(Node*, Node*);   // fun to insert ladder from node to other one
    void Display(Node*);                // fun to display linked-list contents
    Node* Get_Head();                   // fun to return head of linked-list
    int  movement(Node**);              // fun to move player from node to next
    int move2(Node**);                  // fun to move player from node to next if there are snake or ladder
};