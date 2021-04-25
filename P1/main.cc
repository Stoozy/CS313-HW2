#include "ll_stack.h"
#include "arr_stack.h"

#include <iostream>
#include <chrono>
using std::cout;
using std::endl;
using std::chrono::system_clock;
using std::chrono::steady_clock;
using std::chrono::duration_cast;
using std::chrono::seconds;
using std::chrono::milliseconds;


template <typename Func>
long long TimeFunc(Func f)
{
	auto begin = steady_clock::now();
	f();
	auto end = steady_clock::now();

	return duration_cast<milliseconds>(end - begin).count();
}


int main(){
	long long ll=0;
	long long arr=0;

	for(int i=0; i<10000; ++i){


		ll += TimeFunc([]{
			ll_stack<int> s1 = ll_stack<int>();
			for(int i=0; i<1000;++i){
				s1.push(rand()%100);
			}

			s1.print();
			for(int i=0; i<1000;++i){
				s1.pop();
			}


		});

		arr += TimeFunc([]{
			arr_stack<int> s2 = arr_stack<int>(1000);
			for(int i=0; i<1000;++i){
				s2.push(rand()%100);
			}

			s2.print();
			for(int i=0; i<1000;++i){
				s2.pop();
			}
		});
	}


	//  1000000 pushes and 1000000 pops
	cout << "Total push/pop time (Linked List based stack): " << ll << "ms" << endl;
	cout << "Total push/pop time (Array based stack): " << arr <<  "ms" << endl;

    return 0;
}
