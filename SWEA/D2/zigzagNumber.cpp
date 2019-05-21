#include <iostream>

using namespace std;

int main() {
	int t,n;
	int k = 1;
	cin >> t;

	while (t--) {
		int sum = 0;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			sum += (i % 2 == 1 ? i : -i);
		}
		cout << "#" << k++ << " " << sum << endl;
	}
}