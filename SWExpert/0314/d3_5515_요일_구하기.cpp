#include <stdio.h>
using namespace std;

int month[13] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };
int temp; //�� �� ���� 
int dayname; //����

int main(void) {



	int T;
	scanf("%d", &T);

	for (int i = 1; i <= T; i++) {
		int m, d;

		scanf("%d %d", &m, &d);

		for (int j = 1; j < m; j++) {
			temp += month[j]; //�Ѵ޾��� �� �� ���ϱ�
		}

		temp += d; //�� �� ����

		dayname = (temp + 4 - 1) % 7;   //���� ���� -1 !!

		printf("#%d %d \n", i, dayname);

		//�� �ʱ�ȭ
		temp = 0;
		dayname = 0;

	}

	return 0;
}