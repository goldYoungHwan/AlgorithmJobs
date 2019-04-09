#include <iostream>
#include <memory.h>

using namespace std;

int slopeWay = 0;
int slopeCheck[100][100] = { 0 };

void breadth(int **arr, int n, int l) {
	for (int i = 0; i < n; i++) {
		int j = 0;
		int currentLocation = j;
		int flag = 0;
		while (currentLocation != n) {
			if (arr[i][currentLocation] == arr[i][currentLocation + 1])
				currentLocation++;
			else if (arr[i][currentLocation] - 1 == arr[i][currentLocation + 1]) {

				int next = arr[i][currentLocation] - 1;

				for (int k = 1; k <= l; k++) {
					if ((currentLocation + k <n) && (next == arr[i][currentLocation + k]) && (slopeCheck[i][currentLocation + k] == 0)) {
						slopeCheck[i][currentLocation + k] = 1;
					}
					else {
						memset(slopeCheck, 0, sizeof(slopeCheck));
						flag = 1;
						break;
					}
					flag = 2;
				}
			}
			else if (arr[i][currentLocation] + 1 == arr[i][currentLocation + 1]) {
				int before = arr[i][currentLocation];

				for (int k = 0; k < l; k++) {
					if ((currentLocation - k >= 0) && (before == arr[i][currentLocation - k]) && (slopeCheck[i][currentLocation - k] == 0)) {
						slopeCheck[i][currentLocation - k] = 1;
					}
					else {
						memset(slopeCheck, 0, sizeof(slopeCheck));
						flag = 1;
						break;
					}
					flag = 3;
				}
			}
			else
				break; //차이가 2 이상인것들

			if (flag == 1) {
				break;
				flag = 0;
			}
			else if (flag == 2 && currentLocation != n) {
				currentLocation += l;
				flag = 0;
			}
			else if (flag == 3 && currentLocation != n) {
				currentLocation++;
				flag = 0;
			}


			if (currentLocation == n - 1)
				slopeWay++;
		}
		memset(slopeCheck, 0, sizeof(slopeCheck));
	}
}

int main() {
	int n, l;
	cin >> n >> l;

	int **arr = new int*[n];
	for (int i = 0; i < n; i++)
		arr[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];

	breadth(arr, n, l);

	for(int i=0; i<n ; i++)
		for (int j = i; j < n; j++) {
			int temp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = temp;
		}

	breadth(arr, n, l);
	//가로 줄 확인...
	
	cout << slopeWay << endl;
}