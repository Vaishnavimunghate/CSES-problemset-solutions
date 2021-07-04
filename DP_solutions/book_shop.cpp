#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);   //false
	cin.tie(0); //NULL

	int n, x;
	cin >> n >> x;
	int h[n], s[n];
	for (int i = 0; i < n; i++)	cin >> h[i];
	for (int i = 0; i < n; i++)	cin >> s[i];

	vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
	for (int i = 0; i <= n; i++)	dp[i][0] = 0;
	for (int i = 0; i <= x; i++)	dp[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= x; j++) {
			if (h[i - 1] <= j) {
				dp[i][j] = max(dp[i - 1][j], s[i - 1] + dp[i - 1][j - h[i - 1]]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][x] << "\n";
	return 0;
}