#include <iostream>
#include "stack.h"

int main(){
	stack<float> fstack = stack<float>(50);


	std::cout << "After initialization" << std::endl;
	fstack.print();

	fstack.push(24.52);
	fstack.push(3.231);
	fstack.push(528.23);

	fstack.print();

	fstack.set_nth(2, 19.42);
	std::cout << "After setting 2nd item to 19.42:" << std::endl;
	fstack.print();

	return 0;
}
