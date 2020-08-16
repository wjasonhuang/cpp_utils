class UnionFindSet {
public:
    UnionFindSet(int n) {
        rk = vector<int>(n, 0);
        p = vector<int>(n);
        for (int i = 0; i < n; i++) p[i] = i;
    }

    int find(int v) {
        if (p[v] != v) p[v] = find(p[v]);
        return p[v];
    }
    
    bool merge(int v1, int v2) {
        int p1 = find(v1), p2 = find(v2);
        if (p1 == p2) return true;
        if (rk[p1] < rk[p2]) swap(p1, p2);
        p[p2] = p1;
        rk[p1] += rk[p1] == rk[p2];
        return false;
    }

private:
    vector<int> p, rk;
};