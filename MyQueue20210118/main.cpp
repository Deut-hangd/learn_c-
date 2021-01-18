#include "head.h"
namespace zero
{
    template<class T, class Con = deque<T>>
    class queue
    {
        public:
        // 无参构造
        queue(){}

        // push
        void push(const T& x) {_c.push_back(x);}
        // pop
        void pop() {_c.pop_front();}
        // front
        T& front() {return _c.front();}
        const T& front() const {return _c.front();}
        // back
        T& back() {return _c.back();}
        const T& back() const {return _c.back();}
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
    queue<int> q;
    for (size_t i = 0; i < 10; ++i)
    {
        q.push(i);
    }
    cout << "first " << q.front() << endl;
    q.pop();
    cout << "first " << q.front() << endl;
    cout << "back " << q.back() << endl;
    
    return 0;
}