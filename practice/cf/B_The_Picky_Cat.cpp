#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

void solve() {
    int n; cin >> n;
    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    for (auto &ele : vec) {
        ele = abs(ele);
    }

    sort(vec.begin()+1, vec.end());

    auto idx = lower_bound(vec.begin()+1, vec.end(), abs(vec[0])) - vec.begin();

    int bigger_than_first = n - idx;

    int bigger_required = ceil(n/2.0) - 1;

    if (bigger_than_first >= bigger_required) {YES;}
    else {NO;}
    
    
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
