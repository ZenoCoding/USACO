// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll n,t;
	cin >> n >> t;
	vector<ll> bales = vector<ll>(n);
	vector<ll> days = vector<ll>(n);
	for (ll i = 0; i < n; i ++) cin >> days[i] >> bales[i];

	bales.push_back(0);
	days.push_back(t+1);

	ll ans = 0;
	ll last_deliv = 0;
	ll remaining = 0;

	for (ll i = 0; i < n+1; i ++) {
		ans += bales[i];
		ll diff = days[i] - last_deliv;
		last_deliv = days[i];
		remaining -= diff;// the amount remaining after consumption
        remaining = max(remaining, (ll) 0) + bales[i];
	}

	ans -= remaining;

	cout << ans << endl;
}
