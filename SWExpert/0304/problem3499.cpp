#include <iostream>
#include <string>
using namespace std;

int half;
string ans;

int main() {

	int tc, cardN;
	cin >> tc;

	//tc ������ŭ
	for (int i = 1; i <= tc; i++) {



		//int cardN; //ī�� ����
		cin >> cardN;

		string shuffle1[cardN]; //����


		for (int j = 0; j <cardN; j++) {//ī�� �Է¹���
			cin >> shuffle1[j];
		}

		if ((cardN % 2) == 0)  //ī�尹�� ¦��
			half = cardN / 2;

		else
			half = (cardN / 2) + 1;


		for (int j = 0; j < half; j++) {

			if (((cardN % 2) == 1) && (j == (half - 1))) { //cardNum Ȧ���� ������ �����϶�
				ans += " " + shuffle1[j]; //���� �����ʸ�
			}
			else {
				ans += " " + shuffle1[j] + " " + shuffle1[half + j]; //���� ����
			}
		}

		cout << "#" << i << ans << endl;
		ans = "";

	}
	return 0;
}
