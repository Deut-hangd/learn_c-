#include <iostream>
#include "sq_list.h"
using std:: cout;
using std:: cin;
using std:: endl;
int main()
{
    SqList list;
    InitSqList(&list, 10);
    InsertSqList(&list, 2, 0);
    InsertSqList(&list, 2, 1);
    InsertSqList(&list, 2, 2);
    DisplaySqList(&list);
    DeleteSqList(&list, 2);
    DeleteVal(&list, 2);
    DisplaySqList(&list);
    return 0;
}