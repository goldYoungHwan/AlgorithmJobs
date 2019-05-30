#include <iostream>
#include <math.h>

using namespace std;

int a[1000] = { 0 };

int main() {
	int t;
	int k = 1;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		int min = abs(a[0]);
		int count = 1;
		for (int i = 1; i < n; i++) {
			if (min > abs(a[i])) {
				min = abs(a[i]);
				count = 1;
			}
			else if (min == abs(a[i])) {
				count++;
			}
		}

		cout << "#" << k++ << " " << min << " " << count << endl;
	}
}