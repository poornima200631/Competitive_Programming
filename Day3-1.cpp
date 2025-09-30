#include<iostream>
#include<vector>
#include <set>
#include<algorithm>
#include<climits>
using namespace std;

int longestSequence(vector<int>& inputs, int s) {
    int left = 0, right = 0, max_len = 0;
    set<int> st;

    while (right < s) {
        if (st.find(inputs[right]) == st.end()) {
            st.insert(inputs[right]);
            max_len = max(max_len, right - left + 1);
            right++;
        } else {
            st.erase(inputs[left]); 
            left++;
        }
    }

    return max_len;
}


int main(){
  int n,ele;
  cin>>n;
   vector<int>inputs;
   for(int i=0;i<n;++i){
    cin>>ele;
    inputs.push_back(ele);
   }

   int ans=longestSequence(inputs,n);

   cout<<ans;
   return 0;

}