#include <iostream>

using namespace std;

int max(int x, int y)
{
	return x > y ? x : y;
}

int duration[16] = { 0 };
int profit[16] = { 0 };
int dp[16] = { 0 };


int main()
{
	int n;
	int next;

	cin >> n;

	

	for (int i = 1; i <= n; i++) {
		cin >> duration[i] >> profit[i];
	}

	for (int i = n; i > 0; i--) {
		next = i +duration[i]; // 기간 확인
		if (next > n + 1) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], dp[next] + profit[i]);
		}

	}

	cout << dp[1] << endl;

	return 0;
}