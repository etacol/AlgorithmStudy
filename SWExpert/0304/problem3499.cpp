#include <iostream>
#include <string>
using namespace std;

int half;
string ans;

int main() {

	int tc, cardN;
	cin >> tc;

	//tc °¹¼ö¸¸Å­
	for (int i = 1; i <= tc; i++) {



		//int cardN; //Ä«µå °¹¼ö
		cin >> cardN;

		string shuffle1[cardN]; //¼ÅÇÃ


		for (int j = 0; j <cardN; j++) {//Ä«µå ÀÔ·Â¹ÞÀ½
			cin >> shuffle1[j];
		}

		if ((cardN % 2) == 0)  //Ä«µå°¹¼ö Â¦¼ö
			half = cardN / 2;

		else
			half = (cardN / 2) + 1;


		for (int j = 0; j < half; j++) {

			if (((cardN % 2) == 1) && (j == (half - 1))) { //cardNum È¦¼ö°í ¸¶Áö¸· ¼ÅÇÃÀÏ¶§
				ans += " " + shuffle1[j]; //¸ÕÀú ³õ´ÂÂÊ¸¸
			}
			else {
				ans += " " + shuffle1[j] + " " + shuffle1[half + j]; //¼ÅÇÃ ±³´ë
			}
		}

		cout << "#" << i << ans << endl;
		ans = "";

	}
	return 0;
}
