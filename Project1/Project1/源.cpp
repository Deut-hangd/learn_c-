#include <iostream>
using namespace std;

// 数组右移一位
void Right_Move_Array(int *a, int n)
{
	int tmp = a[n - 1];
	for (int i = n - 1; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = tmp;
}

// 数组右移k位
void Right_Move_ArrayK(int *a, int n, int k)
{
	int b[10];
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}
	for (int i = 0; i < n; i++)
	{
		a[(i + k) % n] = b[i];
	}
}

// 数组左移一位
void Left_Move_Array(int *a, int n)
{
	int tmp = a[0];
	for (int i = 0; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	a[n - 1] = tmp;
}

// 数组左移k位
void Left_Move_ArrayK(int *a, int n, int k)
{
	int b[10];
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (i < k)
		{
			a[n - k + i] = b[i];
		}
		else {
			a[i - k] = b[i];
		}
	}
}

// 打印数组元素
void display(int *a, int n)
{
	cout << "{";
	for (int i = 0; i < n; i++)
	{
		cout << a[i];
		if (i != n - 1)
		{
			cout << ",";
		}
	}
	cout << "}" << endl;
}

int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(a) / sizeof(a[0]);
	// 调用数组元素右移一位函数
	Right_Move_Array(a, n);
	display(a, n);
	// 调用数组元素右移k位函数
	int k = 1;
	cout << "请输入偏移量:" << endl;
	cin >> k;
	Right_Move_ArrayK(a, n, k),
		display(a, n);
	// 调用数组元素左移一位函数
	Left_Move_Array(a, n);
	display(a, n);
	// 调用数组元素左移k位函数
	Left_Move_ArrayK(a, n, k);
	display(a, n);
	system("pause");
	return 0;
}