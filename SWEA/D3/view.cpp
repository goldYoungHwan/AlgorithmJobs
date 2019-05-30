#include <iostream>

using namespace std;

int check[1000] = { 0 };

int main() {
	int t = 10;
	int k = 1;

	while (t--) {
		int n;

		cin >> n;

		int view = 0;
		for (int i = 0; i < n; i++)
			cin >> check[i];

		for (int i = 2; i < n - 2; i++) {
			if ((check[i + 1] < check[i]) && (check[i + 2] < check[i]) && (check[i - 1] < check[i]) && (check[i - 2] < check[i])) {
				int rightMax = 0;
				int leftMax = 0;
				check[i + 1] >= check[i + 2] ? rightMax = check[i+1] : rightMax = check[i+2];
				check[i - 1] >= check[i - 2] ? leftMax = check[i - 1] : leftMax = check[i - 2];
				rightMax >= leftMax ? view += check[i] - rightMax : view += check[i] - leftMax;
			}
		}

		cout << "#" << k++ << " " << view << endl;
	}
}