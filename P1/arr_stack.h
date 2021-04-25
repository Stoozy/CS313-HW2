#pragma once
#include <iostream>
template <class T>
class arr_stack{
	private:
		int max_size;
		int stack_top;
		T * arr;


		bool is_empty(){
			return stack_top == 0;	
		}

	public:
			
		arr_stack(const int max_size){
			this->max_size = max_size;
			arr = new T[max_size];
			stack_top = 0;
		}

		~arr_stack(){
			delete [] arr;
		}

		void push(T val){
			arr[++stack_top] = val;
		}

		void pop(){
			if(stack_top == 0)
				return;
			--stack_top;
		}

		T top(){
			return arr[stack_top];
		}

		void print(){
			std::cout << "Stack: ";
			// say empty if stack is empty
			if(this->is_empty()) {
				std::cout << " Empty" << std::endl;
				return;
			}

			for(int i=0; i<stack_top+1; ++i){
				std::cout << " " << this->arr[i];
			}

			std::cout << std::endl;
			return;
		}
};
