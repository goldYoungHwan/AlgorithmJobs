#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int maxCount = 0;

void safeZone(int **copy, vector<pair<int, int>> virusArea, int n, int m) {
	queue<pair<int, int>> virusLocation;
	
	int **virus= new int*[n];

	for (int i = 0; i < n; i++)
		virus[i] = new int[m];

	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			virus[i][j] = copy[i][j];
		}
	
	for (int i = 0; i < virusArea.size(); i++)
		virusLocation.push({ virusArea[i].first, virusArea[i].second });

	int dx[4] = { 0, 0, 1, -1 };
	int dy[4] = { 1, -1, 0, 0 };

	while (!virusLocation.empty()) {
		int x = virusLocation.front().first;
		int y = virusLocation.front().second;
		virusLocation.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if ((nx >= 0) && (nx < n) && (ny >= 0) && (ny < m)) {
				if (virus[nx][ny] == 0) {
					virus[nx][ny] = 2;
					virusLocation.push({nx, ny});
				}
			}
		}

	}
	int countOfSafeZone=0;
	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			if (virus[i][j] == 0)
				countOfSafeZone++;
		}

	if (maxCount < countOfSafeZone)
		maxCount = countOfSafeZone;
}

void makeWall(vector<pair<int, int>> blankArea, int **board, vector<pair<int, int>> virusArea, int n, int m) {
	int size = blankArea.size();
	int **copy = new int*[n];

	for (int i = 0; i < n; i++)
		copy[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			copy[i][j] = board[i][j];
		}
	
	for (int i = 0; i < size; i++) {
		int firstX = blankArea[i].first;
		int firstY = blankArea[i].second;
		copy[firstX][firstY] = 1;

		for (int j = i + 1; j < size; j++) {
			int secondX = blankArea[j].first;
			int secondY = blankArea[j].second;
			copy[secondX][secondY] = 1;

			for (int k = j + 1; k < size; k++) {
				int thirdX = blankArea[k].first;
				int thirdY = blankArea[k].second;
				copy[thirdX][thirdY] = 1;

				safeZone(copy, virusArea, n, m);
				copy[thirdX][thirdY] = 0;

			}
			copy[secondX][secondY] = 0;

		}
		copy[firstX][firstY] = 0;
	}
}

int main() {
	int n,m;
	cin >> n >> m;

	int input;

	int **board = new int*[n];
	vector<pair<int, int>> blankArea;
	vector<pair<int, int>> virusArea;

	for (int i = 0; i < n; i++)
		board[i] = new int[m];

	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++) {
			cin >> input;
			board[i][j] = input;
			if (input == 0)
				blankArea.push_back({ i,j });
			else if (input == 2)
				virusArea.push_back({ i,j });
		}

	makeWall(blankArea, board, virusArea, n, m);

	cout << maxCount << endl;

}