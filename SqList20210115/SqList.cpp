#include <iostream>
#include <malloc.h>
#include "sq_list.h"
using std:: cout;
using std:: cin;
using std:: endl;
static bool AppendSpace(SqList *sq)
{

    // 将顺序表扩容为原来的2倍
    ElemType *new_space = (ElemType *)malloc(sizeof(ElemType) * sq -> space_size * 2 );
    if (new_space == NULL) return false;

    for (int i = 0; i < sq->space_size; ++i)
    {
        new_space[i] = sq->elems[i];
    }

    // 释放原空间
    free(sq->elems);
    // 将new_space的值赋给sq->elems
    sq->elems = new_space;
    new_space = NULL;
    sq->space_size *= 2;
    return true;
}

// 初始化顺序表函数
bool InitSqList(SqList *sq, int size)
{
    // 判定顺序表是否为空
    if (sq == NULL || size <= 0)
    {
        return false;
    }
    // 开辟指定大小的空间
    sq->elems = (ElemType *)malloc(sizeof(ElemType) * size);
    // 判定空间开辟是否成功
    if (sq->elems == NULL) return false;
    sq->space_size = size;
    sq->elem_num = 0;
    return true;
}

// 插入数据函数
bool InsertSqList(SqList *sq, ElemType val, int pos)
{
    // 判定指针是否为空
    if (sq == NULL || pos < 0 || pos > sq->elem_num)
    {
        return false;
    }
    // 判定指针是否需要扩容, 即顺序表是否已满
    if (sq->space_size == sq->elem_num)
    {
        if(!AppendSpace(sq)) return false;
    }

    int end = sq->elem_num;

    while (end > pos)
    {
        sq->elems[end] = sq->elems[end - 1];
        --end;
    }

    sq->elems[pos] = val;
    ++sq->elem_num;
    return true;
}

// 删除顺序表数据
bool DeleteSqList(SqList *sq, int pos)
{
    // 判定指针是否为空
    if (sq == NULL || pos < 0 || pos >= sq->elem_num)
    {
        return false;
    }

    // 将顺序表中pos位置开始的所有数据向后移一位.
    for (int i = pos; i < sq->elem_num - 1; i++)
    {
        sq->elems[i] = sq->elems[i + 1];
    }
    --sq->elem_num;
    return true;
}

// 销毁数据函数
bool DestorySqList(SqList *sq)
{
    if (sq == NULL) return false;

    free(sq->elems);
    sq->elems = NULL;
    sq->space_size = sq->elem_num = 0;
    return true;
}

// 删除指定的val
bool DeleteVal(SqList *sq, ElemType val)
{
    // 判定指针是否为空
    if (sq == NULL) return false;

    for (int i = 0; i < sq->elem_num; ++i)
    {
        if (sq->elems[i] == val)
        {
            DeleteSqList(sq, i);
            --i;
        }
    }
    return true;
}

// 遍历打印顺序表的数据
void DisplaySqList(SqList *sq)
{
    
    if (sq == NULL) return;
    cout << "elems: ";
    for (int i = 0; i < sq->elem_num; ++i)
    {
        cout << sq->elems[i] << " ";
    }
    cout << endl;
}