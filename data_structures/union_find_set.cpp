#include <algorithm>    // std::swap
#include <vector>       // std:vector
using std::vector;
using std::swap;

class UnionFindSet {
public:
    vector<int> p, c;

    UnionFindSet(int n) { p = vector<int>(n, -1); c = vector<int>(n, 1); }
    
    int find(int v) { return (p[v] == -1 ? v : p[v] = find(p[v])); }
    
    bool merge(int v1, int v2) {
        v1 = find(v1); v2 = find(v2);
        if (v1 == v2) return true;
        if (c[v1] < c[v2]) swap(v1, v2);
        p[v2] = v1; c[v1] += c[v2];
        return false;
    }
};