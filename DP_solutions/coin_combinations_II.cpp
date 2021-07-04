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
	sort(c, c + n);
	vector<ll> dp(x + 1, 0);
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		if (c[i] <= x) {
			// dp[c[i]]+=1;
			for (int j = c[i]; j <= x; j++) {
				dp[j] = (dp[j] + dp[j - c[i]]) % mod;
			}
		}
	}
	cout << dp[x] % mod << "\n";
	return 0;
}