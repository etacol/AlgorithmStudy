#include <iostream>
#include <stdio.h>
using namespace std;

int N, L;
int ans = 0;
int map[100][100]; //����


int main(void) {

	scanf("%d %d", &N, &L);
	
	for (int i = 0; i < N; i++) { //ĭ ���� �Է� �ް�
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	//simul
	for (int i = 0; i < N; i++) {
		
		//���α�
		int chk = 1; // ���� same level üũ
		for (int j = 0; j < N-1; j++) {
			if (map[i][j] == map[i][j + 1]) { //same level �̸�
				chk++; 
			}
			else if ((map[i][j] - map[i][j + 1] == -1) && (chk >= L)) {
				//������ && �������� ���� ���� L �̻� �̾����ٸ�
				//���� ���� ��������
				chk = 1; //���� same level �ٽ� 1 set

			}
			else if ((map[i][j] - map[i][j + 1] == 1) && (chk > -1)) {
				//������ && chk -1 ���� ũ��
				//�������� �������� Ȯ�����ο� ���� ����. �̷��
				chk = 1 - L;
			}
			else {
				chk = -1; //�� �� �� �ǳ�
				break;
			}
		}

		//�� �� �ǳʸ� chk value check
		if (chk >= 0) ans++;


		//���α�
		chk = 1; // ���� same level üũ
		for (int j = 0; j < N-1; j++) {
			if (map[j][i] == map[j + 1][i]) { //same level �̸�
				chk++;
			}
			else if ((map[j][i] - map[j + 1][i] == -1) && (chk >= L)) {
				//������ && �������� ���� ���� L �̻� �̾����ٸ�
				//���� ���� ��������
				chk = 1; //���� same level �ٽ� 1 set

			}
			else if ((map[j][i] - map[j + 1][i] == 1) && (chk > -1)) {
				//������ && chk -1 ���� ũ��
				//�������� �������� Ȯ�����ο� ���� ����. �̷��
				chk = 1 - L;
			}
			else {
				chk = -1; //�� �� �� �ǳ�
				break;
			}
		}

		//�� �� �ǳʸ� chk value check
		if (chk >= 0) ans++;

	}

	//ans ���
	printf("%d\n", ans);
	return 0;
}