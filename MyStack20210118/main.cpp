#include "head.h"

namespace zero
{
    template<class T, class Con = deque<T>>
    class stack
    {
        public:
        stack(){};
        // push
        void push(const T& x) {_c.push_back(x);}
        // pop
        void pop() {_c.pop_back();}
        // top
        T& top() {return _c.back();}
        const T& top() const {return _c.back();}
        // size
        size_t size() {return _c.size();}
        // empty
        bool empty() {return _c.empty();}

        private:
        Con _c;
    };
}

using namespace zero;
int main(int arg, char **args)
{
    stack<int> s;
    for (int i = 0; i < 10; ++i)
    {
        s.push(i);
    }

    cout << s.top() << endl;
    return 0;
}