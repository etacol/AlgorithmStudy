#include <iostream>
#include <string>
using namespace std;

//�νĿ��� ���� �����
//���� : a e i o u
//���� 50���� �ҹ��� �ܾ� , (���� ����) >=1
//���� �ν��ϴ� �ܾ� ���

int s; //word size

int main(void) {

	int T; //���� num
	cin >> T;

	for (int i = 1; i <= T; i++) {
		string word;
		cin >> word;
		s = word.size();

		cout << "#" << i << " "; //#T

		for (int j = 0; j < s; j++) { //�ܾ� �ν� ����

			if (!(word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u')) { //������ ���� �ν�
				cout << word[j];
			}

		}
		//�ܾ� ��� ��
		cout << endl;
	}

	return 0;
}