#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    vector<ll> numbers(n);
    for (auto &number : numbers) cin >> number;

    sort(numbers.begin(), numbers.end());

    ll distinct = 0;
    for (int i=0, j=0; i<n; i=j) {
        j=i;
        while (j<n && numbers[j] == numbers[i]) j++;
        distinct++;
    }

    cout << distinct << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1;
    while (t--) solve();
}

