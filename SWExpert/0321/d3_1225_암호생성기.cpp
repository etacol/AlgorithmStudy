
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

//첫번째숫자 1감소-> 맨뒤로, 그다음첫번째숫자 2감소 ...5감소까지! 1cycle
//숫자 감소시켰는데 0보다 작아지면 0set->맨뒤로-> 프로그램 종료!! 종료 조건

int raw[8] = { 0, }; //raw data
int temp;



int main(void) {

	//테케 10개
	for (int i = 1; i <= 10; i++) {
		int flag = false; //종료 flag
		int t;
		scanf("%d", &t); //tc num

		for (int j = 0; j < 8; j++) {//raw data 입력받음
			scanf("%d", &raw[j]);
		}

		// cycle 반복
		while (1) {
			//1 cycle
			for (int j = 1; j <= 5; j++) {
				temp = raw[0] - j;

				if (temp <= 0) { //0보다 작으면 0set & 종료 flag set
					temp = 0;
					flag = true;
				}

				for (int k = 1; k < 8; k++) { //한칸씩 shift
					raw[k - 1] = raw[k];
				}

				raw[7] = temp; //감소값 맨뒤로!

				if (flag) break;  //cycle break
			}

			if (flag) break; //while break
		}

		//답 출력
		cout << "#" << i << " ";
		for (int j = 0; j < 8; j++) {
			cout << raw[j] << " ";
		}
		cout << endl;
		memset(raw, 0, sizeof(int) * 8); //raw data 초기화
	}


	return 0;
}
