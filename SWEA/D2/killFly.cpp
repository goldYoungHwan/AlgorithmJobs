#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int t, n, m;
	int k = 1;
	int sum = 0;
	
	cin >> t;

	while (t--) {
		
		vector<int> max;
		cin >> n >> m;

		int flyNum[15][15];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> flyNum[i][j];
			}
		}

		for (int i = 0; i <= n - m; i++) {
			for (int j = 0; j <= n - m; j++) {
				for (int p = 0; p < m; p++) {
					for (int q = 0; q < m; q++) {
						sum += flyNum[p+i][q+j];
					}
				}
				max.push_back(sum);
				sum = 0;
			}
		}

		sort(max.begin(), max.end());

		cout << "#" << k << " " << max.back() << endl;
		k++;


	}
	return 0;
}