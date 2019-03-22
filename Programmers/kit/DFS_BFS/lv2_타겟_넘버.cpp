#include <string>
#include <vector>
#include <iostream>

using namespace std;
int ans; //답

/*
사용할 수 있는 숫자가 담긴 배열 numbers, 타겟 넘버 target이 매개변수
숫자를 적절히 더하고 빼서 타겟 넘버를 만드는 방법의 수를 return 하도록
solution 함수를 작성해주세요.
*/

void dfs(vector<int> &numbers, int target, int sum, int depth) {

	//다 뻗어나갔으면, depth 끝까지 도달했으면
	if (depth == numbers.size()) {
		if (sum == target) //target num make 성공했으면
			ans = ans + 1;
		//성공 못하면 skip

		return;
	}

	//아직 도달 x case
	dfs(numbers, target, sum + numbers[depth], depth + 1); //쁠
	dfs(numbers, target, sum + numbers[depth] * (-1), depth + 1); //마
}

int solution(vector<int> numbers, int target) {
	dfs(numbers, target, numbers[0], 1); //쁠로 시작
	dfs(numbers, target, numbers[0] * (-1), 1); //마이너스로 시작

	return ans;

}