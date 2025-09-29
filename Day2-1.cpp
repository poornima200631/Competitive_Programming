#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int collectingNumbers(vector<int>& inputs) {
    int n = inputs.size();
    vector<int> leftGreater(n, -1); 
    stack<int> st; 

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && inputs[st.top()] < inputs[i]) {
            st.pop(); 
        }
        if (!st.empty()) {
            leftGreater[i] = st.top();
        }
        st.push(i);
    }

 
    int ans = 1; 
    for (int i = 1; i < n; ++i) { 
        if (leftGreater[i] != -1 && inputs[i-1] > inputs[i]) {
            ans++;
        }
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

 int ans=collectingNumbers(inputs);

 cout<<ans;

return 0;
}
