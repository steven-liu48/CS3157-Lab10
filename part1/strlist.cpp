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
		MyString *pop = (MyString *)::popFront(&list);
		delete pop;
	}
}

// Copy constructor

StrList::StrList(const StrList& l) {
	initList(&list);
	struct Node *node = l.list.head;
    while (node) {
		MyString *cpy = new MyString(*(MyString *) node->data);
		::addBack(&list, cpy);
    	node = node->next;
    }
}

// op=

StrList& StrList::operator=(const StrList& l) {
	if (this == &l) {
		return *this;
	}
	while (!isEmpty()){
		MyString *pop = (MyString *)::popFront(&list);
        delete pop;
	}
	struct Node *node = l.list.head;
    while (node) {
        MyString *cpy = new MyString(*(MyString *) node->data); 
		::addBack(&list, cpy);
        node = node->next;
    }
	return *this;
}

// size()

int StrList::size() const{
	int counter = 0;
	struct Node *node = list.head;
    while (node) {
        counter++;
        node = node->next;
    }
	return counter;
}

// addFront()

void StrList::addFront(const MyString str){
	MyString *addstr = new MyString(str);
	::addFront(&list, addstr);
}

// popFront()

MyString StrList::popFront(){
	MyString *pop = (MyString *)::popFront(&list);
	if(pop != NULL){
    	MyString temp(*pop);
		delete pop;
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
         MyString *addstr = new MyString(*(MyString *) node->data);
         ::addFront(&list, addstr);
         node = node->next;
    }
    reverse();
    return *this;
}

// operator+

StrList StrList::operator+(const StrList& rhs){
	StrList copy = *this;
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



