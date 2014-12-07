/*************************************************************************
  > File Name: 3sum.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 07 Dec 2014 05:12:07 PM CST
 ************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
	public:
		static bool comp (vector<int> v1, vector<int> v2) {
			if (v1[0] != v2[0])
				return v1[0] < v2[0];
			else if (v1[1] != v2[1])
				return v1[1] < v2[1];
			else if (v1[2] != v2[2])
				return v1[2] < v2[2];
			return false;
		}
		/*
		vector<vector<int> > threeSum(vector<int> &num) {
			set<vector<int>, bool(*)(vector<int>, vector<int>)> s (&comp);
			vector<vector<int> > v;
			int l, r, sum, tmp;
			vector<int> triple;
			std::sort(num.begin(), num.end());
			for (int i = 0; i < num.size(); i++) {
				sum = -num[i];
				l = i + 1; 
				r = num.size() - 1;
				while (l < r) {
					if (l == i) 
						l++;
					else if (r == i)
						r--;
					tmp = num[l] + num[r];
					if (tmp < sum)
						l++;
					else if (tmp > sum) 
						r--;
					else {
						//equal 
						triple.clear();
						triple.push_back(num[i]);
						triple.push_back(num[l]);
						triple.push_back(num[r]);
						
					//	if (!triple[0] && !triple[1] && !triple[2])
					//		cout << "(" << i << "," << l << "," << r << "):" << num[i] << ' ' << num[l] << ' ' << num[r] << "   "<< "**********************************************" << endl;
					//	std::sort(triple.begin(), triple.end());
						l++;
						r--;
						s.insert(triple);
					}
				}
			}
			for (set<vector<int> >::iterator it = s.begin(); it != s.end(); ++it) {
				v.push_back(*it);
			}
			return v;
		}
		*/
		vector<vector<int> > threeSum(vector<int> &num) {
			vector<vector<int> > v;
			int l, r, sum, tmp;
			vector<int> triple;
			std::sort(num.begin(), num.end());
			for (int i = 0; i < num.size(); i++) {
				sum = -num[i];
				if (i && num[i] == num[i-1])
					continue;
				l = i + 1; 
				r = num.size() - 1;
				while (l < r) {
					if (l == i) 
						l++;
					else if (r == i)
						r--;
					tmp = num[l] + num[r];
					if (tmp < sum)
						l++;
					else if (tmp > sum) 
						r--;
					else {
						//equal 
						triple.clear();
						triple.push_back(num[i]);
						triple.push_back(num[l]);
						triple.push_back(num[r]);
						
					//	if (!triple[0] && !triple[1] && !triple[2])
					//		cout << "(" << i << "," << l << "," << r << "):" << num[i] << ' ' << num[l] << ' ' << num[r] << "   "<< "**********************************************" << endl;
					//	std::sort(triple.begin(), triple.end());
						/*
						l++;
						r--;
						*/
						do {
							l++;
						}while (num[l] == num[l-1]);
						do {
							r--;
						}while (num[r] == num[r+1]);
						v.push_back(triple);
					}
				}
			}
			return v;
		}
		void print(vector<int> &r) {
				for (int j = 0; j < r.size(); j++)
					cout << r[j] << " ";
				cout << endl;
		}
		void print(vector<vector<int> > &r) {
			cout << "# of qualified triples:" << r.size() << endl;
			for (int i = 0; i < r.size(); i++)  {
				for (int j = 0; j < r[i].size(); j++)
					cout << r[i][j] << " ";
				cout << endl;
			}
			cout << endl;
		}
		void test() {
			int A[] = {-13,5,13,12,-2,-11,-1,12,-3,0,-3,-7,-7,-5,-3,-15,-2,14,14,13,6,-11,-11,5,-15,-14,5,-5,-2,0,3,-8,-10,-7,11,-5,-10,-5,-7,-6,2,5,3,2,7,7,3,-10,-2,2,-12,-11,-1,14,10,-9,-15,-8,-7,-9,7,3,-2,5,11,-13,-15,8,-3,-7,-12,7,5,-2,-6,-3,-10,4,2,-5,14,-3,-1,-10,-3,-14,-4,-3,-7,-4,3,8,14,9,-2,10,11,-10,-4,-15,-9,-1,-1,3,4,1,8,1};
			vector<int> v(A, A + sizeof(A) / sizeof(int));
			int B[] = {9,-15,6,6,10,-2,8,8,0,-6,-4,-2,14,-6,-14,-2,12,5,-2,-8,13,13,-10,4,-6,8,6,-15,-5,11,-15,11,3,-2,-6,-10,11,-12,13,-12,-11,-5,2,10,-4,-5,-15,-7,7,-2,0,5,-11,-3,-13,-10,-9,0,-10,-7,-12,12,-11,7,-5,-1,12,-8,-6,3,-13,-10,5,-4,-14,-14,6,8,-14,-9,-8,-7,3,-4,6,5,1,12,-9,6,-10,-6,-5,-14,-14,5,-8,6,4,1};
			vector<int> v2(B, B + sizeof(B) / sizeof(int));
			/*
			vector<int> b1 = v;
			vector<int> b2 = v2;
			sort(b1.begin(), b1.end());
			sort(b2.begin(), b2.end());
			print(b1);
			print(b2);
			*/
			vector<vector<int> > r = threeSum(v);
			print(r);
			r.clear();
			cout << "_____________________\n";
			r = threeSum(v2);
			print(r);


		}
};

int main() {
	Solution s;
	s.test();
}
