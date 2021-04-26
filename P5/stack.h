#pragma once
#include <iostream>


template <class T>
class stack{
	private:
		int max_size;
		int stack_top;
		T * arr;

		bool is_empty(){
			return stack_top == 0;	
		}

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
		
		/*
		** Push only numbers that are greater than every
		** number already on the stack.
		** 
		** If a smaller number is found then replace the number
		** that is greater with the one that is smaller.
		** 
		** Do nothing for numbers that repeat.
		** 
		 */
        void push_ordered(const T& val) {
            
            for(int i=0; i<stack_top+1; ++i) {
                if(arr[i] == val) return;
                
                if(arr[i] > val){
                    arr[i]  = val;
                    return;
                }
            }

            // if new element is not smaller than anything else,
            // just push normally
            push(val);
             
        }

		T top(){
			return arr[stack_top];
		}

		void set_nth(const int n, const T& val){
			arr[n] = val;
		}

		void print(){
			std::cout << "Subsequence (Stack): [";
			// output "empty" if stack is empty
			if(this->is_empty()) {
				std::cout << " Empty" << std::endl;
				return;
			}

			for(int i=1; i<stack_top+1; ++i){
				std::cout << " " << arr[i];
			}

			std::cout << " ]"  << std::endl;
			return;
		}

		int size(){
			return stack_top;
		}
};
