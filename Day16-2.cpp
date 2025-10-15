#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

long long solve(vector<vector<char>>& grid, int n, vector<vector<long long>>& dp, int i, int j) {
    if(grid[i][j] == '*') return 0;      
    if(i == n-1 && j == n-1) return 1;    
    if(dp[i][j] != -1) return dp[i][j];

    long long right = 0, down = 0;
    if(j + 1 < n) right = solve(grid, n, dp, i, j + 1);
    if(i + 1 < n) down = solve(grid, n, dp, i + 1, j);

    dp[i][j] = (right + down) % MOD; 
    return dp[i][j]; 
}

long long gridPath(vector<vector<char>>& grid, int n) {
    vector<vector<long long>> dp(n, vector<long long>(n, -1));
    return solve(grid, n, dp, 0, 0);
}

int main() {
    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> grid[i][j]; 

    cout << gridPath(grid, n);
    return 0;
}
