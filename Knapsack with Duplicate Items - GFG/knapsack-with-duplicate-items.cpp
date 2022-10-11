//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include<bits/stdc++.h>
class Solution{
public:
    int knapSack(int N, int w, int val[], int wt[])
    {
        // code here
        
        vector<vector<int>>dp(N, vector<int>(w+1,0));
        
        for(int W=0; W<=w; W++)
            dp[0][W] = ((int)(W/wt[0]))*val[0];
    
    
    for(int ind=1; ind<N; ind++){
        for(int W=0; W<=w; W++){
                int ov = dp[ind-1][W];
                int nv=0;
                if(wt[ind]<=W)
                    nv =  val[ind]+dp[ind][W-wt[ind]];
                dp[ind][W] = max(ov,nv);
        }
}
    return dp[N-1][w];
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends