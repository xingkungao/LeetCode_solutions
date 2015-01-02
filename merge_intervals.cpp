/*************************************************************************
  > File Name: merge_intervals.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Fri 02 Jan 2015 09:16:32 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
/**
 *
 *Definition for an interval.
 */

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
	public:
		vector<Interval> merge(vector<Interval> &intervals) {
			sort(intervals.begin(), intervals.end(), compare);
			vector<Interval> ret;
			for (int i = 0; i < intervals.size(); i++) {
				if (ret.empty())
					ret.push_back(intervals[i]);
				else {
					if (ret.back().start == intervals[i].start)
						ret.back().end = max(ret.back().end, intervals[i].end);
					else if (ret.back().end < intervals[i].start) {
						ret.push_back(intervals[i]);
					}
					else if (ret.back().end >= intervals[i].start && ret.back().end < intervals[i].end) {
						ret.back().end = intervals[i].end;
					}
				}
			}
			return ret;
		}
		static bool compare(Interval a, Interval b) {
			return (a.start < b.start);
		}
		void test() {
			vector<Interval> v;
			int n;
			Interval a;
			while (1) {
				cin >> n;
				for (int i = 0; i < n; i++) {
					cin >> a.start >> a.end;
					v.push_back(a);
				}
				print(merge(v));
				v.clear();

			}
		}
		void print(const vector<Interval>& v) {
			for (int i = 0; i < v.size(); i++) {
				cout << "(" << v[i].start << "," << v[i].end << ")" << "    "; 
			}
			cout << endl;
		}

};


int main() {
	Solution s;
	s.test();
}
