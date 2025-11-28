#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SegTree {
public:
    SegTree *lft;
    SegTree *rgt;

    int leftmost, rightmost;
    ll sum, lazy;

    SegTree(int l, int r, vector<ll>& a) {
        this->leftmost = l;
        this->rightmost = r;
        this->lazy = 0;

        if (leftmost == rightmost) {
            sum = a[l];
        } else {
            ll mid = (l + r) / 2;
            this->lft = new SegTree(l, mid, a);
            this->rgt = new SegTree(mid+1, r, a);
            recalc();
        }
    }

    void propagate() {
        if (lazy == 0) return;

        sum += (rightmost - leftmost + 1) * lazy;

        if (leftmost != rightmost) {
            lft->lazy += lazy;
            rgt->lazy += lazy;
        }

        lazy = 0;
    }

    void recalc() {
        if (leftmost == rightmost) return;
        sum = lft->sum + rgt->sum;
    }

    void pointUpdate(int index, ll newVal) {
        if (leftmost == rightmost) {
            sum = newVal; return;
        }
        (index <= lft->rightmost) ? lft->pointUpdate(index, newVal) : rgt->pointUpdate(index, newVal);
        recalc();
    }

    void rangeUpdate(int l, int r, ll add_this) {
        propagate();

        // No overlap
        if (r < leftmost || l > rightmost) return;

        // Complete overlap
        if (l <= leftmost && r >= rightmost) {
            this->lazy += add_this;
            propagate();
            return;
        }

        // Partial
        lft->rangeUpdate(l, r, add_this);
        rgt->rangeUpdate(l, r, add_this);

        recalc();
    }

    ll rangeSum(int l, int r) {
        propagate();
        if (r < leftmost || l > rightmost) return 0;
        if (l <= leftmost && r >= rightmost) return sum;

        return lft->rangeSum(l,r) + rgt->rangeSum(l,r);
    }

    void traverse_leafs(vector<ll>& vals) {
        propagate();

        if (leftmost == rightmost) {
            vals.push_back(sum); return;
        }


        lft->traverse_leafs(vals);
        rgt->traverse_leafs(vals);
    }
};

void solve() {
    ll n,q; cin >> n >> q;

    vector<ll> vec(n);
    for (auto &ele : vec) cin >> ele;

    vector<ll> empty(n);
    SegTree *st = new SegTree(0, n-1, empty);

    auto print_leaves = [&]() {
        vector<ll> vals;
        st->traverse_leafs(vals);

        for (auto &ele : vals) cout << ele << " ";
        cout << "\n";
    };

    for (int i=0; i<q; i++) {
        ll l,r; cin >> l >> r;
        st->rangeUpdate(l-1, r-1, 1);
        // print_leaves();
    }


    vector<ll> vals;
    st->traverse_leafs(vals);

    sort(vals.begin(), vals.end());
    sort(vec.begin(), vec.end());

    ll ans = 0;
    for (int i=0; i<n; i++) {
        ans += vals[i] * vec[i];
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    solve();
}

