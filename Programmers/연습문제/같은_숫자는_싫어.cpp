#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	vector<int> v = arr; //����


	//v ���鼭 �ߺ� ���� ����
	for (int i = 0; i<v.size() - 1; i++) {

		if (v[i] != v[i + 1]) { //���� ���ҿ� next ���� �� �ٸ� ��
			if ((i + 1) == (v.size() - 1)) { //next ���Ұ� end �� 
				answer.push_back(v[i]);
				answer.push_back(v[i + 1]);
			}
			else {
				answer.push_back(v[i]);
			}

		}
		else {  //���� ���ҿ� next ���� �� ���� ��
			if ((i + 1) == (v.size() - 1)) { //next ���Ұ� end ��
				answer.push_back(v[i]);
			}
			else {
				//do nothing 
			}
		}
	}


	return answer;
}