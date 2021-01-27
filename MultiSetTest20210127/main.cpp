#include "head.h"
void DisplayMS(const multiset<int>& set)
{
    for (auto& e : set)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main(int arg, char** args)
{
    int array[] = {1, 2, 4, 6, 7, 3, 2, 1, 0, 9};
    multiset<int> ms(array, array + sizeof(array) / sizeof(array[0]));
    DisplayMS(ms);
    auto ret = ms.insert(10);
    cout << *ret << endl;
    auto ret2 = ms.find(6);
    cout << *ret2 << endl;
    ms.erase(4);
    DisplayMS(ms);
    auto count1 = ms.count(1);
    cout << count1 << endl;
    ms.clear();
    cout << "the size of ms is: " << ms.size() << endl;
    return 0;
}