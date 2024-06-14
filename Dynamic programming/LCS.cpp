#include<iostream>
#include<string>
#include<cmath>
using namespace std;
//Longest common subsequence problem
//Brute force- Time complexity= O(2^n)
//Memoization- Time Complexity= Space complexity =O(m*n); m=s1.length(),n=s2.length(), space is still more duue to recursive calls
//Dynamic Programming- Time Complexity= Space complexity =O(m*n); m=s1.length(),n=s2.length()

int lcs_DP(string s1,string s2){
int **output= new int*[s1.length()+1];
int len1=s1.length();
int len2=s2.length();

for(int i=0;i<len1+1;i++){
    output[i]= new int[len2+1];
    output[i][0]=0;
}
    for(int j=0;j<len2+1;j++){
        output[0][j]=0;
    }


 for(int i=1;i<len1+1;i++){
    for(int j=1;j<len2+1;j++){
        if(s1[len1-i]== s2[len2-j]){
            output[i][j]= 1+output[i-1][j-1];
        }
        else{
          output[i][j]= max(output[i-1][j-1],max(output[i-1][j],output[i][j-1]));
        }
    }
 }
    for(int i=0;i<s1.length()+1;i++)
        delete[] output[i];
    delete[] output;

 return output[len1][len2];

}

int mem_helper(string s1,string s2,int **output){
    //base case
 if(s1.empty() || s2.empty()){
    return 0;
 }

  if(output[s1.length()][s2.length()]!=-1){
    return output[s1.length()][s2.length()];
  }

  if(s1[0]==s2[0]){
    int res=mem_helper(s1.substr(1),s2.substr(1),output) +1;
    output[s1.length()][s2.length()]=res;
    return res;
  }

  else{
    int first= mem_helper(s1.substr(1),s2.substr(1),output);
   int second= mem_helper(s1,s2.substr(1),output);
   int third= mem_helper(s1.substr(1),s2,output);
    int res= max(first,max(second,third));
     output[s1.length()][s2.length()]=res;
    return res;
  }
}

int lcs_mem(string s1,string s2){
int **output= new int*[s1.length()+1];

for(int i=0;i<s1.length()+1;i++){
    output[i]= new int[s2.length()+1];
    for(int j=0;j<s2.length()+1;j++)
        output[i][j]=-1;
}

return mem_helper(s1,s2,output);
}

int lcs(string s1,string s2){
 //base case
 if(s1.empty() || s2.empty()){
    return 0;
 }

  if(s1[0]==s2[0]){
    return lcs(s1.substr(1),s2.substr(1)) +1;
  }

  else{
   int first= lcs(s1.substr(1),s2.substr(1));
   int second= lcs(s1,s2.substr(1));
   int third= lcs(s1.substr(1),s2);
    return max(first,max(second,third));
  }

}

int main(){
string s1,s2;

cin>>s1>>s2;
cout<<lcs(s1,s2)<<endl;
cout<<lcs_mem(s1,s2)<<endl;
cout<<lcs_DP(s1,s2)<<endl;
return 0;
}
