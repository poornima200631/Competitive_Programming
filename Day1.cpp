#include<iostream>
#include<vector>
using namespace std;

bool checkSum(vector<vector<int>> &dp, vector<int>& input, int target, int index) {
  if (target == 0) return true;
if (index < 0) return false;
if (dp[index][target] != -1) return dp[index][target];

    bool take = false, nottake = false;

    if (input[index] <= target) 
        take = checkSum(dp, input, target - input[index], index - 1);
    nottake = checkSum(dp, input, target, index - 1);

    dp[index][target] = take || nottake;
return dp[index][target];

}

int missingCoins(vector<int> input) {
    int s = input.size();
    int sum = 0;
    for (int i = 0; i < s; ++i) sum += input[i];

  vector<vector<int>> dp(s, vector<int>(sum+1, -1));


    int output = 0;
    for (int i = 1; i <= sum + 1; ++i) { 
        bool ans = checkSum(dp, input, i, s - 1);
        if (!ans) return i; 
    }
    return output;
}

int main() {
    int n, ele;
    cin >> n;
    vector<int> input;
    for (int i = 0; i < n; ++i) {
        cin >> ele;
        input.push_back(ele);
    }

    int ans = missingCoins(input);
    cout << ans;
    return 0;
}

