// uva-540-team queue.cpp : �������̨Ӧ�ó������ڵ㡣
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
//���ж��ж���front�� rear��
// �ӺŵĶ�������ͳ������Щ�ӽ�����ܵĶ���
int TeamQueue[1010];
// ���������Щ���Ѿ���������ܶ���
int TeamVis[1010];
// �ӺŶ��еĶ�β
int teamFront;
// �ӺŶ��еĶ�ͷ
int teamRear;
// ����Ĳ�ͬ�Ķӵĳ�Ա����
int EveryTeamQueue[1010][1010];
// ������ͬ�ӵĶ��еĶ�β
int everyTeamFront[1010];
// ������ͬ�ӵĶ��еĶ�ͷ
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
				dataMap.insert(make_pair(temp, i));//Ԫ����ӺŽ�������
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
				int teamNum;//���
				if (strcmp(input, "DEQUEUE") != 0) {
					int num;
					char cmd[20];
					sscanf(input, "%s %d", cmd, &num);
					teamNum = dataMap[num];//���Ԫ�����ڵĶӺ�
					if (!TeamVis[teamNum]) {
						// �Ӻ���ӵĶ���
						TeamQueue[teamFront++] = teamNum;//�Ӻ����  ��front��
						// ��Ǹö��Ѿ��ڶӵĶ�����
						TeamVis[teamNum] = 1;
					}
					// �Ѷӵ�Ԫ������Ӧ�ĶӵĶ���
					EveryTeamQueue[teamNum][everyTeamFront[teamNum]++] = num;//ÿ���Ӷ�Ҳ��front��
				}
				else//����  ��rear�˳�
				{
					// ��ȡ��ǰ�ڶӺŶ��еĶ�ͷ�ĶӺš�
					teamNum = TeamQueue[teamRear + 1];
					// ���ݻ�ȡ�ĶӺ�����ö����еĶ�ͷ����
					cout << EveryTeamQueue[teamNum][++everyTeamRear[teamNum]] << endl;
					// ���������ݺ�ö��б����ӶӺŶ�����ɾ���öӺ�
					// �ѸöӺŴӱ��������ȥ��������Ϊ�㣩
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



