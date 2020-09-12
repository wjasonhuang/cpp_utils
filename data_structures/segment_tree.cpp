#include <vector>
using std::vector;

class SegmentTree {
public:
    vector<int> tree;
    int n;
    
    void build(vector<int>& arr) {
        n = arr.size();
        tree = vector<int>(n, 0);
        tree.insert(tree.end(), arr.begin(), arr.end());
        for (int i = n - 1; i > 0; i--) tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }

    void modify(int p, int value) {  // set value at position p
        for (tree[p += n] = value; p > 1; p >>= 1) tree[p >> 1] = tree[p] + tree[p ^ 1];
    }

    int query(int l, int r) { // sum on interval [l, r)
        int tot = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) tot += tree[l++];
            if (r & 1) tot += tree[--r];
        }
        return tot;
    }
};
