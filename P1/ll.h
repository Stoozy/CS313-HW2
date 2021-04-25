#pragma once
#include <iostream>
#include <assert.h>

template <class T>
struct Node{
	T info;
	Node<T> * next;
};

template <class T>
class LL {
	private:
		int size;
		Node<T> * head;

		bool is_empty() { return size == 0;};
	public:
		LL(){
			size = 0;
		}

		~LL(){	}

		void add(const T& val){
			// if empty, initialize head to the new Node 
			if (is_empty()) {
				head = new Node<T>{val, nullptr};
				++size;
				return;
			}

			Node<T> * old_head = head;
			// point to old head
			head = new Node<T>{val, old_head};
			++size;
			return;
		}


		T top(){
			return head->info;
		}

		void pop_front(){
			head = head->next;
			return;
		}

		void print(){
			if(this->size == 0)	{
				std::cout << " Empty" << std::endl;
				return;
			}

			Node<T> * current = this->head;

			while(current->next != nullptr){
				std::cout <<  " "  << current->info;
				current = current->next;
			}
			std::cout << " " << current->info << std::endl;
			return;
		}

		int length(){
			return size;
		}

};
