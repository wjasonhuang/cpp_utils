#include <vector>
using std::vector;

template<class T>
class TopN {
public:
    int n;
    vector<T> v;
    vector<int> cnt;

    TopN() { n = 0; }

    TopN(int size) {
        n = size;
        v = vector<T>(n, -1);
        cnt = vector<int>(n, 0);
    }

    void update(T val, int count = 1) {
        for (int i = 0; i < n; i++) {
            if (v[i] == val) {
                cnt[i] += count;
                return;
            }
            if (val > v[i]) {
                for (int j = n - 1; j > i; j--) {
                    v[j] = v[j - 1];
                    cnt[j] = cnt[j - 1];
                }
                v[i] = val;
                cnt[i] = count;
                return;
            }
        }
    }
};
