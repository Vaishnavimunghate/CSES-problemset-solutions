#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);   //false
	cin.tie(0); //NULL

	ll n;
	cin >> n;
	vector<ll> dp(n + 1, INT_MAX);
	dp[0] = 0;
	for (ll i = 1; i <= n; i++) {
		vector<int> c;
		ll f = i;
		while (f) {
			c.push_back(f % 10);
			f = f / 10;
		}
		for (int j = 0; j < c.size(); j++) {
			dp[i] = min(dp[i], dp[i - c[j]] + 1);
		}
	}
	cout << dp[n] << "\n";
	return 0;
}