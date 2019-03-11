#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int>> v;
int ans;


void pathYN(int p) {

	if (p == 99) //99 ���� ���� pass 1
		ans = 1;

	//0������ �� ���󰡸鼭 check
	for (int k = 0; k < v[p].size(); k++) {
		int p2 = v[p][k];
		pathYN(p2);
	}
}

int main(void) {


	for (int i = 1; i <= 10; i++) {

		int tcn, num;
		scanf("%d %d", &tcn, &num);

		v.resize(num); //�ʱ�ȭ

		for (int j = 0; j < num; j++) { //������ ������ŭ
			int point, way;

			scanf("%d %d", &point, &way); //������ �� �Է¹�

			v[point].push_back(way);   //������ �� push
		}


		//�� �ִ��� ���� Ȯ��
		pathYN(0);

		printf("#%d %d\n", tcn, ans);
		v.clear(); //�ʱ�ȭ
		ans = 0; //�ٽ� 0 set
	}

	return 0;
}