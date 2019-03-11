#include <stdio.h>
using namespace std;

int month[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
int temp; //일 수 총합 
int dayname; //요일

int main(void) {



	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		int m, d;

		scanf("%d %d", &m, &d);

		for (int j = 1; j < m; j++) {
			temp += month[j]; //한달씩의 일 수 더하구
		}

		temp += d; //일 수 더함

		dayname = (temp + 4 - 1) % 7;   //요일 구함 -1 !!

		printf("#%d %d \n", i, dayname);

		//값 초기화
		temp = 0;
		dayname = 0;

	}

	return 0;
}