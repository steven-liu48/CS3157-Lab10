/*
 * stack.h
 */

#ifndef __STACK_H__
#define __STACK_H__

#include <deque>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
class Stack;
template <typename T>
ostream& operator<<(ostream& os, const Stack<T>& rhs);

template <typename T>
class Stack
{
    public:

	bool empty() const { return q.empty(); }
	
	void push(const T& t) { q.push_back(t); }
	
        T pop();

        void reverse();

	friend ostream& operator<< <T>(ostream& os, const Stack<T>& rhs);

    private:
	
	deque<T> q;
};

template <typename T>
T Stack<T>::pop() 
{
    T t = q.back();
    q.pop_back();
    return t;
}

template <typename T>
void Stack<T>::reverse() 
{ 
    ::reverse(q.begin(), q.end()); 
}

template <typename T>
ostream& operator<<(ostream& os, const Stack<T>& rhs)
{
    os << "[ ";

    // The use of "auto" may require "-std=c++11" or "-std=c++0x" flag
    // if you are using an older version of g++ or clang++ compiler.
    // 
    // Alternatively you can declare i explicitly like this:
    // typename deque<T>::const_iterator i;

    for (auto i = rhs.q.begin(); i != rhs.q.end(); ++i)
	os << *i << " ";

    os << "<";
    return os;
}

#endif
