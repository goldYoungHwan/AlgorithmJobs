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

vector<vector<int>> getCase(int blankSize, int wallCount, vector<vector<int>> newCase) {
	vector<vector<int>> newCases;

	int caseSize = newCase.size();
	for (int i = 0; i < caseSize; i++) {
		for (int j = 0; j < blankSize; j++) {
			if (find(newCase[i].begin(), newCase[i].end(), j) == newCase[i].end()) {
				vector<int> temp (newCase[i]);
				temp.push_back(j);

				sort(temp.begin(), temp.end());
				int flag = 0;

				/*for (int k = 0; k < newCases.size(); k++) {
					if (newCases[k] == temp) {
						flag = 1;
						break;
					}
				}
				if(flag==0)*/
					newCases.push_back(temp);
			}
		}
	}
	if (wallCount == 1) return newCases;
	else return getCase(blankSize, --wallCount, newCases);
}

void makeWall(vector<pair<int, int>> blankArea, int **board, vector<pair<int, int>> virusArea, int n, int m) {

	int blankSize = blankArea.size(); 

	int **copy = new int*[n];

	vector<vector<int>> newCase;

	for (int i = 0; i < n; i++)
		copy[i] = new int[m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			copy[i][j] = board[i][j];
		}

	for (int i = 0; i < blankSize; i++) {
		vector<int> temp;
		temp.push_back(i);
		newCase.push_back(temp);
	}

	newCase = getCase(blankSize, 2, newCase);

	for (int i = 0; i < newCase.size(); i++) {
		for (int j = 0; j < 3; j++) {
			cout << newCase[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < newCase.size(); i++) {
		
			int x1 = blankArea[newCase[i][0]].first;
			int y1 = blankArea[newCase[i][0]].second;
			int x2 = blankArea[newCase[i][1]].first;
			int y2 = blankArea[newCase[i][1]].second;
			int x3 = blankArea[newCase[i][2]].first;
			int y3 = blankArea[newCase[i][2]].second;
			copy[x1][y2] = 1;
			copy[x2][y2] = 1;
			copy[x3][y3] = 1;
		safeZone(copy, virusArea, n, m);
		copy[x1][y2] = 0;
		copy[x2][y2] = 0;
		copy[x3][y3] = 0;
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