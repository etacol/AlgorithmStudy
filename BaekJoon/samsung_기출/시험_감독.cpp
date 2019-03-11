#include <stdio.h>
#include <iostream>
using namespace std;

long long ans;

int main(void) {

	int N;
	scanf("%d", &N);

	int * test = new int[N];

	for (int i = 0; i < N; i++) { //각 시험장 응시자 수 입력 받
		scanf("%d", &test[i]);
	}

	int chong, bu; //총감독 부감독 입력 받
	scanf("%d %d", &chong, &bu);

	for (int i = 0; i < N; i++) { //총감독 커버 인원 뺌
		test[i] = test[i] - chong;
		ans++;

		if (test[i] <= 0) {
			//do nothing
		}
		else if (test[i] > 0) { //부감독 배정
			int buR = test[i] % bu;
			int buN = test[i] / bu;

			if (buR == 0) { //remainder 0 
				ans = ans + buN;
			}
			else { //remainder 0아니면 +1
				ans = ans + buN + 1;
			}
		}
	}

	printf("%lld\n", ans);
	delete[] test;
	test = NULL;
	return 0;
}