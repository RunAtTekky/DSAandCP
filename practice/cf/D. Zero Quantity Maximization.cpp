#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

#define x first
#define y second


void simplify(pll &p) {
	if(p.x < 0) {
		p.x *= -1;
		p.y *= -1;
	} else if (p.x == 0 && p.y < 0) {
		p.y *= -1;
	}

	int d = __gcd(abs(p.x), abs(p.y));
	p.x /= d;
	p.y /= d;

    // // If only one of a and b is negative
    // if ((a < 0) ^ (b < 0)) {
    //     a = abs(a);
    //     b = abs(b);
    //     a *= -1;
    // } else {
    //     a = abs(a);
    //     b = abs(b);
    // }
    //
    // ll divisor = gcd(abs(a), abs(b));
    // a /= divisor; b /= divisor;
}

void solve() {
    ll n; cin >> n;

    vector<ll> vec_a(n);
    for (auto &ele : vec_a) cin >> ele;
    
    vector<ll> vec_b(n);
    for (auto &ele : vec_b) cin >> ele;
    
    map<pll,ll> freq;

    ll ans = 0, extra = 0;
    for (int i=0; i<n; i++) {
        ll a = vec_a[i], b = vec_b[i];

        if (a == 0 && b == 0) extra++;
        if (a == 0) continue;

        pll d = {-b, a};

        simplify(d);
        freq[d]++;

        ans = max(ans, freq[d]);
    }

    cout << ans + extra << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

