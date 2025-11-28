#include <bits/stdc++.h>
#include <numeric>
using namespace std;

typedef long long ll;

class SegTree {
public:
    SegTree *lft;
    SegTree *rgt;

    ll leftmost, rightmost;
    ll sum;

    SegTree(int l, int r, vector<ll> a) {
        this->leftmost = l;
        this->rightmost = r;

        if (leftmost == rightmost) {
            sum = a[l];
        } else {
            ll mid = (l + r) / 2;
            this->lft = new SegTree(l, mid, a);
            this->rgt = new SegTree(mid+1, r, a);
            recalc();
        }
    }

    void recalc() {
        if (leftmost == rightmost) return;
        sum = lft->sum + rgt->sum;
    }

    void pointUpdate(int index, ll newVal) {
        if (leftmost == rightmost) {
            sum = newVal;
            return;
        }
        (index <= lft->rightmost) ? lft->pointUpdate(index, newVal) : rgt->pointUpdate(index, newVal);
        recalc();
    }

    ll rangeSum(int l, int r) {
        if (r < leftmost || l > rightmost) return 0;
        if (l <= leftmost && r >= rightmost) return sum;

        return lft->rangeSum(l,r) + rgt->rangeSum(l,r);
    }
};

int main() {
    // Test the segment tree here
    srand(time(0));
    const ll MAXI = 100;
    ll n = rand() % MAXI;
    vector<ll> a(n);
    for (int i=0; i<n; i++) {
        a[i] = rand() % MAXI;
    }

    SegTree *st = new SegTree(0, n-1, a);

    ll queries = 1000;
    bool isWrong = false;
    for (int q=0; q<queries; q++) {
        ll l = rand() % n;
        ll r = rand() % n;
        if (l>r) swap(l,r);

        ll sum_of_range = accumulate(a.begin() + l, a.begin() + r + 1, 0LL);
        ll sum_from_segtree = st->rangeSum(l, r);

        if (sum_of_range != sum_from_segtree) {
            isWrong = true;
            cout << "WA" << "\n";
            cout << q << " " << l << " " << r << "\n";
            cout << sum_of_range << " " << sum_from_segtree << "\n";
            for (auto &ele : a) cout << ele << " ";
            cout << "\n";
            break;
        }
    }

    if (!isWrong) {
        cout << "AC" << "\n";
        cout << "Successful queries: " << " " << queries << "\n";
    }
}
