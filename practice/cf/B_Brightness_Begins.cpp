#include <bits/stdc++.h>
using namespace std;

/*
We are given k
We need to find n, which is the number of bulbs we must use.
For i=1,2....,n we flip j divisible by i
At the end the number of bulbs which are turned on must be k

1 2 3 4 5 6 7 8 9 10 
0 1 1 0 1 1 1 1 0 1

For each bulb we need to find how many divisors it has.
If even divisors - Turn on the bulb
If odd divisors - Turn off the bulb

But still we will have to go through each of the bulbs to find this
Because k <= 1e18
We will get TLE

Observations:
1. Perfect squares are turned off while others are on.
   This is because we have root(n) as one divisor whereas non-squares will
   two divisors in place of one
   For 36 -> 1, 2, 3, 6, 12, 18, 36
   For 30 -> 1, 2, 3, 5, 6, 10, 15, 30

With the help of this observation we can binary search on n
[0, 1e18]

For 1e18 we will have to go till 1e9 to find the number of bulbs turned ON
which gives TLE

*/

long long getBulbsOn(long long mid) {
    // Basically find how many perfect squares are there till mid
    long long bulbsOff = int(sqrtl(mid));

    return mid - bulbsOff;
}

void solve() {
    long long k; cin >> k;

    long long start = 0, end = 2e18;

    while (start < end) {
        long long mid = (start + end) >> 1;

        long long bulbsOn = getBulbsOn(mid);

        if (bulbsOn >= k) end = mid;
        else start = mid+1;
    }

    cout << end << "\n";

}

int main() {
    int t=1; cin >> t;
    while (t--) solve();
}
