#include "sq_list.h"
#include <iostream>
#include <malloc.h>
using std:: cout;
using std:: cin;
using std:: endl;
static bool AppendSpace(SqList *sq)
{

    // 空间不足扩容2倍
    ElemType *new_space = (ElemType *)malloc(sizeof(ElemType) * sq -> space_size * 2 );
    if (new_space == NULL) return false;

    for (int i = 0; i < sq->space_size; ++i)
    {
        new_space[i] = sq->elems[i];
    }

    // 释放elems的空间
    free(sq->elems);
    // 将新的空间赋值给sq->elems
    sq->elems = new_space;
    new_space = NULL;
    sq->space_size *= 2;
    return true;
}

// 初始化函数
bool InitSqList(SqList *sq, int size)
{
    // 判断指针是否为空
    if (sq == NULL || size <= 0)
    {
        return false;
    }
    // 开辟空间
    sq->elems = (ElemType *)malloc(sizeof(ElemType) * size);
    // 判定空间开辟是否成功
    if (sq->elems == NULL) return false;
    sq->space_size = 0;
    sq->elem_num = 0;
    return true;
}

// 插入数据函数
bool InsertSqList(SqList *sq, ElemType val, int pos)
{
    // 判断指针是否为空
    if (sq == NULL || pos < 0 || pos > sq->elem_num)
    {
        return false;
    }
    // 空间不足需要扩容
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

// 删除数据函数
bool DeleteSqList(SqList *sq, int pos)
{
    // 判断指针是否为空
    if (sq == NULL || pos < 0 || pos >= sq->elem_num)
    {
        return false;
    }

    // 删除指定位置的数据
    // 即通过将从当前位置开始往后的所有数据向前移一位
    for (int i = pos; i < sq->elem_num - 1; i++)
    {
        sq->elems[i] = sq->elems[i + 1];
    }
    --sq->elem_num;
    return true;
}

// 销毁函数
bool DestorySqList(SqList *sq)
{
    if (sq == NULL) return false;

    free(sq->elems);
    sq->elems = NULL;
    sq->space_size = sq->elem_num = 0;
    return true;
}

// 删除指定val值
bool DeleteVal(SqList *sq, ElemType val)
{
    // 判断指针是否为空
    if (sq == NULL) return false;

    for (int i = 0; i < sq->elem_num; ++i)
    {
        if (sq->elems[i] == val)
        {
            DeleteSqList(sq, i);
        }
    }
    return true;
}

// 打印顺序表数据
void Display(SqList *sq)
{
    // 判断线性表是否为空
    if (sq == NULL) return;

    cout << "顺序表的内容为: ";
    for (int i = 0; i < sq->elem_num; ++i)
    {
        cout << i << " ";
    }
    cout << endl;
}