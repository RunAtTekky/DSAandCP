#include <bits/stdc++.h>
using namespace std;

long long take(vector<int>& vec, vector<int>& vec_side, int sz) {
    long long sum = 0;
    for (int i=0; i<sz; i++) sum += vec_side[i];

    return sum;
}

void solve() {
    int n,l,r; cin >> n >> l >> r;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    vector<int> lft_vec(vec.begin(), vec.begin() + r);
    vector<int> rgt_vec(vec.begin()+l-1, vec.end());

    sort(lft_vec.begin(), lft_vec.end());
    sort(rgt_vec.begin(), rgt_vec.end());

    // for (auto &ele : lft_vec) cout << ele << " ";
    // cout << "\n";
    
    // for (auto &ele : rgt_vec) cout << ele << " ";
    // cout << "\n";
    

    int sz = r-l+1;

    // taking elements from left side
    auto lft = take(vec, lft_vec, sz);

    // taking elements from right side
    auto rgt = take(vec, rgt_vec, sz);

    cout << min(lft,rgt) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
