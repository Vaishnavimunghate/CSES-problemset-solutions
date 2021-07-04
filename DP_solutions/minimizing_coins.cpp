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
	for (int i = 0; i < n; i++)	cin >> c[i];
	vector<ll> dp(x + 1, INT_MAX);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		if (c[i] <= x)	dp[c[i]] = 1;
	}
	for (ll i = 1; i <= x; i++) {
		for (int j = 0; j < n; j++) {
			if (c[j] <= i) {
				dp[i] = min(dp[i], dp[i - c[j]] + 1);
			}
		}
	}
	if (dp[x] == (INT_MAX))	cout << "-1\n";
	else	cout << dp[x] << "\n";
	return 0;
}