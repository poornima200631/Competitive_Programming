#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void threeSum(vector<int>& inputs, vector<int>& ans, int target) {
    int n = inputs.size();
    vector<pair<int,int>> index;
    for (int i = 0; i < n; i++) {
        index.push_back({inputs[i], i});
    }

    sort(index.begin(), index.end());

    for (int i = 0; i < n - 2; ++i) {
        int j = i + 1;
        int q = n - 1;
        while (j < q) {
            long long sum = (long long)index[i].first + index[j].first + index[q].first;
            if (sum > target) q--;
            else if (sum < target) j++;
            else {
                ans.push_back(index[i].second);
                ans.push_back(index[j].second);
                ans.push_back(index[q].second);
                return;
            }
        }
    }
}

int main() {
    int n, sum;
    cin >> n >> sum;

    vector<int> inputs(n);
    for (int i = 0; i < n; ++i) {
        cin >> inputs[i];
    }

    vector<int> ans;
    threeSum(inputs, ans, sum);

    if (ans.empty()) cout << "IMPOSSIBLE\n";
    else {
        for (int i = 0; i < 3; ++i)
            cout << ans[i] + 1 << " ";
        cout << "\n";
    }

    return 0;
}
