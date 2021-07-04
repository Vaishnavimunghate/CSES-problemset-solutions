#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);   //false
	cin.tie(0); //NULL

	int a, b;
	cin >> a >> b;
	vector<vector<int>> dp(a + 1, vector<int>(b + 1, INT_MAX / 2));
	dp[0][0] = 0;
	for (int i = 0; i <= a; i++)	dp[i][0] = 0;
	for (int i = 0; i <= b; i++)	dp[0][i] = 0;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (i == j) {
				dp[i][j] = 0;
			}
			else {
				for (int k = 1; k <= i; k++) {
					dp[i][j] = min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
				}
				for (int k = 1; k <= j; k++) {
					dp[i][j] = min(dp[i][j], 1 + dp[i][j - k] + dp[i][k]);
				}
			}
		}
	}
	cout << dp[a][b] << "\n";
	return 0;
}