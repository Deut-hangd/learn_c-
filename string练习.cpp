#include "head.h"
#include <string>
using std::string;

void test1()
{
	string s1("abc");
	cout << s1 << endl;
	cout << s1.empty() << endl;
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;

	s1.clear();
	cout << s1 << " " <<  endl;
	cout << s1.empty() << endl;
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;

	s1.resize(10, 'a');
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;

	s1.resize(15);
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.length() << endl;
	cout << s1.capacity() << endl;
}

void test2()
{
	string s;
	s.reserve(100);  // Îª×Ö·û´®Ô¤Áô¿Õ¼ä
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(50);  // ¿Õ¼ä²»»áÑ¹Ëõ
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

int main()
{
	test1();
	system("pause");
	return 0;
}