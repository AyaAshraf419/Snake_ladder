#pragma once
class enhancement
{                   
public:
    enhancement();                             // Default constructor
                  // fun to insert node in list
    void insert_30(int*);                   // fun to store values from 1 to 30 in linked-list
    int * insert_100();                  // fun to store values from 1 to 100 in linked-list    
    int search(int);                  // fun to search for a node in list and return pointer to this node
    void insert_ladder(int * arr, int c, int d);  // fun to insert snake from snake head to snake tail
    void insert_snake(int * arr, int c, int d); // fun to insert ladder from node to other one
               
   
    int  movement(int &);              // fun to move player from node to next
    int move2(int ,int  *arr);                  // fun to move player from node to next if there are snake or ladder
};
