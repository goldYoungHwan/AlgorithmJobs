#include <iostream>
#include <memory.h>
using namespace std;

int check[10] = {0};

int main() {
	int t;
	int k = 1;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int flag = 0;
		int j = 1;

		while (1) {
			int p = j * n;
			
			while (p) {
				check[p % 10]=1;
				p = p / 10;
			}


			for (int i = 0; i < 10; i++) {
				if (check[i] == 0) {
					flag = 1;
					break;
				}
			}

			if (flag == 1) {
				j++;
				flag = 0;
			}else
				break;
		}

		cout << "#" << k++ << " " << j*n << endl;
		memset(check, 0, sizeof(check));
	}
}