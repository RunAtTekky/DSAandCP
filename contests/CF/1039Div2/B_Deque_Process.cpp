#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> vec;
ll a, b, lft, rgt, curr, sz;
string ans;
bool inc;
ll last_lft;

void take_lft(ll &idx) {
    cout << "L";
    curr = a;
    idx++;
    a = vec[idx];
    sz++;
    last_lft = true;
}

void take_rgt(ll &idx) {
    cout << "R";
    curr = b;
    idx--;
    b = vec[idx];
    sz++;
    last_lft = false;
}

void solve() {
    ll n; cin >> n;
    vec = vector<ll>(n);
    for (auto &ele : vec) cin >> ele;
    
    a = vec.front(), b = vec.back();
    lft = 0, rgt = n-1, curr = -1, sz = 0;
    ans = "";
    inc = true;
    last_lft = true;

    while (lft < rgt) {
        if (curr < a && curr < b) {
            if (a < b) { take_rgt(rgt); }
            else { take_lft(lft); }
            inc = true;
        } else if (curr > a && curr > b) {
            if (a > b) { take_rgt(rgt); }
            else { take_lft(lft); }
            inc = false;
        } else {
            if (inc) {
                if (a<b) { take_lft(lft); }
                else { take_rgt(rgt); }
            } else {
                if (a<b) { take_rgt(rgt); }
                else { take_lft(lft); }
            }
            inc = !inc;
        }
    }

    if (last_lft) cout << "R";
    else cout << "L";

    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
