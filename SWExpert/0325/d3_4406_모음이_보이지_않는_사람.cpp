#include <iostream>
#include <string>
using namespace std;

//인식에서 모음 사라짐
//모음 : a e i o u
//길이 50이하 소문자 단어 , (자음 갯수) >=1
//내가 인식하는 단어 출력

int s; //word size

int main(void) {

	int T; //테케 num
	cin >> T;

	for (int i = 1; i <= T; i++) {
		string word;
		cin >> word;
		s = word.size();

		cout << "#" << i << " "; //#T

		for (int j = 0; j < s; j++) { //단어 인식 시작

			if (!(word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u')) { //자음일 때만 인식
				cout << word[j];
			}

		}
		//단어 출력 끝
		cout << endl;
	}

	return 0;
}