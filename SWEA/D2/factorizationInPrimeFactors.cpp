#include <iostream>

using namespace std;



int num = 0;

void calculate(int *n, int m) {
	int k = *n;

	while (k % m == 0) {
		k = k / m;
		num++;
	}
}

int main() {

	int t;
	int k = 1;

	int a[5] = { 2,3,5,7,11 };

	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		cout << "#" << k++ << " ";

		for (int i = 0; i < 5; i++) {
			calculate(&n, a[i]);
			cout << num <<" ";
			num = 0;
		}
		cout << endl;
		
	}

}