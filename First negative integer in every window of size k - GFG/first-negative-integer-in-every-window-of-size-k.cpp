//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int n, long long int k) {
                                                 
        deque<pair<int,int>>q;
        
        for(int i=0;i<k;i++){
            if(A[i]<0){
                q.push_back({A[i],i});
            }
        }
        
          vector<long long>ans;
          if(q.empty())
          ans.push_back(0);
          
          else{
              pair<int,int>front=q.front();
              ans.push_back(front.first);
          }
          
          pair<int,int>curr;
          curr=q.front();
          
          for(int i=k;i<n;i++){
              if(!q.empty() && curr.second==i-k)
              q.pop_front();
              
              if(A[i]<0)
              q.push_back({A[i],i});
              
              if(!q.empty()){
              curr=q.front();
              ans.push_back(curr.first);
              }
              else{
                  ans.push_back(0);
              }
              
          }
                 return ans;                                
 }