#include <iostream>
using namespace std;

//5개중 3개 맞고 런타임에러ㅜ
/*
오답
채점용 input 파일로 채점한 결과 fail 입니다.
(오답 : 5개의 테스트케이스 중 3개가 맞았습니다.)

런타임 에러가 발생하였습니다. 런타임 에러로 전체 혹은 일부 테스트 케이스는 채점이 되지 않을 수 있습니다.
Error Message :
Runtime Error!

*/

int main(void) {



	int T;
	cin >> T;


	for (int k = 1; k <= T; k++) {
		int N, Q;
		cin >> N >> Q;



		int cow[N + 1];
		int L[Q], R[Q];

		int one[Q], two[Q], thr[Q];

		for (int i = 1; i <= N; i++) { //N개 소 품종 입력받
			cin >> cow[i];
		}

		for (int j = 0; j < Q; j++) { //문제 입력받
			cin >> L[j] >> R[j];

			one[j] = 0;
			two[j] = 0;
			thr[j] = 0;

			for (int i = L[j]; i <= R[j]; i++) { //품종 수 구하기
				if (cow[i] == 1) {
					one[j]++;
				}
				else if (cow[i] == 2) {
					two[j]++;
				}
				else {
					thr[j]++;
				}
			}

		}
		//답 출력
		cout << "#" << k << endl;
		for (int j = 0; j < Q; j++) {
			cout << one[j] << " " << two[j] << " " << thr[j] << endl;
		}

	}

}