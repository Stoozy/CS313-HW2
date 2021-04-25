#pragma once
#include "ll.h"
#include <iostream>

template <class T>
class ll_stack{
	private:
		LL<T> list;
	public:
		ll_stack(){
			this->list = LL<T>();
		}

		~ll_stack(){

		}

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
