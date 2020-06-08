int count_DP(int n) {
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 2;
    dp[2] = 3;

    for(int i=3; i<=n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << count_DP(n) << "\n";
    }
}
