#include <iostream>

using namespace std;

int main() {
	int t;
	int k = 1;
	int P, Q, R, S, W;

	
	cin >> t;
	while (t--) {
		int finalMoney=0;
		int aWaterMoney, bWaterMoney;
		cin >> P >> Q >> R >> S >> W;

		aWaterMoney = P * W;
		bWaterMoney = (R >= W ? Q : Q + S * (W - R));

		if (aWaterMoney <= bWaterMoney)
			finalMoney = aWaterMoney;
		else
			finalMoney = bWaterMoney;

		cout << "#" << k++ << " "<< finalMoney << endl;
	}
}