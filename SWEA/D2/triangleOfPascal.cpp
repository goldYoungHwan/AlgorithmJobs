#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;


int a[10] = { 0 }; //È¦¼ö¿ë
int b[10] = { 0 }; //Â¦¼ö¿ë

int main() {
	int t,n;
	int k = 1;
	cin >> t;

	while (t--) {
		cin >> n;

		cout << "#" << k << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				if (j == 0) {
					a[j] = 1;
					b[j] = a[j];
					cout << b[j] << " ";
				}
				else {
					b[j] = a[j - 1] + a[j];
					cout << b[j] << " ";
				}
				
			}
			copy(b, b + 10, a);
			cout << endl;
		}
		k++;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}
}