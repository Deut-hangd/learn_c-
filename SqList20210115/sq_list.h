#pragma once

typedef int ElemType;

typedef struct SqList 
{
    ElemType *elems;
    int space_size;  // 当前空间大小
    int elem_num;  // 当前已存取的数据
} SqList;


// 初始化函数
bool InitSqList(SqList *sq, int size);

// 插入数据函数
bool InsertSqList(SqList *sq, ElemType val, int pos);

// 删除数据函数
bool DeleteSqList(SqList *sq, int pos);

// 删除指定的val
bool DeleteVal(SqList *sq, ElemType val);

// 遍历打印顺序表的数据
void DisplaySqList(SqList *sq);

