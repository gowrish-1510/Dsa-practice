#include<iostream>
#include<cmath>
using namespace std;

//dynamic programming approach- O(n) - space occupied is lesser than memoization
int min_steps_to1_DP(int n){
 int *ans= new int[n+1];
  ans[1]=0;

  for(int i=2;i<=n;i++){
     if(i%2==0 && i%3==0)
        ans[i]= min(ans[i-1],min(ans[i/2],ans[i/3]))+1;

     else if(i%2==0 && i%3!=0)
        ans[i]= min(ans[i-1],ans[i/2])+1;

     else if(i%3==0 && i%2!=0)
        ans[i]= min(ans[i-1],ans[i/3])+1;

     else
        ans[i]=ans[i-1]+1;
  }

  return ans[n];

}

int min_helper(int *ans,int n){
  if(n<=1)
    return 0;

  if(ans[n]!=-1)  //if saved return that value
    return ans[n];

 int a= min_helper(ans,n-1);
 int b=INT_MAX,c=INT_MAX;
 if(n%2==0)
  b= min_helper(ans,n/2);
 if(n%3==0)
  c= min_helper(ans,n/3);

  int answer= min(a,min(b,c))+1;
  ans[n]= answer; //save the result in an array
  return ans[n];
}

//use of memoization - O(n)
int min_to_one_memo(int n){
int *ans= new int[n+1];
for(int i=0;i<n;i++){
    ans[i]=-1;
}
  return min_helper(ans,n);
}

//brute force- O(2^n)
int min_to_one_brute(int n){
 if(n<=1){
    return 0;
 }

 int a= min_to_one_brute(n-1);
 int b=INT_MAX,c=INT_MAX;
 if(n%2==0)
  b= min_to_one_brute(n/2);
 if(n%3==0)
  c= min_to_one_brute(n/3);

  int ans= min(a,min(b,c))+1;
  return ans;
}

int main(){
int n;
cout<<"enter n:";
cin>>n;

cout<<"min steps to 1 for "<<n<<" is "<<min_to_one_brute(n)<<endl;
cout<<"using dp: "<<min_steps_to1_DP(n);

}
