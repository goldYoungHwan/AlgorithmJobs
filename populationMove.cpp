#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <memory.h>

#define ABS(X) ((X) > 0? (X) : -(X))

using namespace std;

int check[51][51] = { 0 };

void bfs(int i, int j, int cnt, int n, int l, int r, int **arr) {
	queue<pair<int, int>> location;
	vector<pair<int, int>> cal;

	int dx[4] = { 0,0,-1,1 };
	int dy[4] = { 1,-1,0,0 };
	location.push({ i,j });
	cal.push_back({ i,j });
	check[i][j] = cnt;
	int x, y, nx, ny, minus;
	int sum = 0;
	int count = 0;

	while (!location.empty()) {
		x = location.front().first;
		y = location.front().second;
		location.pop();
		sum += arr[x][y];
		count++;
		//check[x][y] = cnt;

		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];

			if ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < n) && check[nx][ny]==0) {
				
				if (l <= ABS(arr[x][y] - arr[nx][ny]) && ABS(arr[x][y] - arr[nx][ny]) <= r) {
					location.push({ nx, ny });
					cal.push_back({ nx, ny });
					check[nx][ny] = cnt;
					//sum += arr[nx][ny];
					//count++;
				}
					
			}
		}
	}
	for (int i = 0; i < cal.size(); i++) {
		arr[cal[i].first][cal[i].second] = sum / count;
	}
}

void searchLine(int **arr, int l, int r, int n) {
	int total = 0;
	int i, j, k;
	int cnt;
	int countOfCnt;
	int sum;

	while (1) {
		
		cnt = 0;
		for ( i = 0; i < n; i++) {
			for ( j = 0; j < n; j++) {
				if (check[i][j] == 0)
					bfs(i, j, ++cnt,  n, l, r, arr);
			}
		}
		if (cnt == n * n) {
			cout << total << endl;
			break;
		}

		/*for (i = 1; i <= cnt; i++) {
			countOfCnt = 0;
			sum = 0;
			for ( k = 0; k < n; k++)
				for ( j = 0; j < n; j++) {
					if (check[k][j] == i) {
						countOfCnt++;
						sum += arr[k][j];
					}
				}

			for ( k = 0; k < n; k++) {
				for ( j = 0; j < n; j++) {
					if (check[k][j] == i) {
						arr[k][j] = sum / countOfCnt;
					}
				}
			}
			sum = 0;
			countOfCnt = 0;
		}*/
		total++;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				check[i][j] = 0;
		//memset(check, 0, sizeof(check));
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

	for(int i=0; i<n; i++)
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			//check[i][j] = 0;
		}

	searchLine(arr,  l, r, n);

}