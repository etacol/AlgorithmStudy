#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(string s) {
	string ans = "";
	int c;
	string center;
	ans = s; //문자열 입력

	if (ans.length() % 2 == 0) { //문자열 길이 짝수
		c = ans.length() / 2;
		center = ans[c - 1];
		center += ans[c]; //가운데 2글자 추출

	}
	else { //문자열 길이 홀수
		c = ans.length() / 2;
		center = ans[c]; //가운데 글자 추출
	}

	return center;
}