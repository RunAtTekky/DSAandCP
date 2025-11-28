#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SegTree {
public:
    vector<ll> segment;
    vector<ll> vec;

    SegTree(ll n, vector<ll> vec) {
        segment.resize(4*n + 1);
        this->vec = vec;

        build_segment_tree(0, 0, n-1);
    }

    void build_segment_tree(int index, int low, int high) {
        if (low == high) {
            segment[index] = vec[low];
            return;
        }

        int mid = (low + high) / 2;

        build_segment_tree(2*index + 1, low, mid);
        build_segment_tree(2*index + 2, mid+1, high);

        segment[index] = max(segment[2*index+1], segment[2*index+2]);
    }

    int query_segment_tree(int index, int low, int high, int l, int r) {

        // Completely has it -> return the value at that index
        if (l <= low && high <= r) return segment[index];

        // Doesn't have it -> return worst value
        if (l > high || r < low) return INT_MIN;

        int mid = (low + high) / 2;

        // Overlapping -> go both side
        int lft = query_segment_tree(2*index+1, low, mid, l, r);
        int rgt = query_segment_tree(2*index+2, mid+1, high, l, r);

        return max(lft, rgt);
    }
};


int main() {
    // Test the segment tree here

    // Create a random array
    srand(time(0));
    const ll MAXI = 100;
    ll n = rand() % MAXI;
    vector<ll> a(n);
    for (int i=0; i<n; i++) {
        a[i] = rand() % MAXI;
    }

    // Build the segment tree
    SegTree st = SegTree(n, a);

    // Test queries
    ll queries = 1000;
    bool isWrong = false;
    for (int q=0; q<queries; q++) {
        ll l = rand() % n;
        ll r = rand() % n;
        if (l>r) swap(l,r);

        ll maxi = *max_element(a.begin() + l, a.begin() + r + 1);
        ll max_from_segtree = st.query_segment_tree(0, 0, n-1, l, r);

        if (maxi != max_from_segtree) {
            isWrong = true;
            cout << "WA" << "\n";
            cout << q << " " << l << " " << r << "\n";
            cout << maxi << " " << max_from_segtree << "\n";

            for (auto &ele : a) cout << ele << " ";
            cout << "\n";
            
            break;
        }
    }

    if (!isWrong) cout << "AC" << "\n";
}
