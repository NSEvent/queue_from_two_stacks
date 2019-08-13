// Kevin Tang
// 8/12/2019

// To compile: g++ test.cpp -o test

#include "MyQueue.h"
#include <deque>
#include <cassert>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	MyQueue<int> q;
	deque<int> ref;

	for (int i = 0; i < 100; ++i) {
		ref.push_front(i);
		q.push(i);

		if (i % 7 == 0) {
			assert(ref.back() == q.pop());
			ref.pop_back();
		}
		else if (i % 6 == 0) {
			assert(ref.back() == q.pop());
			ref.pop_back();
			assert(ref.back() == q.pop());
			ref.pop_back();
			assert(ref.back() == q.pop());
			ref.pop_back();
		}
		else if (i % 3 == 0) {
			int num = (100 - i) * (i % 7);
			ref.push_front(num);
			q.push(num);
		}


	}

	while (!ref.empty()) {
		cout << ref.back() << endl;
		assert(ref.back() == q.pop());
		ref.pop_back();
	}
}

