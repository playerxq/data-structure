// leetcode-352-类似线段树.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <unordered_map>
#include <stack>
#include<iomanip>
#include <ctype.h>
#include <algorithm>
using namespace std;
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
class SummaryRanges {
private:
	vector<Interval> intervals = vector<Interval>();

	int binarySearch(vector<Interval> intervals, int val) {
		return binarySearchHelper(intervals, 0, intervals.size(), val);
	}

	int binarySearchHelper(vector<Interval> intervals, int start, int end, int val) {
		if (start == end) return -1;
		if (start + 1 == end && intervals[start].start < val) return start;

		int mid = (start + end) / 2;
		if (intervals[mid].start == val) {
			return mid;
		}
		else if (intervals[mid].start < val) {
			return binarySearchHelper(intervals, mid, end, val);
		}
		else { //intervals[mid] > val
			return binarySearchHelper(intervals, start, mid, val);
		}
	}

public:
	/** Initialize your data structure here. */
	SummaryRanges() {

	}

	/** For a new number n, find the last(biggest) interval
	*  [s,t], such that s < n. If no such interval exists,
	*  return -1.
	*/
	void addNum(int val) {
		int index = binarySearch(intervals, val);

		// intervals[index] contains val
		if (index != -1 && intervals[index].end >= val) {
			return;
		}

		if (index != intervals.size() - 1 && val + 1 == intervals[index + 1].start) {
			intervals[index + 1].start = val;
		}
		else if (index != -1 && val - 1 == intervals[index].end) {
			intervals[index].end = val;
		}
		else {
			intervals.insert(intervals.begin() + index + 1, Interval(val, val));
		}

		//merge intervals[index] with intervals[index+1]
		if (index != -1 && intervals[index].end + 1 == intervals[index + 1].start) {
			intervals[index].end = intervals[index + 1].end;
			intervals.erase(intervals.begin() + index + 1);
		}

		return;
	}

	vector<Interval> getIntervals() {
		return this->intervals;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

