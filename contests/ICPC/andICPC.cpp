#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"  

void solve() {
    int n,k; cin >> n >> k;

    vector<int> vec(n);
    for (auto &ele : vec) cin >> ele;

    vector<bool> canTake(n, true);

    bitset<32> bits_k(k);
    for (int bit=0; bit<32; bit++) {
        if (bits_k.test(bit)) {
            for (int i=0; i<n; i++) {
                int num = vec[i];
                bitset<32> bits_num(num);

                canTake[i] = canTake[i] & bits_num.test(bit);
            }
        }
    }

    map<int, bool> haveZero;

    vector<int> answer;
    for (int i=0; i<n; i++) {
        if (!canTake[i]) continue;

        answer.push_back(i+1);

        int num = vec[i];
        bitset<32> bits_num(num);

        for (int bit=0; bit<32; bit++) {
            if (bits_k.test(bit) == false) {
                if (bits_num.test(bit) == false) haveZero[bit] = true;
            }
        }
    }

    for (int bit=0; bit<32; bit++) {
        if ( (bits_k.test(bit) == false) && !haveZero[bit]) {NO; return;}
    }

    if (answer.empty()) {NO; return;}

    YES;
    cout << answer.size() << "\n";

    for (auto num : answer) cout << num << " ";
    cout << "\n";

}

int main() {
ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
