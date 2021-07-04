#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);   //false
	cin.tie(0); //NULL

	int n, m;
	cin >> n >> m;
	ll mod = 1e9 + 7;
	int x[n];
	for (int i = 0; i < n; i++)	cin >> x[i];
	vector<vector<ll>> dp(m + 1, vector<ll>(n, 0));
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (x[i] != 0)	dp[x[i]][i] = 1;
			else {
				for (int j = 1; j <= m; j++)	dp[j][i] = 1;
			}
		}
		else {
			if (x[i] != 0) {
				dp[x[i]][i] = (dp[x[i]][i - 1] + dp[x[i] - 1][i - 1]) % mod;
				if (x[i] < m) {
					dp[x[i]][i] = (dp[x[i]][i] + dp[x[i] + 1][i - 1]) % mod;
				}
			}
			else {
				for (int j = 1; j <= m; j++) {
					dp[j][i] = dp[j][i - 1] % mod;
					dp[j][i] = (dp[j][i] + dp[j - 1][i - 1]) % mod;
					if ((j + 1) <= m)	dp[j][i] = (dp[j][i] + dp[j + 1][i - 1]) % mod;
				}
			}
		}
	}
	if (x[n - 1] != 0)
		cout << dp[x[n - 1]][n - 1] % mod << "\n";
	else {
		ll sm = 0;
		for (int j = 1; j <= m; j++)	sm = (sm + dp[j][n - 1]) % mod;
		cout << sm % mod << "\n";
	}
	return 0;
}