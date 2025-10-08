#include<iostream>
#include<vector>
using namespace std;

int subarraySum(vector<int>& inputs, int &target){
    int s = inputs.size();
    int left = 0;
    int right = 0;
    int Ans = 0;
    int sum = 0;

    while (right < s) {
        sum += inputs[right];

        while (sum > target && left <= right) {
            sum -= inputs[left];
            left++;
        }

        if (sum == target) {
            Ans++;
            sum -= inputs[left];
            left++;
        }

        right++;
    }

    return Ans;
}

int main(){
    int n, x;
    cin >> n >> x;

    vector<int> inputs(n);
    for(int i = 0; i < n; ++i){
        cin >> inputs[i];
    }

    int ans = subarraySum(inputs, x);
    cout << ans;

    return 0;
}
