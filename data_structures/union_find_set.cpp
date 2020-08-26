#include <algorithm>    // std::swap
#include <numeric>      // std:iota
#include <vector>       // std:vector
using std::vector;
using std::swap;

class UnionFindSet {
public:
    vector<int> p, rk;

    UnionFindSet(int n) {
        rk = vector<int>(n, 0);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    int find(int v) { return (p[v] == v ? v : p[v] = find(p[v])); }

    bool merge(int v1, int v2) {
        v1 = find(v1);
        v2 = find(v2);
        if (v1 == v2) return true;
        if (rk[v1] < rk[v2]) swap(v1, v2);
        p[v2] = v1;
        rk[v1] += rk[v1] == rk[v2];
        return false;
    }
};