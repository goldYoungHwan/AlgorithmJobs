#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int checkAlphabat[26] = { 0 };
int checkBoard[21][21] = { 0 };
int checkDepth[21][21] = { 0 };

int maxPath = 0;

void findPath(int x, int y, char **board, int r, int c) {
	
	if (maxPath < checkDepth[x][y])
		maxPath = checkDepth[x][y];


	checkBoard[x][y] = 1;
	checkAlphabat[board[x][y] - 65] = 1;

	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	
	int nx, ny;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if ((nx < r) && (nx >= 0) && (ny < c) && (ny >= 0)) {

				if ((checkBoard[nx][ny] == 0) && (checkAlphabat[board[nx][ny] - 65] == 0)) {
					checkDepth[nx][ny] = checkDepth[x][y] + 1;
					findPath(nx, ny, board, r, c);
					
					checkAlphabat[board[nx][ny] - 65] = 0;
					checkBoard[nx][ny] = 0;
				}
			}
		}
}
int main() {
	int r, c;
	cin >> r >> c;

	char input;
	char **board = new char*[r];

	for (int i = 0; i < r; i++) {
		board[i] = new char[c];
	}

	for(int i=0; i<r; i++)
		for (int j = 0; j < c; j++) {
			cin >> input;
			board[i][j] = input;
		}
	maxPath = 1;
	checkDepth[0][0] = 1;
	findPath(0, 0, board, r, c);
	
	cout << maxPath << endl;	
}