#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

bool comp(vector<ll> &a, vector<ll> &b) {
	return a[1] < b[1];
}

ll binSer(vector<vector<ll>> &jb, ll i) {
	ll l = 0, r = i - 1, mid, ans = -1;
	while (l <= r) {
		mid = l + (r - l) / 2;
		if (jb[mid][1] < jb[i][0]) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);   //false
	cin.tie(0); //NULL

	ll n;
	cin >> n;
	vector<vector<ll>> jb(n, vector<ll>(3));
	for (ll i = 0 ; i < n; i++) {
		cin >> jb[i][0] >> jb[i][1] >> jb[i][2];
	}
	sort(jb.begin(), jb.end(), comp);
	vector<ll> dp(n, 0);
	dp[0] = jb[0][2];
	for (ll i = 1; i < n; i++) {
		ll inc = jb[i][2];
		ll idx = binSer(jb, i);
		if (idx != (-1)) {
			inc += dp[idx];
		}
		ll exc = dp[i - 1];
		dp[i] = max(inc, exc);
	}
	cout << dp[n - 1] << "\n";
	return 0;
}
