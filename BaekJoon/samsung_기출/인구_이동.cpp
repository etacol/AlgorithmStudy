#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;


int city[50][50];
int city2[50][50];
int share[50][50];
bool visit[50][50];
int ans, shareVal;
int N, L, R;

//���� checker ���Ʒ��޿�
int xc[4] = { 0,0,-1,1 };
int yc[4] = { -1,1,0,0 };

//bfs!!
vector<pair<int, int>> bfs(int i, int j) {

	queue<pair<int, int>> q;
	vector<pair<int, int>> vp;
	memset(visit, 0, sizeof(visit)); //memset

	q.push({ i,j });
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second; //��ǥ ��
		q.pop();

		if (visit[y][x])
			continue;

		share[y][x] = shareVal;
		vp.push_back({ y,x });
		visit[y][x] = true; //visit set

		//�����¿� ���� check
		for (int i = 0; i < 4; i++) {
			int y2 = y+yc[i];
			int x2 = x + xc[i];

			int diff;
			// L<=diff<=R , ���� check -> ���漱 open
			if (y2 >= 0 && y2 < N &&x2 >= 0 && x2 < N && share[y2][x2] == -1) {

				//diff ���ϰ�
				if (city[y2][x2] > city[y][x])
					diff = city[y2][x2] - city[y][x];
				else
					diff = city[y][x]- city[y2][x2];

				if (diff >= L && diff <= R)
					q.push({ y2,x2 }); //shareval q
			}

		}

	}
	return vp;
}

int main(void) {

	
	scanf("%d %d %d", &N, &L, &R);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) 
			scanf("%d", &city[i][j]);

	
	bool flag = true;
	while (flag) {
	
		bool visited[50][50] = { 0, };
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++)
				city2[i][j] = city[i][j]; //copy
			
		shareVal = 1;
		flag = false; //ó�� notset
		memset(share, -1, sizeof(share)); //���漱 close
		shareVal = 1;
		//ó�� start
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (share[i][j] != -1) //shareVal check
					continue;
				shareVal = shareVal + 1;

				//���� ���� bfs
				vector<pair<int, int>> vpi = bfs(i, j);
				if (vpi.size() == 1) //���� ũ�� check
					continue;

				//�α� �̵� start
				flag = true; //ó�� set
				int c2=0;

				for (int l = 0; l < vpi.size(); l++)
					c2 += city2[vpi[l].first][vpi[l].second];

				c2 = c2 / vpi.size(); //�α� ����
				for (int l = 0; l < vpi.size(); l++)
					city2[vpi[l].first][vpi[l].second] = c2; //���� ����

			}
		}

		if (!flag)
			break;
		ans = ans + 1; //Ƚ�� +

		for (int i = 0; i < N; i++) 
			for (int j = 0; j < N; j++) 
				city[i][j] = city2[i][j];

	}


	printf("%d\n", ans);

	return 0;
}