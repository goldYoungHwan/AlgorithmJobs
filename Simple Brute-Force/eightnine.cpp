#include <iostream>
using namespace std;

int main() {
	int n, m;
	int temp;
	cin >> n >> m;


	int **arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for(int i=0; i<n; i++)
		for (int j = 0; j < m/2; j++) {
			if (arr[i][0 + j] == arr[i][m - 1 - j]) {

			}
			else {
				temp = arr[i][0 + j];
				arr[i][0 + j] = arr[i][m - 1 - j];
				arr[i][m - 1 - j] = temp;
			}
		}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}
			
}
