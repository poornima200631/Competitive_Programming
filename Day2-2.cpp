#include<iostream>
#include<vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

long long stickLengths(vector<int>& inputs) {
    int n = inputs.size();

    sort(inputs.begin(), inputs.end());
    int length = n / 2;  
    int req_length = inputs[length];

    long long ans = 0;  
    for (int i = 0; i < n; ++i) {
        ans += abs(req_length - inputs[i]);
    }

    return ans;
}


int main(){
  int n,ele;
  cin>>n;
   vector<int>inputs;
   for(int i=0;i<n;++i){
    cin>>ele;
    inputs.push_back(ele);
   }


   long long ans=stickLengths(inputs);

   cout<<ans;

   return 0;
}