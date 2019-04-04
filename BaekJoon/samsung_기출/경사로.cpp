#include <iostream>
#include <stdio.h>
using namespace std;

int N, L;
int ans = 0;
int map[100][100]; //지도


int main(void) {

	scanf("%d %d", &N, &L);
	
	for (int i = 0; i < N; i++) { //칸 높이 입력 받고
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	//simul
	for (int i = 0; i < N; i++) {
		
		//가로길
		int chk = 1; // 연속 same level 체크
		for (int j = 0; j < N-1; j++) {
			if (map[i][j] == map[i][j + 1]) { //same level 이면
				chk++; 
			}
			else if ((map[i][j] - map[i][j + 1] == -1) && (chk >= L)) {
				//오르막 && 연속으로 같은 높이 L 이상 이어졌다면
				//경사로 놓고 지나가고
				chk = 1; //연속 same level 다시 1 set

			}
			else if ((map[i][j] - map[i][j + 1] == 1) && (chk > -1)) {
				//내리막 && chk -1 보다 크면
				//앞으로의 같은층수 확보여부에 따라 결정. 미루기
				chk = 1 - L;
			}
			else {
				chk = -1; //못 놔 못 건너
				break;
			}
		}

		//길 다 건너면 chk value check
		if (chk >= 0) ans++;


		//세로길
		chk = 1; // 연속 same level 체크
		for (int j = 0; j < N-1; j++) {
			if (map[j][i] == map[j + 1][i]) { //same level 이면
				chk++;
			}
			else if ((map[j][i] - map[j + 1][i] == -1) && (chk >= L)) {
				//오르막 && 연속으로 같은 높이 L 이상 이어졌다면
				//경사로 놓고 지나가고
				chk = 1; //연속 same level 다시 1 set

			}
			else if ((map[j][i] - map[j + 1][i] == 1) && (chk > -1)) {
				//내리막 && chk -1 보다 크면
				//앞으로의 같은층수 확보여부에 따라 결정. 미루기
				chk = 1 - L;
			}
			else {
				chk = -1; //못 놔 못 건너
				break;
			}
		}

		//길 다 건너면 chk value check
		if (chk >= 0) ans++;

	}

	//ans 출력
	printf("%d\n", ans);
	return 0;
}