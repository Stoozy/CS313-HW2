#pragma once
#include "ll.h"
#include <iostream>

/*
** This is more like  wrapper class around
** the linked list data structure
**
** The internal functinality is in the linked list
*/

template <class T>
class ll_stack{
	private:
		LL<T> list;
	public:

		ll_stack(){
			this->list = LL<T>();
		}

		~ll_stack(){ }

		void push(T val){
			this->list.add(val);
		}

		T top(){
			return list.top();
		}

		void pop(){
			return list.pop_front();
		}

		void print(){
			std::cout << "Stack: " ;
			return this->list.print();
		}

		int size(){
			return this->list.length();
		}

};
