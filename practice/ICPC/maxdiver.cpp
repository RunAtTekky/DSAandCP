#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &e : arr) cin >> e;

    // 2 3 3 2 4 4
    // 2 2 3 3 4 4
    // 1 2 3 4 4 6
    // 5+4+3+1+1+0 = 14

    // We need to find the elements with maximum frequency at the moment
    // Change that element
    // Do this k times

    priority_queue<int> pq;

    map<int,int> mp;

    for (auto e : arr) mp[e]++;

    for (auto [e, freq] : mp) pq.push(freq);

    while (k--) {
        int max_frequency_at_the_time = pq.top();
        if (max_frequency_at_the_time == 1) break;
        pq.pop();
        pq.push(max_frequency_at_the_time-1);

        // This is the extra distinct element
        pq.push(1);
    }

    long long max_diver = 0;

    while (!pq.empty()) {
        long long top = pq.top();
        pq.pop();

        max_diver += (n - top)*top;
        n -= top;
    }

    cout << max_diver << "\n";

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
