#include <iostream>
//#include <string.h>
#include <memory.h>

using namespace std;

int landsnailNumber[10][10] = { 0 };
int check[10][10] = { 0 };

void dfs(int x, int y, int n) {
	
	int count = 0;
	int direction=0;

	while (count != n * n) {
		
		count++;

		if (check[x][y] == 1)
			count--;

		int dx[4] = { 0,1,0,-1 };
		int dy[4] = { 1,0,-1,0 };

		landsnailNumber[x][y] = count;
		check[x][y] = 1;

		int nx = x + dx[direction % 4];
		int ny = y + dy[direction % 4];

		if (nx < n && nx >= 0 && ny < n && ny >= 0 && check[nx][ny]==0) {
			x = nx;
			y = ny;
			
		}else
			direction++;
	}
}

int main() {
	int t;
	int n;
	int testCase = 1;
	cin >> t;

	while (t--) {

		cin >> n;
		dfs(0, 0, n);
		
		cout << "#" << testCase << " " << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << landsnailNumber[i][j] << " ";
			}
			cout << endl;
		}
		memset(landsnailNumber, 0, sizeof(landsnailNumber));
		memset(check, 0, sizeof(check));
		testCase++;
	}
}