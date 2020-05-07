/*
 * tlist.h
 */
#ifndef __TLIST_H__
#define __TLIST_H__

#include <vector>
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
		vector<T> vct;
};


template <typename T>
int TList<T>::isEmpty() const
{
	if (vct.empty()) {return 1;}
	else {return 0;}
}


template <typename T>
int TList<T>::size() const
{
	return vct.size();
}


template <typename T>
void TList<T>::addFront(const T& t){
	reverse();
	vct.push_back(t);
	reverse();
}


template <typename T>
T TList<T>::popFront(){
	T t = vct.front();
	reverse();
	vct.pop_back();
	reverse();
	return t;
}


template <typename T>
void TList<T>::reverse(){
	::reverse(vct.begin(), vct.end());
}


template <typename T>
TList<T>& TList<T>::operator+=(const TList<T>& rhs){
	vct.insert(vct.end(), rhs.vct.begin(), rhs.vct.end());
	return *this;
}

template <typename T>
TList<T> TList<T>::operator+(const TList<T> &rhs){
    TList<T> copy = *this;
	copy += rhs;
	return copy;
}


template <typename T>
ostream& operator<<(ostream& os, const TList<T>& l){
	os << "{";
	typename vector<T>::const_iterator node = l.vct.begin();
	while (node != l.vct.end()){
		os << *node << " ";
		node++;
	}
	os << "}";
    return os;
}


template <typename T>
T& TList<T>::operator[](int n){
	/*int counter = 0;
	typename vector<T>::iterator node = vct.begin();
	while (node != vct.end()){
		if (counter == n) {break;}
		node++;
		counter++;
	}
	return *node;*/
		return vct.at(n);
}


template <typename T>
const T& TList<T>::operator[](int n) const{
 	return ((TList&)*this)[n];
}

#endif
