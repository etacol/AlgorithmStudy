#include <iostream>
#include <vector>

using namespace std;


//��ǥ class
typedef struct point {

	int x, y;
	bool visit;
}point;

int ans; //�� 


//���� ��� search
void searchDist(vector<point> &p, int n, int N, int dist, int before) {

	if (n == N) { //terminate cond
		//N��° �������� ��������
		dist = dist+ abs(p[1].x - p[before].x) + abs(p[1].y - p[before].y);

		if (ans > dist) { //dist �� �� ª
			ans = dist;
		}
		return;
	}


	//ȸ�� - 1��°��- 2��°�� - and so on
	for (int i = 2; i < p.size(); i++) {

		if (p[i].visit == false) { 
			p[i].visit = true; //�湮 check
			
			// �Ÿ� �׾Ƽ� ���� ������
			searchDist(p, n + 1, N, dist + abs(p[i].x - p[before].x) + abs(p[i].y - p[before].y), i); 

			p[i].visit = false; //for others, not visited setting is needed?
		}
	}
}

int main(void) {

	int tc; //test case ��
	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int N;
		ans = 987654321;
		cin >> N;

		vector<point> p(N + 2);

		//ȸ�� -  N - ��
		for (int i = 0; i < N + 2; i++) {
			cin >> p[i].x >> p[i].y;  //��ǥ �޾Ƽ� ��ǥ array �� push
			p[i].visit = false;
		}

		//���� ��� ���ϰ�
		searchDist(p, 0, N, 0, 0); //(��ǥarray, ȸ��index, N, dist, ���� index)


		//print
		cout << "#" << t << " " << ans << endl;


	}


	return 0;

}
