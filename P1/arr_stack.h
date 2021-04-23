#pragma once
#include <iostream>
template <class T>
class arr_stack{
	private:
		int max_size;
		int size;
		T * arr;
	public:
			
		arr_stack(const int max_size){
			this->max_size = max_size;
			this->arr = new T[max_size];
			this->size = -1;
		}

		~arr_stack(){}

		void push(const T& val){
			this->arr[++size] = val;
		}

		void pop(){
			--size;
		}

		T top(){
			return this->arr[size];
		}

		void print(){
			std::cout << "Stack: ";
			// say empty if stack is empty
			if(this->size == 0) {
				std::cout << " Empty" << std::endl;
				return;
			}

			for(int i=0; i<size; ++i){
				std::cout << " " << this->arr[i];
			}

			std::cout << std::endl;
			return;
		}
};
