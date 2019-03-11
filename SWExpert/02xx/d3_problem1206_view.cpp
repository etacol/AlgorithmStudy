#include <iostream>

using namespace std;


int main(void) {
	
	int ans;
	int buildingNum;
	int * build_arr; 


	for (int i = 1; i <= 10; i++) { //10회 반복
		
		cin >> buildingNum; //빌딩수 입력
		build_arr = new int[buildingNum]; //빌딩들 container 생성

		ans = 0;
		for (int j = 0; j < buildingNum; j++) {
			cin >> build_arr[j]; //각 빌딩 길이 입력받음
		}

		
		//앞2, 뒤2 총4개 빌딩과 키를 비교한 후 키가 더 크면 조망권 확보 check
		for (int b = 2; b < buildingNum - 2; b++) {
			int length = build_arr[b]; //조망권 check 할 빌딩 길이(층수)

			while (length != 0) { //length-- 로 해야함 한층씩 검사
				//앞2뒤2 와 length 비교
				if (length > build_arr[b - 1] && length > build_arr[b + 1]&& length > build_arr[b - 2] && length > build_arr[b + 2]) {

					
						ans++; // 조망권 확보된 세대 check
						length--;
				}
				else {
				
					break;
				}

			}
		}

		//출력
		cout << "#" << i << " " << ans << endl;

	}
	return 0;
}