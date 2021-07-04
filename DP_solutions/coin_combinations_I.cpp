#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);   //false
	cin.tie(0); //NULL

	int n;
	cin >> n;
	ll x;
	cin >> x;
	ll c[n];
	ll mod = 1e9 + 7;
	for (int i = 0; i < n; i++)	cin >> c[i];
	vector<ll> dp(x + 1, 0);
	dp[0] = 1;
	for (ll i = 1; i <= x; i++) {
		for (int j = 0; j < n; j++) {
			if (c[j] <= i) {
				dp[i] = (dp[i] + dp[i - c[j]]) % mod;
			}
		}
	}
	cout << dp[x] % mod << "\n";
	return 0;
}