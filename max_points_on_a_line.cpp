/*************************************************************************
  > File Name: max_points_on_a_line.cpp
  > Author: lax
  > Mail: xingkungao@gmail.com
  > Created Time: Tue 02 Dec 2014 03:11:42 PM CST
 ************************************************************************/

#include "CPP.h"
#include "utility.h"
using namespace std;

/**
 *
 *  * Definition for a point.
 */
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

struct Line{
	int a, b;
	double c;
	Line() : a(0), b(0), c(0){}
	Line(Point l, Point r) {
		if (r.x - l.x == 0) {
			a = INT_MAX; 
			b = 1;
			c = l.x;
		}
		else {
			int d = gcd(abs(r.y - l.y), abs(r.x - l.x));
			a = abs(r.y - l.y) / d;
			b = abs(r.x - l.x) / d;
			if (r.y-l.y < 0 ^ r.x - l.x < 0)
				a = -a;
			if (b) 
//				c = r.y - r.x * (double)a / (double)b;
				c = b * r.y - r.x * (double)a; 
		}
	}

	int gcd(int a, int b) {
		if (b == 0)
			return a;
		else return gcd(b, a%b);
	}

};
bool operator < (const Line &l, const Line &r) {
	if (l.a / l.b < r.a / r.b)
		return true;
	else if (l.a / l.b == r.a / r.b && l.c < r.c)
		return true;
	return false;
}

class Solution {
	public:
		int maxPoints(vector<Point> &points) {
			int ret = 0;
			int dup;
			int m;
			if (points.size() < 3)
				return points.size();
			for (int i = 0; i < points.size(); i++) {
				dup = 0;
				m = 0;
				map<Line, int> lines;
				for (int j = i + 1; j < points.size(); j++) {
					if (points[i].x == points[j].x && points[i].y == points[j].y) {
						dup++;
					}
					else {
						Line l(points[i], points[j]);
						lines[l]++;
					}
				}
				for (auto it = lines.begin(); it != lines.end(); ++it) {
					m = max(m, it->second);
				}
				ret = max(ret, m + 1 + dup);
			}
			return ret;
		}

		void test() {
			vector<Point> v;
			v.push_back(Point(3, 1));
			v.push_back(Point(12, 3));
			v.push_back(Point(3, 1));
			v.push_back(Point(-6, -1));
			cout << maxPoints(v) << endl;
		}
};

int main() {
	Solution s;
	s.test();
}

