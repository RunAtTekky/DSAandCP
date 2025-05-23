#include <bits/stdc++.h>
using namespace std;

#define TOM cout << "Tom\n"
#define JERRY cout << "Jerry\n"  

void solve() {
    long long n,k; cin >> n >> k;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;
    
    long long turns = accumulate(vec.begin(), vec.end(), 0LL);

    sort(vec.begin(), vec.end());

    vec[n-1]--;

    sort(vec.begin(), vec.end());

    if (vec.back() - vec.front() > k) {
        JERRY; return;
    }

    if (turns&1) {
        TOM;
    } else {
        JERRY;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
