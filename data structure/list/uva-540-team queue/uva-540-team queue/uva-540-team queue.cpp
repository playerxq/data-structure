// uva-540-team queue.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct cmp {
	bool operator () (const int & a, const int & b) {
		return a < b;
	}
};
//所有队列都从front入 rear出
// 队号的队列用来统计有哪些队进入的总的队列
int TeamQueue[1010];
// 用来标记那些队已经进入的了总队列
int TeamVis[1010];
// 队号队列的队尾
int teamFront;
// 队号队列的队头
int teamRear;
// 具体的不同的队的成员队列
int EveryTeamQueue[1010][1010];
// 各个不同队的队列的队尾
int everyTeamFront[1010];
// 各个不同队的队列的队头
int everyTeamRear[1010];

int main()
{
	int t;
	int count = 0;
#ifndef ONLINE_JUDGE
	freopen("540.txt", "r", stdin);
#endif
	while (cin >> t) {
		if (t == 0) break;
		map<int, int, cmp> dataMap;
		int i, j;
		for (i = 0; i < t; i++) {
			int k;
			cin >> k;
			for (j = 0; j < k; j++) {
				int temp;
				cin >> temp;
				dataMap.insert(make_pair(temp, i));//元素与队号建立关联
			}
		}
		char input[50];
		gets(input);
		cout << "Scenario #" << ++count << endl;
		
		memset(TeamVis, 0, sizeof(TeamVis));
		teamFront = 0;
		teamRear = -1;
		memset(everyTeamFront, 0, sizeof(everyTeamFront));
		memset(everyTeamRear, -1, sizeof(everyTeamRear));
		while (gets(input)) {
			if (strcmp(input, "STOP") == 0) {
				cout << endl;
				break;
			} 
			else 
			{
				int teamNum;//入队
				if (strcmp(input, "DEQUEUE") != 0) {
					int num;
					char cmd[20];
					sscanf(input, "%s %d", cmd, &num);
					teamNum = dataMap[num];//入队元素所在的队号
					if (!TeamVis[teamNum]) {
						// 队号入队的队列
						TeamQueue[teamFront++] = teamNum;//队号入队  从front入
						// 标记该队已经在队的队列中
						TeamVis[teamNum] = 1;
					}
					// 把队的元素入相应的队的队列
					EveryTeamQueue[teamNum][everyTeamFront[teamNum]++] = num;//每个子队也从front入
				}
				else//出队  从rear端出
				{
					// 获取当前在队号队列的队头的队号。
					teamNum = TeamQueue[teamRear + 1];
					// 根据获取的队号输出该队列中的队头数据
					cout << EveryTeamQueue[teamNum][++everyTeamRear[teamNum]] << endl;
					// 如果输出数据后该队列变空则从队号队列中删除该队号
					// 把该队号从标记数组中去除（即设为零）
					if (everyTeamFront[teamNum] - everyTeamRear[teamNum] == 1) {
						teamRear++;
						TeamVis[teamNum] = 0;
					}
				}
			}
		}
	}
	return 0;
}



