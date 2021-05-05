#pragma once
#include <iostream>
#include <assert.h>

// Simple template node structure
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

		/*
		** If list is empty, create a
		** node with value and make head
		** point to it
		**
		** Otherwise, store current head
		** pointer as old_head and make
		** head point to the new node which
		** points to the old_head as next
		**
		** increase size
		 */
		void add(const T& val){
			// if empty, initialize head to the new Node 
			if (is_empty()) {
				head = new Node<T>{val, nullptr};
				++size;
				return;
			}

			Node<T> * old_head = head;
			head = new Node<T>{val, old_head};
			++size;
			return;
		}


		// simply return heads data
		T top(){
			return head->info;
		}

		/*
		** Create a temporary pointer
		** pointing to second to top value
		** (the node right after head)
		**
		** delete that node and make head
		** point to the node after.
		**
		** decreases size
		 */
		void pop_front(){
			Node<T> * next = head->next;
			delete head;
			head = next;
			--size;
			return;
		}

		/*
		** Go over all items and print the info
		** print "Empty" if stack is empty
		 */
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
