#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, k1, k2; cin >> n >> k1 >> k2;

    vector<ll> vec_a(n);
    for (auto &ele : vec_a) cin >> ele;
    
    vector<ll> vec_b(n);
    for (auto &ele : vec_b) cin >> ele;
    

    priority_queue<ll> pq;
    for (int i=0; i<n; i++) {
        ll err = abs(vec_a[i] - vec_b[i]);
        pq.push(err);
    }

    ll k = k1 + k2;
    while (!pq.empty() && k) {
        ll top = pq.top();
        pq.pop();
        if (top == 0) continue;
        k--;
        pq.push(top-1);
    }

    ll total_err = 0;
    if (pq.empty()) {
        // this means that all errors are zero
        total_err += k&1;
    }

    while (!pq.empty()) {
        ll top = pq.top();
        total_err += top * top;
        pq.pop();
    }

    cout << total_err << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

