/*************************************************************************
    > File Name: majority_element.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Tue 23 Dec 2014 01:06:27 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		int majorityElement(vector<int> &num) {
			// cnt is the difference between # majority element and # rest elments 
			int cnt = 1;
			int ele = num[0];
			for (int i = 1; i < num.size(); i++) {
				if (ele == num[i])
					cnt++;
				else 
					cnt--;
				if (cnt == 0) {
					ele = num[i];
					cnt = 1;
				}
			}
			return ele;
		}
		void test() {
			vector<int> v;
			int x;
			while (1)  {
				while (cin >> x && x > 0) 
					v.push_back(x);
				cout << majorityElement(v) << endl;
				v.clear();
			}
		}
};


int main() {
	Solution s;
	s.test();
}
