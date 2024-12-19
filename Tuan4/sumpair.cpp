#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
int socap(const vector<int>& arr, int M) {
    unordered_set<int> seen;
    int so = 0;
    
    for (int num : arr) {
        int target = M - num;
        if (seen.find(target) != seen.end()) {
            so = so +1;
        }
        seen.insert(num);
    }

    return so;
}
int main() {
    int n, M;
    cin >> n >> M;
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int ketqua = socap(arr, M);
    cout << ketqua << endl;
    
    return 0;
}
