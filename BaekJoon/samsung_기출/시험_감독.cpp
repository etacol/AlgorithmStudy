#include <stdio.h>
#include <iostream>
using namespace std;

long long ans;

int main(void) {

	int N;
	scanf("%d", &N);

	int * test = new int[N];

	for (int i = 0; i < N; i++) { //�� ������ ������ �� �Է� ��
		scanf("%d", &test[i]);
	}

	int chong, bu; //�Ѱ��� �ΰ��� �Է� ��
	scanf("%d %d", &chong, &bu);

	for (int i = 0; i < N; i++) { //�Ѱ��� Ŀ�� �ο� ��
		test[i] = test[i] - chong;
		ans++;

		if (test[i] <= 0) {
			//do nothing
		}
		else if (test[i] > 0) { //�ΰ��� ����
			int buR = test[i] % bu;
			int buN = test[i] / bu;

			if (buR == 0) { //remainder 0 
				ans = ans + buN;
			}
			else { //remainder 0�ƴϸ� +1
				ans = ans + buN + 1;
			}
		}
	}

	printf("%lld\n", ans);
	delete[] test;
	test = NULL;
	return 0;
}