#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int main() {
	ios_base::sync_with_stdio(0);   //false
	cin.tie(0); //NULL

	int n;
	cin >> n;
	int x[n];
	for (int i = 0; i < n; i++)	cin >> x[i];
	set<int> s;
	for (int i = 0; i < n; i++) {
		if (s.empty()) {
			s.insert(x[i]);
		}
		else {
			vector<int> v;
			v.push_back(x[i]);
			for (auto itr = s.begin(); itr != s.end(); itr++)
			{
				v.push_back(*itr + x[i]);
			}
			for (int j = 0; j < v.size(); j++) {
				s.insert(v[j]);
			}
		}
	}
	cout << s.size() << "\n";
	for ( auto it = s.begin(); it != s.end() ; it++) {
		cout << (*it) << " ";
	}
	cout << "\n";
	return 0;
}