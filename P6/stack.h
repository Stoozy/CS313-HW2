#pragma once
#include <iostream>


template <class T>
class stack{
	private:
		int max_size;
		int stack_top;
		T * arr;


	public:
			
		/*
		** Constructor with max_size parameter
		** max_size is the maximum stack size
		** any more would cause an overflow
		**
		**
		** Initialise the array to a dynamically
		** allocated array and stack_top to 0 (the
		** starting index)
		 */
		stack(const int max_size){
			this->max_size = max_size;
			arr = new T[max_size];
			stack_top = 0;
		}

		/*
		** For the destructor, I just deallocated
		** the array.
		 */
		~stack(){
			delete [] arr;
		}

		/*
		** Increase stack_top every push
		 */
		void push(const T& val){
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

		void set_nth(const int n, const T& val){
			arr[n] = val;
		}

		void print(){
			std::cout << "Stack: ";
			// output "empty" if stack is empty
			if(this->is_empty()) {
				std::cout << " Empty" << std::endl;
				return;
			}

			for(int i=1; i<stack_top+1; ++i){
				std::cout << " " << arr[i];
			}

			std::cout << std::endl;
			return;
		}

		bool is_empty(){
			return stack_top == 0;	
		}

};
