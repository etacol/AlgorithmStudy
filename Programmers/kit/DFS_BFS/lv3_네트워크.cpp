#include <iostream>
#include <vector>

using namespace std;
int ans = 0;
vector<int> v[200]; //���� �迭
bool visit[200] = {0,}; //�湮 checker
/*
��ǻ���� ���� n, ���ῡ ���� ������ ��� 2���� �迭 computers�� �Ű�����
��Ʈ��ũ�� ������ return �ϵ��� solution �Լ��� �ۼ��Ͻÿ�.
*/

void dfs(int com){
    visit[com] = true; //visit ó��

    for(int j=0; j<v[com].size(); j++){ //����� �ֵ�
        int com2 = v[com][j]; 

        if(visit[com2] == 0) //���� �湮 ��������
            dfs(com2);
    }
    //
}

int solution(int n, vector<vector<int>> computers) {

    //2���� �迭 ���鼭 ����Ǿ� �ִ� ��츸 ���� push_back ���� ����
    for(int i=0; i<n; i++)
        for(int j=0; j<n;j++){
            if(computers[i][j] == 1){ //i �� j�� ����Ǿ� ������
                v[i].push_back(j);
                v[j].push_back(i);
            }
        }
    // dfs start
    for(int i=0; i<n; i++){
        if(visit[i] == 0){ //��ȸ �������� (��, �׵��� ��Ʈ��ũ ���� �ȵǾ�����)
            ans = ans+1;
            dfs(i);
        }
    }

    return ans;

    }