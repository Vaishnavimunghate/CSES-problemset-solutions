#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);   //false
	cin.tie(0); //NULL

	ll n;
	cin >> n;
	ll mod = 1e9 + 7;
	ll dp[n + 1] = {0};
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (ll i = 3; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			if ((i - j) >= 0) {
				dp[i] = (dp[i] + dp[i - j]) % mod;
			}
		}
	}
	cout << dp[n] % mod << "\n";
	return 0;
}