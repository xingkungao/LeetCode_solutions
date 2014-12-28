/*************************************************************************
  > File Name: anagrams.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Sun 28 Dec 2014 03:59:48 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

class Solution {
	public:
		vector<string> anagrams(vector<string> &strs) {
			unordered_multimap<string, int> mymap;
			vector<string> ret;
			for (int i = 0; i < strs.size(); i++) {
				string s = strs[i];
				sort(s.begin(), s.end());
				mymap.insert(make_pair(s, i));
			}
			/*
			 * the following code doesn't work in Leetcode OJ probably because of bugs of gcc 
			 */
			
			/*
			for (int i = 0; i < mymap.bucket_count(); i++) {
				if (mymap.bucket_size(i) >= 2) 
					for (auto local_it = mymap.begin(i); local_it != mymap.end(i); ++local_it) 
						ret.push_back(strs[local_it->second]);
			}
			*/

			for (auto it = mymap.begin(); it != mymap.end(); it = mymap.equal_range(it->first).second) {
				auto key = it->first;
				if (mymap.count(key) > 1) {
					auto bounds = mymap.equal_range(key);
					for (auto jt = bounds.first; jt != bounds.second; ++jt)
						ret.push_back(strs[jt->second]);
				}
			}
			return ret;
		}
		void test() {
			vector<string> v;
			string s;
			/*
			v.push_back("");
			v.push_back("b");
			print1DVector(anagrams(v));
			*/
			int n;
			while (1) {
				cin >> n;
				for (int i = 0; i < n; i++) { 
					cin >> s;
					v.push_back(s);
				}
				print1DVector(anagrams(v));
				v.clear();

			}

		}
};
int main() {
	Solution s;
	s.test();
}
