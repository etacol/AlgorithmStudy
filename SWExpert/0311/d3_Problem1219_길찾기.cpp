#include <stdio.h>
#include <vector>
using namespace std;

vector<vector<int>> v;
int ans;


void pathYN(int p) {

	if (p == 99) //99 지점 오면 pass 1
		ans = 1;

	//0번부터 길 따라가면서 check
	for (int k = 0; k < v[p].size(); k++) {
		int p2 = v[p][k];
		pathYN(p2);
	}
}

int main(void) {


	for (int i = 1; i <= 10; i++) {

		int tcn, num;
		scanf("%d %d", &tcn, &num);

		v.resize(num); //초기화

		for (int j = 0; j < num; j++) { //순서쌍 갯수만큼
			int point, way;

			scanf("%d %d", &point, &way); //정점과 길 입력받

			v[point].push_back(way);   //정점에 길 push
		}


		//길 있는지 여부 확인
		pathYN(0);

		printf("#%d %d\n", tcn, ans);
		v.clear(); //초기화
		ans = 0; //다시 0 set
	}

	return 0;
}