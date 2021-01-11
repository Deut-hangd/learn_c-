#include <iostream>
#include <assert.h>

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

        void push_back(const T& value)
        {
            insert(end(), value);
        }

        //TODO
        void insert(iterator pos, const T& value)
        {

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
            }
            _start = temp;
            _finish = _start + oldSize;
            _endOfStorage = _start + n;
        }

        private:

        iterator _start;
        iterator _finish;
        iterator _endOfStorage;

    };
}
