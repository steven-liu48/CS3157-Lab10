/*
 * tlist.h
 */
#ifndef __TLIST_H__
#define __TLIST_H__

#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

template <typename T>
class TList;

template <typename T>
ostream& operator<<(ostream& os, const TList<T>& l);


template <typename T>
class TList
{
	public:
		
		int isEmpty() const;

		int size() const;

		void addFront(const T& t);

		T popFront();

		void reverse();

		TList<T>& operator+=(const TList<T>& rhs);

		TList<T> operator+(const TList<T>& rhs);

		friend ostream& operator<< <T>(ostream& os, const TList<T>& l);

		T& operator[](int n);	

		const T& operator[](int n) const;
		
	private:

	list<T> lst;
};


template <typename T>
int TList<T>::isEmpty() const
{
	if (lst.empty()) {return 1;}
	else {return 0;}
}


template <typename T>
int TList<T>::size() const
{
	return lst.size();
}


template <typename T>
void TList<T>::addFront(const T& t){
	//T *newT = new T(str);
	//lst.push_front(newT);
	lst.push_front(t);
}


template <typename T>
T TList<T>::popFront(){
	T s = lst.front();
	lst.pop_front();
	return s;
}

// ?
template <typename T>
void TList<T>::reverse(){
	lst.reverse();
}


template <typename T>
TList<T>& TList<T>::operator+=(const TList<T>& rhs){
	//TList<T>& temp = (TList<T>&) rhs;
	//typename list<T>::iterator node;
	//node = temp.lst.begin();
	//lst.reverse();
	/*
	while (node != temp.lst.end()){
		T *copy = new T(*node);
		push_front(copy);
		node++;
	}*/
	lst.insert(lst.end(), rhs.lst.begin(), rhs.lst.end());
	//lst.reverse();
	return *this;
}

//?
template <typename T>
TList<T> TList<T>::operator+(const TList<T> &rhs){
	//*this += rhs;
	//return *this;
    TList<T> copy = *this;
	copy += rhs;
	return copy;
}


template <typename T>
ostream& operator<<(ostream& os, const TList<T>& l){
	os << "{";
	typename list<T>::const_iterator node = l.lst.begin();
	while (node != l.lst.end()){
		os << *node << " ";
		node++;
	}
	os << "}";
    return os;
}


template <typename T>
T& TList<T>::operator[](int n){
	int counter = 0;
	typename list<T>::iterator node = lst.begin();
	while (node != lst.end()){
		if (counter == n) {break;}
		node++;
		counter++;
	}
	return *node;
}


template <typename T>
const T& TList<T>::operator[](int n) const{
 	return ((TList&)*this)[n];
}

#endif
