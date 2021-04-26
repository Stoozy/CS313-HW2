#include <iostream>
#include "stack.h"
#include <vector>


/*
** Driver code:
** Creates a randomly sized vector with randomly generated numbers
** that is also push to the push in order where the main functionality lies
**
** Then the random vector is printed as the full sequence and the stack is printed
** as the subsequence
*/
int main(){
	srand(time(0));
	std::vector<int> rand_nums;

	stack<int> s = stack<int>(10);
	for(int i=0; i<rand()%10+4; ++i){
		rand_nums.push_back(rand()%50);
		s.push_ordered(rand_nums[i]);
	}

	std::cout << "Sequence: [ ";
	for(int i=0; i<rand_nums.size(); ++i)
		std::cout << rand_nums[i] << " ";
	std::cout << " ]" << std::endl;

	s.print();
	std::cout << "Length of LIS: " << s.size();

	return 0;
}
