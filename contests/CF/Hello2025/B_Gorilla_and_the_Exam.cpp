#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k; cin >> n >> k;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    map<int,int> freq;

    for (auto ele : vec) {
        freq[ele]++;
    }

    vector<int> freq_vec;

    for (auto [x,fr]: freq) {
        freq_vec.push_back(fr);
    }

    sort(freq_vec.begin(), freq_vec.end());

    int i=0;
    while (k>0) {
        if (freq_vec[i] > k) break;
        k -= freq_vec[i];
        i++;
    }

    int answer = freq_vec.size() - i;
    cout << max(1,answer) << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
