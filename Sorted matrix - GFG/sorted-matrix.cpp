//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

vector<vector<int>> sortedMatrix(int N, vector<vector<int>> Mat) {
    // Flatten the matrix
    vector<int> flattened;
    for (const auto &row : Mat) {
        flattened.insert(flattened.end(), row.begin(), row.end());
    }

    // Sort the flattened vector
    sort(flattened.begin(), flattened.end());

    // Reconstruct the sorted matrix
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            Mat[i][j] = flattened[i * N + j];
        }
    }

    return Mat;
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends