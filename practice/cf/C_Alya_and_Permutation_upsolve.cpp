#include <bits/stdc++.h>
using namespace std;

int getHighestBit(int n) {
    int i=0;
    while (n>1) {
        i++;
        n = n>>1;
    }

    return 1<<i;
}

void solve() {
    int n; cin >> n;

    vector<int> perm(n);

    // Three cases
    // n is odd
    // Last operation performed will be &
    // Thus the most we can get is n only
    // We need to have k till second last equal to n
    // 101100101010 - 10 == 101100101000
    // 000000000010
    // l is lowest bit
    // l, l + (l==1 ? 2 : 1), n-l, n
    // Subtracting the lowest bit from n - l

    vector<bool> taken(n+1);
    int lowestBit = n & (-n);

    bool isPowerOfTwo = ((n&(n-1)) == 0);

    if (n&1) {
        perm[n-1] = n;
        perm[n-2] = n - lowestBit;
        perm[n-3] = lowestBit + (lowestBit==1 ? 2 : 1); // If 00001 make it 00011
        perm[n-4] = lowestBit;

        taken[n] = true;
        taken[n-lowestBit] = true;
        taken[perm[n-3]] = true;
        taken[lowestBit] = true;
    }

    // n is even but not a power of 2
    // Highest Bit - 1 will have all bits except highest bit
    // If we have n, n-1, h-1
    // First two will give us the highest bit and then or-ing with all bits except highest
    // will give us all the bits

    else if (!isPowerOfTwo) {
        int highestBit = getHighestBit(n);
        perm[n-1] = highestBit-1;
        perm[n-2] = n-1;
        perm[n-3] = n;

        taken[highestBit-1] = true;
        taken[n-1] = true;
        taken[n] = true;
    }

    // n is even and power of 2
    // 1, 3, n-2, n-1, n

    else {

        perm[n-1] = n;
        perm[n-2] = n-1;
        perm[n-3] = n-2;
        perm[n-4] = 3;
        perm[n-5] = 1;

        taken[n] = true;
        taken[n-1] = true;
        taken[n-2] = true;
        taken[3] = true;
        taken[1] = true;
    }

    int k=0;

    for (int i=0, j=1; i<n; i++) {
        if (perm[i] != 0) continue;
        while (j<=n && taken[j]) j++;
        taken[j] = true;
        perm[i] = j;
    }

    for (int i=0; i<n; i++) {
        if (i&1) k |= perm[i];
        else k &= perm[i];
    }

    cout << k << "\n";

    for (auto ele : perm) cout << ele << " ";
    cout << "\n";

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
