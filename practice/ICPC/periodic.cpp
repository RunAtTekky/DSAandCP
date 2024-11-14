#include <bits/stdc++.h>
using namespace std;

map<int,int> mp;

map<int, vector<int>> periodic_bits;

vector<int> getPeriodic(int bits) {
    // cout << bits << " bits \n";
    vector<int> periodic_numbers;

    int all_ones = (1 << bits) - 1;
    periodic_numbers.push_back(all_ones);

    for (int i=bits/2; i>=1; i--) {
        if (bits%i != 0) continue;
        int number = 0;

        int cycles = bits/i;

        bool oneTurn = true;
        while (cycles--) {
            int times = i;
            while (times--) {
                number = number << 1;
                if (oneTurn) number++;
            }
            oneTurn = !oneTurn;
        }

        periodic_numbers.push_back(number);
    }

    return periodic_numbers;
}

void precompute() {
    for (int i=1; i<=32; i++) {
        periodic_bits[i] = getPeriodic(i);
    }
}

void solve() {
    int L,R; cin >> L >> R;

    int bitsInL, bitsInR;

    bitsInL = 1 + (int) log2(L);
    bitsInR = 1 + (int) log2(R);

    long long total_periodic = 0;
    for (int bits=bitsInL+1; bits<bitsInR; bits++) {
        total_periodic += periodic_bits[bits].size();
    }

    // To check R we will find all the possible periodic numbers of that bit
    auto periodic_numbers_R = periodic_bits[bitsInR];

    if (bitsInL == bitsInR) {
        for (auto num : periodic_numbers_R) {
            // cout << num << " ";
            total_periodic += ( (num <= R) && (num >= L) ) ? 1 : 0;
        }
        cout << total_periodic << "\n";
        return;
    }

    auto periodic_numbers_L = periodic_bits[bitsInL];

    for (auto num : periodic_numbers_R) {
        // cout << num << " ";
        total_periodic += (num <= R) ? 1 : 0;
    }

    // cout << " R \n";

    for (auto num : periodic_numbers_L) {
        // cout << num << " ";
        total_periodic += (num >= L) ? 1 : 0;
    }
    // cout << " L \n";

    cout << total_periodic << "\n";

}

int main() {
    precompute();
    int t=1; cin >> t;
    while (t--) solve();
}
