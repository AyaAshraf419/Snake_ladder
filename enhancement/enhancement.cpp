#include"enhancement .h"
enhancement::enhancement()
{
}// Default constructor
void enhancement::insert_30(int*arry)
{
    for (int i = 1; i <=30; i++)
        arry[i] = i;
    insert_ladder(arry, 11, 26);
    insert_ladder(arry,3, (22));
    insert_ladder(arry,5, 8);
   // insert_ladder(arry,(10), (26));
    insert_ladder(arry,(20), (29));
    insert_snake(arry,(27), (1));
    insert_snake(arry,(21), (9));
    insert_snake(arry,(17), (4));
    insert_snake(arry,(19), (7));
}// fun to store values from 1 to 30 in linked-list
int * enhancement::insert_100() 
{
    int arry[100];
    for(int i=0;i<100;i++)
       arry[i] = i;
    insert_ladder(arry, 2, 22);
    insert_ladder(arry, (8), (29));
    insert_ladder(arry, 13,77);
    insert_ladder(arry, (32), (51));
    insert_ladder(arry, (63), (82));
    insert_ladder(arry, (73), (90));

    insert_snake(arry, (39), (20));
    insert_snake(arry, (49), (16));
    insert_snake(arry, (80), (78));
    insert_snake(arry, (94), (36));
    insert_snake(arry, (91), (52));
    return arry;
}
void enhancement::insert_ladder(int * arr, int c, int d)
{
    *(arr + c) = d;
}
void enhancement::insert_snake(int  *arr, int c, int d)
{
*   ( arr +c) = d;
}
int enhancement::movement(int & f)
{
    if (f != 30)
    {
        ++f;
        return f;
       
    }
    
}
int enhancement::move2(int   f, int *arr)
{
    return *(arr+f);
}
// fun to store values from 1 to 100 in linked-list   
// fun to search for a node in list and return pointer to this node
   // fun to insert snake from snake head to snake tail
// fun to insert ladder from node to other one



