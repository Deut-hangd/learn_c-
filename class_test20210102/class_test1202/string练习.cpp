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
	cout << s1 <<  endl;
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
	s.reserve(100);  // 为字符串预留空间
	cout << s.size() << endl;
	cout << s.capacity() << endl;

	s.reserve(50);  // 空间不会压缩
	cout << s.size() << endl;
	cout << s.capacity() << endl;
}

void TestPushBack()
{
	string s;
	
	size_t sz = s.capacity();
	cout << "making s grow" << endl;
	for (int i = 0; i < 100; i++)
	{
		s.push_back('a');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity" << sz << endl;
		}
	}
}

void TestPushBackReserve()
{
	string s;
	s.reserve(100);
	int sz = s.capacity();
	cout << "making a grow: " << sz << endl;
	for (int i = 0; i < 100; i++)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity" << sz << endl;
		}
	}
}

void TestStringConst()
{
	string s1("hello");
	const string s2("world");
	s1[0] = 'e';
	cout << s1 <<  " "  << s1[0] << endl;
	cout << s2 << " " <<  s2[1] << endl;

}

void TestFor()
{
	string s("hello");
	for (auto ch : s)
	{
		cout << ch << endl;
	}
}

void TestIterator()
{
	string s("hello");
	string::iterator it = s.begin();

	while (it != s.end())
	{
		cout << *it << endl;
		++it;
	}
}

void TestIteratorR()
{
	string s("hello");
	string::reverse_iterator it = s.rbegin();

	while (it != s.rend())
	{
		cout << *it << endl;
		++it;
	}
}

void TestString() 
{
	string s("hello");
	// push_back() 方法添加一个字符到原字符串末尾
	s.push_back('K');
	cout << "push_back: " << s << endl;
	// append() 方法添加一个字符串到原字符串末尾
	s.append("kiva");
	cout << "append: " << s << endl;
	// 利用 operator+= ,即运算符重载向字符串末尾追加字符串
	s += "builder";
	cout << "+=: " << s << endl;
	s = s + "sun";
	cout << "+: " << s << endl;
	// 用c_str()返回c格式的字符串
	cout << sizeof(s) << endl;
	s = s.c_str();
	cout << "c_str: " << s << endl;
	cout << sizeof(s) << endl;
	// 获取文件的后缀
	string file("string.cpp");
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size() - pos));
	cout << suffix << endl;
	// 获取域名
	string url("http://www.baidu.com/news");
	// 获取协议和域名之间分割符的位置
	size_t start = url.find("//");
	cout << string::npos << endl;
	if (start == string::npos){
		cout << "invalide url" << endl;
		return;
	}
	start += 2;
	size_t end = url.find('/', start);
	// substr() 第一个参数表示截取的位置, 后一个参数表示截取的元素个数
	cout << url.substr(start, end - start) << endl;

	// 删除url协议前缀
	size_t p = url.find("://");
	url.erase(0, p + 3);
	cout << url << endl;

}

int main() 
{
	TestString();
	system("pause");
	return 0;
}