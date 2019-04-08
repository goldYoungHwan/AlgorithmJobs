#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int check[51][51] = { 0 };

void bfs(int i, int j, int cnt, int n, int l, int r, int **arr) {
	queue<pair<int, int>> location;

	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { 1,-1,0,0 };
	location.push({ i,j });
	int x, y, nx, ny, minus;
	
	while (!location.empty()) {
		x = location.front().first;
		y = location.front().second;
		location.pop();
		check[x][y] = cnt;

		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];

			if ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < n) && check[nx][ny]==0) {
				minus = arr[x][y] - arr[nx][ny];
				minus = minus >= 0 ? minus : minus * (-1);
				if (minus >= l && minus <= r) {
					location.push({ nx, ny });
					//check[nx][ny] = cnt;
				}
					
			}
		}
	}
}

void searchLine(int **arr, int l, int r, int n) {
	int total = 0;

	while (1) {
		
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == 0)
					bfs(i, j, ++cnt,  n, l, r, arr);
			}
		}
		if (cnt == n * n) {
			cout << total << endl;
			break;
		}

		for (int i = 1; i <= cnt; i++) {
			int countOfCnt = 0;
			int sum = 0;
			for (int k = 0; k < n; k++)
				for (int j = 0; j < n; j++) {
					if (check[k][j] == i) {
						countOfCnt++;
						sum += arr[k][j];
					}
				}

			for (int k = 0; k < n; k++) {
				for (int j = 0; j < n; j++) {
					if (check[k][j] == i) {
						arr[k][j] = sum / countOfCnt;
					}
				}
			}
			sum = 0;
			countOfCnt = 0;
		}
		total++;
		memset(check, 0, sizeof(check));
	}
}

int main() {
	int n, l, r;
	cin >> n >> l >> r;

	int **arr = new int*[n];
	//int **check = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		//check[i] = new int[n];
	}
		

	int input;
	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			cin >> input;
			arr[i][j] = input;
			//check[i][j] = 0;
		}

	searchLine(arr, l, r, n);

}