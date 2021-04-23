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
        Node<T> * first;
        Node<T> * last;

    public:
        LL(){
            this->size = 0;
        }

        ~LL(){	}

        void add(const T& val){
            if (this->size == 0) {
                this->first = new Node<T>{val, nullptr};
                this->last = this->first;
                this->size++;
                return;
            }

            // iterate list and append to last
            Node<T> * current = this->first;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = new Node<T>{val, nullptr};

            this->last = current->next;
            this->size++;

            return;
        }


		T top(){
			// returns garbage if size = 0
			return this->last->info;	
		}

        void remove_last(){
			if(this->size == 1){
				this->first = nullptr;
				this->last = nullptr;
				--size;
				return;
			}

			Node<T> * current = this->first;

			// traverse list
			while(current->next != nullptr){
				if(current->next->next == nullptr){
					current->next = nullptr;	
					this->last = current;	

					--size;
					return;
				}
				current = current->next;
			}

			return;
		}

		void print(){
			if(this->size == 0)	{
				std::cout << " Empty" << std::endl;
				return;
			}

			Node<T> * current = this->first;

			while(current != this->last){
				std::cout <<  " "  << current->info;
				current = current->next;
			}
			std::cout << " " << current->info << std::endl;
			return;
		}

		int length(){
			return this->size;
		}

        void nth(const int pos){	}
};
