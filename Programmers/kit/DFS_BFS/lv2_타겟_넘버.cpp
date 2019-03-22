#include <string>
#include <vector>
#include <iostream>

using namespace std;
int ans; //��

/*
����� �� �ִ� ���ڰ� ��� �迭 numbers, Ÿ�� �ѹ� target�� �Ű�����
���ڸ� ������ ���ϰ� ���� Ÿ�� �ѹ��� ����� ����� ���� return �ϵ���
solution �Լ��� �ۼ����ּ���.
*/

void dfs(vector<int> &numbers, int target, int sum, int depth) {

	//�� ���������, depth ������ ����������
	if (depth == numbers.size()) {
		if (sum == target) //target num make ����������
			ans = ans + 1;
		//���� ���ϸ� skip

		return;
	}

	//���� ���� x case
	dfs(numbers, target, sum + numbers[depth], depth + 1); //��
	dfs(numbers, target, sum + numbers[depth] * (-1), depth + 1); //��
}

int solution(vector<int> numbers, int target) {
	dfs(numbers, target, numbers[0], 1); //�ܷ� ����
	dfs(numbers, target, numbers[0] * (-1), 1); //���̳ʽ��� ����

	return ans;

}