#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);   //false
	cin.tie(0); //NULL

	int n;
	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];
	ll mod = 1e9 + 7;
	vector<vector<int>> dp(n, vector<int>(n, 0));
	if (v[0][0] != '*') {
		dp[0][0] = 1;
		for (int i = 1; i < n; i++) {
			if (v[i][0] == '.' && v[i - 1][0] == '.')
				dp[i][0] += dp[i - 1][0];
			if (v[0][i] == '.' && v[0][i - 1] == '.')
				dp[0][i] += dp[0][i - 1];
		}
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < n; j++) {
				if (v[i][j] == '.') {
					dp[i][j] = (dp[i][j] + (dp[i - 1][j] + dp[i][j - 1]) % mod) % mod;
				}
			}
		}
	}
	cout << dp[n - 1][n - 1] % mod << "\n";
	return 0;
}