#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool subset_sum(vector<int> arr,int sum){
    int n = arr.size();
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i==0)
                dp[i][j] = false;
            if(j==0)
                dp[i][j] = true;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(arr[i-1]<=j)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main(){
    vector<int> arr;
    int sum;
    int n;
    cin>>n;
    int val;
    for(int i=0;i<n;i++){
        cin>>val;
        arr.push_back(val);
    }
    cin>>sum;
    cout<<subset_sum(arr,sum)<<endl;
    return 0;
}