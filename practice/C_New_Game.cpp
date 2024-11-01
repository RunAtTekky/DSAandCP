#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k; cin >> n >> k;

    vector<int> cards(n);
    for (auto &card : cards) cin >> card;

    sort(cards.begin(), cards.end());
    
    int max_cards = 0;
    for (int i=0, j=0; i<n; i++) {
        j = max(i,j);

        while (j+1<n && (cards[j+1] - cards[j] <= 1) && (cards[j+1] - cards[i] < k)) j++;

        max_cards = max(max_cards, j-i+1);
    }

    cout << max_cards << "\n";

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
