#include <iostream>
#include <vector>

using namespace std;
int ans = 0;
vector<int> v[200]; //벡터 배열
bool visit[200] = {0,}; //방문 checker
/*
컴퓨터의 개수 n, 연결에 대한 정보가 담긴 2차원 배열 computers가 매개변수
네트워크의 개수를 return 하도록 solution 함수를 작성하시오.
*/

void dfs(int com){
    visit[com] = true; //visit 처리

    for(int j=0; j<v[com].size(); j++){ //연결된 애들
        int com2 = v[com][j]; 

        if(visit[com2] == 0) //아직 방문 안했으면
            dfs(com2);
    }
    //
}

int solution(int n, vector<vector<int>> computers) {

    //2차원 배열 돌면서 연결되어 있는 경우만 서로 push_back 으로 연결
    for(int i=0; i<n; i++)
        for(int j=0; j<n;j++){
            if(computers[i][j] == 1){ //i 컴 j컴 연결되어 있으면
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    // dfs start
    for(int i=0; i<n; i++){
        if(visit[i] == 0){ //순회 안했으면 (즉, 그동안 네트워크 형성 안되었으면)
            ans = ans+1;
            dfs(i);
        }
    }

    return ans;

    }