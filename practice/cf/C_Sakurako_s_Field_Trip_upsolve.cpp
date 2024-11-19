#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << ' ' << x << '\n';

bool profitableSwap(int l, int r, vector<int>& interest) {
    vector<int> neighboursLeft;
    vector<int> neighboursRight;

    if (l-1>=0) neighboursLeft.push_back(interest[l-1]);
    if (l+1<interest.size()) neighboursLeft.push_back(interest[r+1]);

    if (r-1>=0) neighboursRight.push_back(interest[r-1]);
    if (r+1<interest.size()) neighboursRight.push_back(interest[r+1]);

    for (auto ele : neighboursLeft) if (ele == interest[r]) return false;
    for (auto ele : neighboursRight) if (ele == interest[l]) return false;

    return true;
}

bool hasProblem(int x, vector<int>& interest) {
    int curr = interest[x];

    if (x+1<interest.size() && curr == interest[x+1]) return true;
    if (x-1>=0 && curr == interest[x-1]) return true;

    return false;
}

void solve() {
    int n; cin >> n;
    vector<int> interest(n+1);
    for (int i=1; i<=n; i++) cin >> interest[i];
    
    for (int i=n/2; i>=1; i--) {
        if ( (interest[i] == interest[i+1]) || (interest[n-i+1] == interest[n-i]) ) {
            swap(interest[i], interest[n-i+1]);
        }
    }

    int disturbance = 0;
    for (int i=1; i+1<=n; i++) {
        disturbance += (interest[i] == interest[i+1]);
    }

    cout << disturbance << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
