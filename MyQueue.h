// Kevin Tang
// 8/12/2019

// To compile: g++ test.cpp -o test

#include <stack>

template <class T>
class MyQueue {
public:
	MyQueue() {}

	// O(1) push 
	void push(T val) {
		s1.push(val);
	}

	// O(n) pop
	T pop() {
		if (s2.empty()) {
			// move everything from s1 to s2
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		// top element in s2 is the return val
		T res = s2.top();
		s2.pop();
		return res;
	}

	
private:
	std::stack<T> s1;
	std::stack<T> s2;


};
