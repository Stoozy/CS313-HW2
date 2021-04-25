#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>

#include "stack.h"


/*
** Reverses a string using a stack
*/
std::string stack_reverse(std::string str ){
	if(str.size() == 0 || str.size() == 1) return str;

	// build the stack
	stack<char>	cstack = stack<char>(str.size());
	for(int i=0; i<str.size();++i)
		cstack.push(str[i]);

	// pop the stack and output to `rev` string
	std::string rev;
	while(!cstack.is_empty()){
		rev += cstack.top();
		cstack.pop();
	}

	return rev;
}

int main(){
	std::ifstream in{"input.txt"};

	// used to read lines
	std::string line;

	while(getline(in, line)){

		// create a stringstream of the read
		// line so that we can tokenize it
		std::stringstream ss(line);

		// all the words in current line
		std::vector<std::string> words;

		// tmp_str holds each word when being read
		std::string tmp_str;
		// tokenize line with ' ' being
		// the delimeter
		while(getline(ss, tmp_str, ' '))
			words.push_back(tmp_str);

		// for each word, print he reverse
		// and then add a space after
		for(int i=0; i<words.size(); ++i)
			std::cout <<  stack_reverse(words[i]) << " ";
		std::cout << std::endl;
	}

	return 0;
}
