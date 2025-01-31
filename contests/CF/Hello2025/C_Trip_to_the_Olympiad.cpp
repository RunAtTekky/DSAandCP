#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(string n) {
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}

void solve() {
    long long l,r; cin >> l >> r;

    // Figure out till where they are similar.

    bitset<32> bits_l(l);
    bitset<32> bits_r(r);

    string s_l = "";
    string s_r = "";

    for (int i=31; i>=0; i--) {
        s_l += (bits_l.test(i) == 1) ? "1" : "0";
    }

    for (int i=31; i>=0; i--) {
        s_r += (bits_r.test(i) == 1) ? "1" : "0";
    }

    // cout << s_l << "\n";
    // cout << s_r << "\n";

    int i = 0;

    for (i=0; i<32; i++) {
        if (s_l[i] != s_r[i]) break;
    }

    string a = "";
    string b = "";
    string c = "";

    for (int idx=i; idx<32; idx++) {
        if (s_r[idx] == '1') {
            a.push_back('1');
            b.push_back('0');
            c.push_back('0');
        }
        else {
            a.push_back('0');
            b.push_back('1');
            c.push_back('1');
        }
    }

    int sz = b.size();

    if (b[sz-1] == '1') c[sz-1] = '0';
    else c[sz-1] = '1';

    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";

    int i_a = binaryToDecimal(a);
    int i_b = binaryToDecimal(b);
    int i_c = binaryToDecimal(c);

    cout << i_a << "\n";
    cout << i_b << "\n";
    cout << i_c << "\n";

    int answer = (i_a^i_b) + (i_a^i_c) + (i_b^i_c);

    cout << answer << "\n";

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t=1; cin >> t;
    while (t--) solve();
}
