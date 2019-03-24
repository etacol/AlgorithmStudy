#include <stdio.h>
#include <iostream>
using namespace std;

int N, M, H;
int point[31][11]; //H N !!!!
int ans; //��


int game() {

	int pass = 1; //���� ���� ����

	for (int i = 1; i <= N; i++) {
		int now = i;

		for (int j = 1; j <= H; j++) {
			if (point[j][now] == 1) { //���� ������ ���׾��� ������
				now = now + 1; //����������
			}
			else if (point[j][now - 1] == 1) { //���� ������ ���׾��� ������
				now = now - 1; //��������
			}
		}
		//���� ���� ����
		if (now != i) {
			pass = 0;
			return pass;
		}
	}

	return pass;

}

void dfs(int cnt, int aa, int bb) {


	if (cnt >= 4) return;

	//��ٸ� ���� start
	if (game() == 1) {
		if (cnt < ans) //���� ���̸� �� set
			ans = cnt;

		return;
	}

	//���� ���� & �� 3��
	if (cnt == 3)
		return;


	//��ٸ� ���� - ������ �ɸ��� ���μ��� ������ ������ ��� ���߱�
	for (int i = aa; i <= H; i++) {
		for (int j = bb; j < N; j++) { //N���� ���������� ���μ� ���ߴ´� j<N
			//���� �� && ������ �޿� ������ �� �ȱ׾��� ������
			if ((point[i][j] == 0) && (point[i][j - 1] == 0) && (point[i][j + 1] == 0)) {
				point[i][j] = 1; //���߱�
				dfs(cnt + 1, i, j);
				point[i][j] = 0; //reset
			}
		}
		bb = 1;

	}
}

int main(void) {

	int a, b;
	scanf("%d %d %d", &N, &M, &H);

	for (int i = 0; i < M; i++) { //���μ� ���� �Է� ����
		scanf("%d %d", &a, &b);
		point[a][b] = 1; // a ��ġ���� b~b+1 ����!
	}

	ans = 4;
	dfs(0, 1, 1);

	if (ans == 4)
		ans = -1;
	printf("%d\n", ans); //�� ���


	return 0;
}