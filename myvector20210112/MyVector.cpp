#include <iostream>
#include <assert.h>
#include <algorithm>
using std:: cout;
using std:: cin;
using std:: endl;

namespace zero
{
    template<class T>
    class vector
    {
        public:

        typedef T* iterator;
        typedef const T* const_iterator;

        iterator begin() {return _start;}
        iterator end() {return _finish;}

        const_iterator begin() const {return _start;}
        const_iterator end() const {return _finish;}

        vector()
        :_start(nullptr)
        ,_finish(nullptr)
        ,_endOfStorage(nullptr)
        {}

        vector(int n, const T& value = T())
        :_start(nullptr)
        ,_finish(nullptr)
        ,_endOfStorage(nullptr)
        {
            reserve(n);
            while (n--)
            {
                push_back(value);
            }
        }

        ~vector()
        {
            delete[] _start;
            _start = _finish = _endOfStorage = nullptr;
        }

        void push_back(const T& value)
        {
            insert(end(), value);
        }

        void pop_back()
        {
           erase(--end());
        }

        T& operator[](size_t pos)
        {
            return _start[pos];
        }

        const T& operator[](size_t pos) const
        {
            return _start[pos];
        }

        vector<T>& operator=(vector<T> v)
        {
            swap(v);
            return *this;
        }

        iterator insert(iterator pos, const T& value)
        {
            assert(pos <= _finish);

            if (_finish == _endOfStorage)
            {
                size_t len = pos - _start;
                size_t newCapacity = (0 == capacity()) ? 1 : capacity() * 2;
                reserve(newCapacity);
                pos = _start + len;
            }

            iterator end = _finish - 1;

            while (end >= pos) 
            {
                *(end + 1) = *end;
                --end;
            }

            *pos = value;
            ++_finish;
            return pos;
        }

        // 返回删除数据的下一个数据
        // 方便解决一边遍历, 一边删除导致迭代器失效的问题
        iterator erase(iterator pos)
        {
            iterator begin = pos + 1;
            while (begin != _finish)
            {
                *(begin - 1) = *(begin);
                ++begin;
            }
            --_finish;
            return pos;
        }

        size_t size() {return _finish - _start;}
        size_t capacity() {return _endOfStorage - _start;}

        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t oldSize = size();
                T* temp = new T[n];

                if (_start)
                {
                    for (int i = 0; i < oldSize; i++)
                    {
                        temp[i] = _start[i];
                    }
                }
                delete[] _start;
                _start = temp;
                _finish = _start + oldSize;
                _endOfStorage = _start + n;
            }
            
        }

        void resize(size_t n, const T& value = T())
        {
            if (n <= size())
            {
                _finish = _start + n;
                return;
            }

            if (n > capacity())
            {
                reserve(n);
            }

            iterator tmp = _finish;
            _finish = _start + n;
            while (tmp != _finish)
            {
                *tmp = value;
                ++tmp;
            }


        }

        void swap(vector<T>& v)
        {
            swap(_start, v._start);
            swap(_finish, v._finish);
            swap(_endOfStorage, v._endOfStorage);
        }

        private:

        iterator _start;
        iterator _finish;
        iterator _endOfStorage;

    };
}

int main()
{
    zero::vector<int> v(12, 6);
    zero:: vector<int>:: iterator pos = v.begin();
    v.insert(pos + 3, 9);
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << v.size() << " " << v.capacity() << endl;
}