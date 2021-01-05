#include <iostream>
using namespace std;

// ��������һλ
void Right_Move_Array(int *a, int n)
{
	int tmp = a[n - 1];
	for (int i = n - 1; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = tmp;
}

// ��������kλ
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

// ��������һλ
void Left_Move_Array(int *a, int n)
{
	int tmp = a[0];
	for (int i = 0; i < n - 1; i++)
	{
		a[i] = a[i + 1];
	}
	a[n - 1] = tmp;
}

// ��������kλ
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

// ��ӡ����Ԫ��
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
	// ��������Ԫ������һλ����
	Right_Move_Array(a, n);
	display(a, n);
	// ��������Ԫ������kλ����
	int k = 1;
	cout << "������ƫ����:" << endl;
	cin >> k;
	Right_Move_ArrayK(a, n, k),
		display(a, n);
	// ��������Ԫ������һλ����
	Left_Move_Array(a, n);
	display(a, n);
	// ��������Ԫ������kλ����
	Left_Move_ArrayK(a, n, k);
	display(a, n);
	system("pause");
	return 0;
}