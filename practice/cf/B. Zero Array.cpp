#include <bits/stdc++.h>
using namespace std;

#define YES cout << "YES\n"
#define NO cout << "NO\n"

typedef long long ll;

void solve() {
    ll n; cin >> n;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;

    ll sum = accumulate(vec.begin(), vec.end(), 0LL);

    if (sum & 1LL) {NO; return;}

    sort(vec.begin(), vec.end());

    ll single = 0, dbl = 0;

    for (int i=n-1, k=0; i-1>=0 && k<i; i-=2) {
        ll diff = vec[i] - vec[i-1];

        ll can_subtract = min( (diff/2LL) * 2LL, dbl );

        diff -= can_subtract;
        dbl -= can_subtract;

        while (k<i-1 && diff > 0) {
            ll sub = min(diff, vec[k]);
            vec[k] -= sub;
            diff -= sub;
            if (vec[k] == 0) k++;
        }

        if (diff != 0) {NO; return;}

        dbl += vec[i-1] * 2LL;
    }

    YES;


    

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

