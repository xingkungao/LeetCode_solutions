/*************************************************************************
    > File Name: find_minimum_in_rotated_sorted_array.cpp
    > Author: lax
    > Mail: xingkungao@gmail.com
    > Created Time: Tue 02 Dec 2014 07:43:35 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

class Solution {
	public:
		int findMin(vector<int> &num) {
			int mid, l = 0, r = num.size() - 1;
			if (l == r)
				return num[l];
			int lmin = num[l], rmax = num[r];
			if (lmin < rmax)
				return lmin;
			while (l < r) {
				mid = (l + r) / 2;
				if (mid == l)
					return num[r];
				if (num[mid] < lmin)  { // on the right
					if (mid && num[mid] < num[mid-1])
						return num[mid];
					r = mid;
				}
				else if (num[mid] == num[l])
					return num[r]; 
				else  
					l = mid;
			}
			return num[mid];
		}

		int binarySearch(vector<int> &num, int data) {
			int l, r, mid;
			l = 0;
			r = num.size() - 1;
			while (l <= r) {
				mid = (l + r) / 2;
				if (data < num[mid])
					r = mid - 1;
				else if (data > num[mid])
					l = mid + 1;
				else 
					return mid;
			}
			return -1;
		}
};
int main()  {
	Solution s;
	vector<int> v1;
	v1.push_back(6);
	v1.push_back(2);
	cout << s.findMin(v1) << endl;
}
