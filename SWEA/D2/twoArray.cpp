#include <iostream>
#include <memory.h>

using namespace std;

int a[20] = { 0 };
int b[20] = { 0 };

int main() {
	int t;
	int k = 1;

	cin >> t;

	while (t--) {
		int n, m;
		int temp;
		int sum = 0;
		int max = 0;
		int flag = 1;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
			cin >> a[i];

		for (int i = 0; i < m; i++)
			cin >> b[i];

		if (n > m) {
			temp = n;
			n = m;
			m = temp;
			flag = 0;
		}


		for (int i = 0; i <= m - n; i++) {
				for (int j = 0; j < n; j++) {
					if (flag == 1)
						sum += (a[j] * b[i + j]);
					else
						sum += (a[i + j] * b[j]);
				}
			if (max < sum)
				max = sum;
			sum = 0;
		}
		

		cout << "#" << k++ << " " << max << endl;
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
	}

}