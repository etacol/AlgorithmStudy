#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;



//�̷�
int maze[100][100];
bool visited[100][100];
pair<int, int> start;

//���� checker ���Ʒ��޿�
int xcheck[4] = {0,0,-1,1};
int ycheck[4] = { -1,1,0,0 };

int ans = 0; //�� container




//���� ��� ���翩�� sol
void maze_possible(int x1, int y1) {

	if (maze[x1][y1] == 3) { //�������� ����
		ans = 1;
		return;
	}

	visited[x1][y1] = true; //visited check

	// �������� check
	for (int i = 0; i < 4; i++) {
		int x2 = x1 + xcheck[i];
		int y2 = y1 + ycheck[i];

		//1. �̷� �ȿ� �ְ� 2. visit ���߰� 3. ���� �ƴϸ� continue
		if ((x2 < 100) && (y2 < 100) && (visited[x2][y2] == false) && (maze[x2][y2] == 0) || (maze[x2][y2] == 3)) {
			maze_possible(x2, y2);
		}
		//x2>-1 y2>-1 �� ����� �� �� ����.
	}


}

int main(void) {
	

	//test case 10��
	for(int tc = 1; tc<=10; tc++) {
		ans = 0;
		int num;
		cin >> num; //test case container
		
		
		// �̷� �� �ְ� ������ ã�� (0,0)~(99,99)
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				scanf("%1d", &maze[i][j]);

				if (maze[i][j] == 2) { //if������
					start = make_pair(i, j);
				}
			}
		}

		//���� ��� ���� ã�� ���
		maze_possible(start.first, start.second);

		printf("#%d %d\n", tc, ans);
	


		//memset
		memset(maze, 0, sizeof(maze));
		memset(visited, 0, sizeof(visited));

	}

	return 0;
}
