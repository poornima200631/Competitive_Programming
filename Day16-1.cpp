#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int findMaxDigit(int n){
  int maxi=INT_MIN;
  while(n>0){
    int rem=n%10;
    n=n/10;
    maxi=max(maxi,rem);
  }
  return maxi;
}
int removingDigits(int n){

    int mini=0;
  while(n>0){
    int max_digit=findMaxDigit(n);
    n-=max_digit;
    mini+=1;
  }


    return mini;
}
int main(){
  int n;
  cin>>n;
  int min_operations=removingDigits(n);
  cout<<min_operations;
return 0;
}