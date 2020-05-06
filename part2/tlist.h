/*
 * tlist.h
 */
#ifndef __TLIST_H__
#define __TLIST_H__

#include <list>

using namespace std;

template <typename T>
class TList;

template <typename T>
ostream& operator<<(ostream& os, const TList<T>& l);

template <typename T>
ostream& operator+=(ostream& os, const TList<T>& l);

template <typename T>
class TList
{
	public:
        TList();
        
        ~TList();
        
        TList(const T& l);
        
        TList& operator=(const T& l);

		int isEmpty() const;

		int size() const;

		void addFront(const T str);

		T popFront();

		void reverse();

		T& operator+=(const T& rhs);

		friend T operator+(const T& lhs, const T& rhs);

		friend ostream& operator<<(ostream& os, const T& l);

		T& operator[](int n);	

		const T& operator[](int n) const;
	private:

	list<T> lst;
}
