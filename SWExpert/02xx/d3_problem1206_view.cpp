#include <iostream>

using namespace std;


int main(void) {
	
	int ans;
	int buildingNum;
	int * build_arr; 


	for (int i = 1; i <= 10; i++) { //10ȸ �ݺ�
		
		cin >> buildingNum; //������ �Է�
		build_arr = new int[buildingNum]; //������ container ����

		ans = 0;
		for (int j = 0; j < buildingNum; j++) {
			cin >> build_arr[j]; //�� ���� ���� �Է¹���
		}

		
		//��2, ��2 ��4�� ������ Ű�� ���� �� Ű�� �� ũ�� ������ Ȯ�� check
		for (int b = 2; b < buildingNum - 2; b++) {
			int length = build_arr[b]; //������ check �� ���� ����(����)

			while (length != 0) { //length-- �� �ؾ��� ������ �˻�
				//��2��2 �� length ��
				if (length > build_arr[b - 1] && length > build_arr[b + 1]&& length > build_arr[b - 2] && length > build_arr[b + 2]) {

					
						ans++; // ������ Ȯ���� ���� check
						length--;
				}
				else {
				
					break;
				}

			}
		}

		//���
		cout << "#" << i << " " << ans << endl;

	}
	return 0;
}