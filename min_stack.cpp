/*************************************************************************
    > File Name: min_stack.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Wed 24 Dec 2014 04:42:33 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class MinStack {
	private:
		stack<int> estk;
		stack<int> mstk;
		int minele = 0;
	public:
		MinStack() {
			mstk.push(INT_MAX);
		}

		void push(int x) {
			estk.push(x);
			if(estk.size() == 1 || x <= minele) {
				mstk.push(x);
				minele = x;
			}
		}

		void pop() {
			if (estk.empty())
				return;
			if (minele == estk.top()) {
				mstk.pop();
				minele = mstk.top();
			}
			estk.pop();
		}

		int top() {
			if (estk.empty())
				return -1;
			return estk.top();
		}

		int getMin() {
			return minele;
		}
};



int main() {
	MinStack m;
	m.push(3);
	m.push(2);
	m.push(1);
	cout << m.getMin() << endl;
	m.pop();
	cout << m.getMin() << endl;
	m.pop();
	cout << m.getMin() << endl;
	m.pop();

}
