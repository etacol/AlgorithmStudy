#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(string s) {
	string ans = "";
	int c;
	string center;
	ans = s; //���ڿ� �Է�

	if (ans.length() % 2 == 0) { //���ڿ� ���� ¦��
		c = ans.length() / 2;
		center = ans[c - 1];
		center += ans[c]; //��� 2���� ����

	}
	else { //���ڿ� ���� Ȧ��
		c = ans.length() / 2;
		center = ans[c]; //��� ���� ����
	}

	return center;
}