#include <cstring>
#include <cstdio>
    
#include "strlist.h"

using namespace std;

// Default constructor

StrList::StrList() {
	initList(&list);
}

// Destructor

StrList::~StrList() {
	while(!isEmpty()){
		MyString *s = (MyString *)::popFront(&list);
		//cout << "Pop" << *s << endl;
		delete s;
	}
}

// Copy constructor

StrList::StrList(const StrList& l) {
	initList(&list);
	struct Node *node = l.list.head;
    while (node) {
    	MyString *original = (MyString *)node->data;
		MyString *copy = new MyString(*original);
		//cout << "Copied" << *copy << endl;
		::addBack(&list, copy);
    	node = node->next;
    }
}

// op=

StrList& StrList::operator=(const StrList& l) {
	if (this == &l) {
		//cout << "SAME!" << endl;
		return *this;
	}
	while (!isEmpty()){
		MyString *s = (MyString *)::popFront(&list);
        delete s;
	}
	struct Node *node = l.list.head;
    while (node) {
        MyString *original = (MyString *)node->data;
        MyString *copy = new MyString(*original);
        ::addBack(&list, copy);
        node = node->next;
    }
	return *this;
}

// size()

int StrList::size() const{
	int size = 0;
	struct Node *node = list.head;
    while (node) {
        size++;
        node = node->next;
    }
	return size;
}

// addFront()

void StrList::addFront(const MyString str){
	MyString *newString = new MyString(str);
	//cout << "Added " << *newString << endl;
	::addFront(&list, newString);
}

// popFront()

MyString StrList::popFront(){
	MyString *s = (MyString *)::popFront(&list);
	if(s != NULL){
    	MyString temp(*s);
		delete s;
		return temp;
	} else {
		return NULL;
	}
}

// reverse()

void StrList::reverse(){
	::reverseList(&list);
}

// operator+=
StrList& StrList::operator+=(const StrList& rhs){
    //cout << rhs << endl;
	struct Node *node = rhs.list.head;
    reverse();
    while (node) {
         MyString *copy = new MyString(*(MyString *) node->data);
         ::addFront(&list, copy);
         node = node->next;
    }
    reverse();
    return *this;
}

// operator+

StrList operator+(const StrList& lhs, const StrList& rhs){
	StrList copy;
	copy += lhs;
	copy += rhs;
	return copy;
}

// operator<<

ostream& operator<<(ostream& os, const StrList& l){
	os << "{";
	struct Node *node = l.list.head;
	while (node) {
         os << *(MyString *)node->data << ' ';
         node = node->next;
    }
	os << "}";
	return os;
}

// operator[]

MyString& StrList::operator[](int n){
	int counter = 0;
	struct Node *node = list.head;
    while (node) {
    	if (counter == n) {break;}
        node = node->next;
		counter++;
    }
	return *(MyString *) node->data;
}

// operator[] const

const MyString& StrList::operator[](int n) const{
	return ((StrList&)*this)[n]; 
}



