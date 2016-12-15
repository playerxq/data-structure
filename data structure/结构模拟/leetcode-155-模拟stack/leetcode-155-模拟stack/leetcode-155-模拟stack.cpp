// leetcode-155-模拟stack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class MinStack {
public:
    vector<int> a;
    vector<int> min;
    MinStack() {
        min.push_back(2147483647);
    }
    void push(int x) {
        a.push_back(x);
        if (x < min.back()) {
            min.push_back(x);
        } else {
            min.push_back(min.back());
        }
    }

    void pop() {
        a.pop_back();
        min.pop_back();
    }

    int top() {
        return a.back();
    }

    int getMin() {
        return min.back();
    }
};
int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

