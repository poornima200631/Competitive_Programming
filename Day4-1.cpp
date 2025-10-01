#include<iostream>
#include<vector>
#include<set>
using namespace std;

int totalTowers(vector<int>& input, int &s) {
  multiset<int>ms;
    ms.insert(input[0]);
  for(int i=1;i<s;++i){
       auto it=ms.upper_bound(input[i]);
        if(it!=ms.end()){
          ms.erase(it);
        }
          ms.insert(input[i]);
        
  }


return ms.size();
}

int main() {
    int n, cubes;
    cin >> n;
    vector<int> input;

    for(int i = 0; i < n; ++i) {
        cin >> cubes;
        input.push_back(cubes);
    }

    int towers = totalTowers(input, n);
    cout << towers;

    return 0;
}
