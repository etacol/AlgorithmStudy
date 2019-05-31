#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr)
{
	vector<int> answer;
	vector<int> v = arr; //복사


	//v 돌면서 중복 숫자 제거
	for (int i = 0; i<v.size() - 1; i++) {

		if (v[i] != v[i + 1]) { //현재 원소와 next 원소 값 다를 때
			if ((i + 1) == (v.size() - 1)) { //next 원소가 end 면 
				answer.push_back(v[i]);
				answer.push_back(v[i + 1]);
			}
			else {
				answer.push_back(v[i]);
			}

		}
		else {  //현재 원소와 next 원소 값 같을 때
			if ((i + 1) == (v.size() - 1)) { //next 원소가 end 면
				answer.push_back(v[i]);
			}
			else {
				//do nothing 
			}
		}
	}


	return answer;
}