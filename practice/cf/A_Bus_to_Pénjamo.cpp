#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,r; cin >> n >> r;

    vector<int> families(n);
    for (auto &members : families) cin >> members;

    int max_happy_people = 0;
    int leftAlone = 0;

    for (auto members : families) {
        if (members&1) {
            leftAlone++;
            max_happy_people += members - 1;
            r -= (members-1) / 2;
        }
        else {
            max_happy_people += members;
            r -= members / 2;
        }
    }

    // Find how many people left alone can be happy with r remaining seats
    // Mind that we have to make everyone sit in the bus
    // If there are 3 rows left and 4 people left then we can have 2 people happy

    while (leftAlone > r) {
        r--;
        leftAlone -= 2;
    }

    max_happy_people += leftAlone;

    cout << max_happy_people << "\n";

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
