#include<iostream>
#include<stack>
#include<vector>
using namespace std;

   void  NearestSmallerVlaues(vector<int>&inputs,vector<int>&ans){
    int n=inputs.size();
       stack<int>st;
        st.push(0);
         for(int i=1;i<n;++i){
             int flag=0;
             while(!st.empty()&&flag==0){
              int index=st.top();
              if(inputs[index]<inputs[i]){
                ans[i]=index+1;
                flag=1;
              }else if(inputs[index]>=inputs[i]){
                 st.pop();
              }
             }
             st.push(i);
         }

   }


int main(){
      int n;
      cin>>n;

     vector<int>inputs(n);
     for(int i=0;i<n;++i){
           cin >> inputs[i];
     }
     
     vector<int>ans(n,0);

     NearestSmallerVlaues(inputs,ans);

      for(int i=0;i<n;++i){
        cout<<ans[i]<<" ";
      }

      return 0;
}