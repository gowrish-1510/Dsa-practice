#include<iostream>
using namespace std;

int fibo_helper(int n,int *ans){
if(n<=1)
    return n;

 //check if output already exists
 //if yes
 if(ans[n]!=-1)
    return ans[n];

 //else
  int a= fibo_helper(n-1,ans);
  int b= fibo_helper(n-2,ans);

  //save the output for future use
  ans[n]=a+b;
  return ans[n];

}
// Dynamic programming approach- O(n)
int fibo_dp(int n){
int *ans= new int[n+1];
ans[0]=0;
ans[1]=1;

for(int i=2;i<=n;i++){
    ans[i]=ans[i-1]+ans[i-2];
}

return ans[n];

}

//using memoization- O(n)
int fibo_memoization(int n){
int *ans= new int[n+1];

for(int i=0;i<n+1;i++){
    ans[i]=-1;
}
 return fibo_helper(n,ans);
}


int main(){
int n;
cout<<"enter n: ";
cin>>n;

cout<<"fib(n) is "<<fibo_memoization(n)<<endl;
cout<<"using DP: "<<fibo_dp(n);

}
