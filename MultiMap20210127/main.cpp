#include "head.h"
void DisplayMap(const multimap<int, int>& m)
{
    for (auto& e : m)
    {
        cout << e.first << "--->" << e.second << endl;
    }
}

int main(int arg, char** args)
{
    // ����һ��multimap
    multimap<int, int> m;
    // ����Ԫ��
    m.insert(pair<int, int>(1, 2));
    m.insert(make_pair(1, 3));
    m.insert(make_pair(2, 3));
    m.insert(make_pair(6, 7));
    DisplayMap(m);
    // ��multimap�в���һ����ֵ��, �����շ��صĵ�����
    auto ret = m.insert(make_pair(2, 4));
    cout << ret->first << "=====" << ret->second << endl;
    // ɾ��keyΪ2�����м�ֵ��;   
    size_t c = m.erase(2);
    cout << "count of c is " << c << endl;
    DisplayMap(m);
    // ���multimap
    m.clear();
    cout << "size: " << m.size() << endl;
    return 0;
}