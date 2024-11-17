#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    map<int,int> freq;
    for (auto ele : vec) freq[ele]++;

    long long score = 0;
    for (auto i : freq) {
        score += i.second/2;
    }

    cout << score << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
