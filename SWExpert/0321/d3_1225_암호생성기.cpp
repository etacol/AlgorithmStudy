
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

//ù��°���� 1����-> �ǵڷ�, �״���ù��°���� 2���� ...5���ұ���! 1cycle
//���� ���ҽ��״µ� 0���� �۾����� 0set->�ǵڷ�-> ���α׷� ����!! ���� ����

int raw[8] = { 0, }; //raw data
int temp;



int main(void) {

	//���� 10��
	for (int i = 1; i <= 10; i++) {
		int flag = false; //���� flag
		int t;
		scanf("%d", &t); //tc num

		for (int j = 0; j < 8; j++) {//raw data �Է¹���
			scanf("%d", &raw[j]);
		}

		// cycle �ݺ�
		while (1) {
			//1 cycle
			for (int j = 1; j <= 5; j++) {
				temp = raw[0] - j;

				if (temp <= 0) { //0���� ������ 0set & ���� flag set
					temp = 0;
					flag = true;
				}

				for (int k = 1; k < 8; k++) { //��ĭ�� shift
					raw[k - 1] = raw[k];
				}

				raw[7] = temp; //���Ұ� �ǵڷ�!

				if (flag) break;  //cycle break
			}

			if (flag) break; //while break
		}

		//�� ���
		cout << "#" << i << " ";
		for (int j = 0; j < 8; j++) {
			cout << raw[j] << " ";
		}
		cout << endl;
		memset(raw, 0, sizeof(int) * 8); //raw data �ʱ�ȭ
	}


	return 0;
}
