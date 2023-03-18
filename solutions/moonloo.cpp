#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;

    vector<long long> days(n);
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }

    long long ans = k + 1;
    vector<long long> memo(n);
    memo[0] = k + 1;

    for(int i = 1; i < n; i ++){
        memo[i] = memo[i-1] + min(days[i]-days[i-1], k + 1);
    }

    cout << memo[n-1] << endl;

    return 0;
}