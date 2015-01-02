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
			int a = newInterval.start;
			int b = newInterval.end;
			int left, right;


			int l = 0, r = intrvals.size() -1, mid;
			while (l < r) {
				mid = (l + r) / 2;
				if (intervals[mid].start < a)
					l = mid + 1;
				else 
					r = mid;
			}
			left = l;
			r = intervals.size();
			while (l < r) {
				mid = (l + r) / 2;
				if (intervals[mid].start > a)
					r = mid - 1;
				else 
					l = mid;
			}
			right = l;

			if (idxl == idxr)
				intervals.insert(intervals.begin() + l, newInterval);
			else {
				if (idxl;

			}
		}
};

int main() {
	Solution s;
	s.test();
}
