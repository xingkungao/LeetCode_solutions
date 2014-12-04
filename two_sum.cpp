/*************************************************************************
    > File Name: two_sum.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Wed 03 Dec 2014 11:44:39 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
class Solution {
	public:
		vector<int> twoSum(vector<int> &numbers, int target) {
			vector<int> ans;
			vector<int> backup = numbers;
			std::sort(numbers.begin(), numbers.end());
			int len = numbers.size();
			int l = 0, r = len - 1, sum;
			while (l < r) {
				sum = numbers[l] + numbers[r];
				if (sum == target) {

					int a, b;
					for (int i = 0; i < backup.size(); i++) {
						if (numbers[l] == backup[i]) {
							a = i;
							break;
						}
					}
					for (int i = 0; i < backup.size(); i++) {
						if (numbers[r] == backup[i]) {
							b = i;
							if (b != a)
							break;
						}
					}
					if (a > b)
						std::swap(a, b);
					ans.push_back(++a);
					ans.push_back(++b);
					return ans;
				}
				else if (sum < target) l++;
				else r--;
			}
			return ans;
		}
		void print(vector<int> &v) {
			for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) 
				cout << *it << " ";
			cout << endl;
		}
		void test() {
			vector<int> data;
			data.push_back(4);
			data.push_back(3);
			data.push_back(0);
			vector<int> v = twoSum(data, 4);
			print(v);
		}
};

int main() {
	Solution s;
	s.test();
}
