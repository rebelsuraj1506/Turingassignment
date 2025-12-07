#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int count = 0;
    
    for (int start = 0; start < n; start++) {
        unordered_map<int, int> freq;
        
        for (int len = 1; len <= n; len++) {
            int pos = (start + len - 1) % n;
            freq[a[pos]]++;
            
            if (len % 2 == 0) {
                bool allEven = true;
                for (auto [val, cnt] : freq) {
                    if (cnt % 2 == 1) {
                        allEven = false;
                        break;
                    }
                }
                if (allEven) count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}