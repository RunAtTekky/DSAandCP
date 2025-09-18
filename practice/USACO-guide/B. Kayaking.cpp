#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n; cin >> n;
    ll people = 2 * n;

    vector<ll> weights(people);
    for (auto &weight : weights) cin >> weight;

    sort(weights.begin(), weights.end());

    ll minimum_instability = INT_MAX;
    for (int i=0; i<people; i++) {
        for (int j=i+1; j<people; j++) {
            vector<ll> new_weights;
            for (int k=0; k<people; k++) {
                if ((k==i) || (k==j)) continue;
                new_weights.push_back(weights[k]);
            }
            // /usr/include/c++/15.2.1/bits/stl_vector.h:1263: std::vector<_Tp, _Alloc>::reference std::vector<_Tp, _Alloc>::operator[](size_type) [with _Tp = long long int; _Alloc = std::allocator<long long int>; reference = long long int&; size_type = long unsigned int]: Assertion '__n < this->size()' failed.


            // for (auto &ele : new_weights) cout << ele << " ";
            // cout << "\n";
            
            ll instability = 0;
            for (int k=0; k<new_weights.size(); k+=2) {
                instability += abs(new_weights[k] - new_weights[k+1]);
            }

            // cout << i << " " << j << " " << instability << "\n";
            minimum_instability = min(minimum_instability, instability);
        }
    }

    cout << minimum_instability << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

