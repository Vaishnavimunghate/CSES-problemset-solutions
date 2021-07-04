#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);   //false
	cin.tie(0); //NULL

	ll n;
	cin >> n;
	ll mod = 1e9 + 7;
	ll sm = (n * (n + 1)) / 2;
	if (sm % 2)	cout << "0\n";
	else {
		sm = sm / 2;
		vector<vector<ll>> dp(n, vector<ll>(sm + 1, 0));
		dp[0][0] = 1;
		for (ll i = 1; i < n; i++) {
			for (ll j = 0; j <= sm; j++) {
				if (j >= i) {
					dp[i][j] = (dp[i - 1][j - i] + dp[i - 1][j]) % mod;
				}
				else {
					dp[i][j] = dp[i - 1][j] % mod;
				}
			}
		}

		cout << dp[n - 1][sm] % mod << "\n";
	}
	return 0;
}