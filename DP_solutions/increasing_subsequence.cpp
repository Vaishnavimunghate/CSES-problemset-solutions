#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);   //false
	cin.tie(0); //NULL

	ll n;
	cin >> n;
	ll x[n];
	for (ll i = 0; i < n; i++) cin >> x[i];
	vector<ll> d(n + 1, 1e9);
	d[0] = -1e9;
	for (ll i = 0; i < n; i++) {
		ll j = upper_bound(d.begin(), d.end(), x[i]) - d.begin();
		if (d[j - 1] < x[i] && x[i] < d[j])	d[j] = x[i];
	}
	ll ans = 0;
	for (ll i = 0; i <= n; i++) {
		if (d[i] < (1e9))	ans = i;
	}
	cout << ans << "\n";
	return 0;
}