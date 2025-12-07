#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;

    for (int start = 0; start < n; start++) {
        for (int len = 2; len <= n; len += 2) {
            unordered_map<int, int> freq;
            for (int j = 0; j < len; j++) {
                int idx = (start + j) % n;
                freq[a[idx]]++;
            }
            bool balanced = true;
            for (auto& [val, cnt] : freq) {
                if (cnt % 2 != 0) {
                    balanced = false;
                    break;
                }
            }

            if (balanced) {
                count++;
            }
        }
    }

    cout << count << '\n';
    return 0;
}