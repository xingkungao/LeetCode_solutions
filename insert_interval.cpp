/*************************************************************************
  > File Name: insert_interval.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Fri 02 Jan 2015 09:51:57 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;
/**
 *
 *  * Definition for an interval.
 */
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
	public:
		vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
			vector<Interval> ret;
			if (intervals.empty()) {
				intervals.insert(intervals.begin(), newInterval);
				return intervals;
			}

			for (int i = 0; i < intervals.size(); i++) {
				if (intervals[i].end < newInterval.start) {
					ret.push_back(intervals[i]);
				}
				else if (intervals[i].start > newInterval.end) {

					ret.push_back(newInterval);
					newInterval = intervals[i];
				}
				else  {
					newInterval.start = min(newInterval.start, intervals[i].start);
					newInterval.end = max(newInterval.end, intervals[i].end);
				}
			}
			ret.push_back(newInterval);
			return ret;
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
				cout << endl;
				cin >> a.start >> a.end;
				print(insert(v, a));
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
