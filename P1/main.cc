#include "ll_stack.h"
#include "arr_stack.h"
#include <iostream>
using namespace std;

int main(){
	//ll_stack<int> s1 = ll_stack<int>();

	//s1.push(5);
	//s1.print();

	//s1.push(64);
	//s1.print();

	//s1.push(28);
	//s1.print();

	//s1.pop();
	//s1.print();

	arr_stack<int> s2 = arr_stack<int>(100);
	s2.push(5);
	s2.print();

	s2.push(64);
	s2.print();

	s2.push(28);
	s2.print();

	s2.pop();
	s2.print();

	cout << "Top value is "  << s2.top() << endl;

    return 0;
}
