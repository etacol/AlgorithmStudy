#include <iostream>
#include <vector>

using namespace std;


//좌표 class
typedef struct point {

	int x, y;
	bool visit;
}point;

int ans; //답 


//최적 경로 search
void searchDist(vector<point> &p, int n, int N, int dist, int before) {

	if (n == N) { //terminate cond
		//N번째 고객집에서 내집으로
		dist = dist+ abs(p[1].x - p[before].x) + abs(p[1].y - p[before].y);

		if (ans > dist) { //dist 가 더 짧
			ans = dist;
		}
		return;
	}


	//회사 - 1번째고객- 2번째고객 - and so on
	for (int i = 2; i < p.size(); i++) {

		if (p[i].visit == false) { 
			p[i].visit = true; //방문 check
			
			// 거리 쌓아서 다음 집으로
			searchDist(p, n + 1, N, dist + abs(p[i].x - p[before].x) + abs(p[i].y - p[before].y), i); 

			p[i].visit = false; //for others, not visited setting is needed?
		}
	}
}

int main(void) {

	int tc; //test case 수
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int N;
		ans = 987654321;
		cin >> N;

		vector<point> p(N + 2);

		//회사 -  N - 집
		for (int i = 0; i < N + 2; i++) {
			cin >> p[i].x >> p[i].y;  //좌표 받아서 좌표 array 에 push
			p[i].visit = false;
		}

		//최적 경로 구하고
		searchDist(p, 0, N, 0, 0); //(좌표array, 회사index, N, dist, 이전 index)


		//print
		cout << "#" << t << " " << ans << endl;


	}


	return 0;

}
