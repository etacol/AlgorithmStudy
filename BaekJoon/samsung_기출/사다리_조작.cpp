#include <stdio.h>
#include <iostream>
using namespace std;

int N, M, H;
int point[31][11]; //H N !!!!
int ans; //답


int game() {

	int pass = 1; //조작 성공 여부

	for (int i = 1; i <= N; i++) {
		int now = i;

		for (int j = 1; j <= H; j++) {
			if (point[j][now] == 1) { //현재 점에서 선그어져 있으면
				now = now + 1; //오른쪽으로
			}
			else if (point[j][now - 1] == 1) { //왼쪽 점에서 선그어져 있으면
				now = now - 1; //왼쪽으로
			}
		}
		//조작 성공 여부
		if (now != i) {
			pass = 0;
			return pass;
		}
	}

	return pass;

}

void dfs(int cnt, int aa, int bb) {


	if (cnt >= 4) return;

	//사다리 게임 start
	if (game() == 1) {
		if (cnt < ans) //최적 값이면 답 set
			ans = cnt;

		return;
	}

	//조작 실패 & 선 3개
	if (cnt == 3)
		return;


	//사다리 조작 - 점선에 걸리는 세로선의 점에서 가능한 경우 선긋기
	for (int i = aa; i <= H; i++) {
		for (int j = bb; j < N; j++) { //N에서 오른쪽으로 가로선 못긋는다 j<N
			//현재 점 && 나란히 왼오 점에서 선 안그어져 있을때
			if ((point[i][j] == 0) && (point[i][j - 1] == 0) && (point[i][j + 1] == 0)) {
				point[i][j] = 1; //선긋기
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

	for (int i = 0; i < M; i++) { //가로선 정보 입력 받음
		scanf("%d %d", &a, &b);
		point[a][b] = 1; // a 위치에서 b~b+1 연결!
	}

	ans = 4;
	dfs(0, 1, 1);

	if (ans == 4)
		ans = -1;
	printf("%d\n", ans); //답 출력


	return 0;
}