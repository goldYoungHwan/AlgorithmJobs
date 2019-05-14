#include <iostream>

using namespace std;

int a[7][7] = { 0 };
int b[7][7] = { 0 };

void transfer(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			b[j][i + n - (i * 2 + 1)] = a[i][j];
		}
	}

	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			a[i][j] = b[i][j];
		}
}

int main() {
	int t, n;
	int k = 1;

	cin >> t;
	while (t--) {

		cin >> n;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		cout << "#" << k << " " << endl;
		k++;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {

				transfer(n);
				for (int q = 0; q < n; q++) {
					cout << b[i][q];
				}
				cout << " ";
			}
			transfer(n);
			cout << endl;
		}
		
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}
}