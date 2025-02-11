#include <bits/stdc++.h>
using namespace std;

#define YES cout << "Yes\n"
#define NO cout << "No\n"  

void increase(vector<int>& vec, int from, int target) {
    for (int i=from+2; i<vec.size(); i++) {
        if (vec[i] == target) vec[i]++;
        else break;
    }
}

void solve() {
    int n; cin >> n;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    sort(vec.begin(), vec.end());

    for (int i=0; i+1<n; i+=2) {

        if (vec[i] < vec[i+1]) {NO; return;}

        increase(vec, i, vec[i]);
    }

    YES;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
