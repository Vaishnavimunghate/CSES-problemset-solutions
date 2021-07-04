#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);   //false
	cin.tie(0); //NULL

	int n;
	cin >> n;
	ll x[n];
	for (int i = 0; i < n; i++) cin >> x[i];
	vector<vector<ll>> dp(n, vector<ll>(n, 0));

	for (int len = 1; len <= n; len++) {
		for (int i = 0; i + len <= n; i++) {
			int j = i + len - 1;
			ll a, b, c;
			a = (i + 2 <= j) ? dp[i + 2][j] : 0;
			b = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
			c = (i <= j - 2) ? dp[i][j - 2] : 0;
			dp[i][j] = max(x[i] + min(a, b), x[j] + min(b, c));
		}
	}

	cout << dp[0][n - 1] << "\n";
	return 0;
}