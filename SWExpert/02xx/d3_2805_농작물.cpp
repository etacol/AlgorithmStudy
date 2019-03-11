#include <iostream>
using namespace std;




int main(void) {
	int tc;
	cin >> tc;


	for (int k = 1; k <= tc; k++) { //testcase 갯수만큼
		int N;
		cin >> N;

		int arr[50][50] = {};

		int sumVal = 0; // ㅡㅠㅡ..
		int base = (N - 1) / 2; //기준


		for (int i = 0; i <N; i++) { //가치 입력받고
			for (int j = 0; j <N; j++) {
				scanf("%1d", &arr[i][j]);
			}
		}
		int first = 1;





		//base 기준으로 가치 더하기
		for (int i = 0; i <= base; i++) {
			for (int j = 0; j < first; j++) {
				//cout << arr[i][base - i + j] << " ";
				//cout << arr[N-1-i][base - i + j] << " ";
				sumVal += arr[i][base - i + j];
				sumVal += arr[N - 1 - i][base - i + j];
			}
			first += 2;

		}

		for (int i = 0; i < N; i++) {
			sumVal -= arr[base][i];
		}




		//출력
		cout << "#" << k << " " << sumVal << endl;




	}
}