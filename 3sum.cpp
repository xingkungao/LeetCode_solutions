/*************************************************************************
  > File Name: 3sum.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 07 Dec 2014 05:12:07 PM CST
 ************************************************************************/
#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		vector<vector<int> > threeSum(vector<int> &num) {
			vector<vector<int> > ret;
			sort(num.begin(), num.end());
			for (vector<int>::size_type i = 0; i + 2 < num.size(); i++)  {
				// skip duplicate element
				if (i && num[i] == num[i-1])
					continue;
				twoSum(num, i + 1, 0 - num[i], ret);
			}
			return ret;
		}
		void twoSum(vector<int> &num, int start, int sum, vector<vector<int> > &ret) {
			int l = start, r = num.size() - 1;
			while (l < r) {
				int tmp = num[l] + num[r];
				if (tmp > sum) 
					r--;
				else if (tmp < sum)
					l++;
				else {
					vector<int> v;
					v.push_back(-sum);
					v.push_back(num[l]);
					v.push_back(num[r]);
					ret.push_back(v);

					// skip duplicate element
					do {
						l++;
					}while (num[l] == num[l-1]);

					do {
						r--;
					}while (num[r] == num[r+1]);
				}
			}
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

			int C[] = {0, 0, 0};
			vector<int> v3(C, C + 3);
			print2DVector(threeSum(v3));
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
