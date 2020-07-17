#include <bits/stdc++.h>
#define R 10
#define C 10

using namespace std;

void counterClockspiralPrint(int m, int n, int arr[R][C]) 
{ 
    int i, k = 0, l = 0; 
  
    //  k - starting row index 
    //    m - ending row index 
    //    l - starting column index 
    //    n - ending column index 
    //    i - iterator  
  
    // initialize the count 
    int cnt = 0; 
  
    // total number of  
    // elements in matrix 
    int total = m * n; 
  
    while (k < m && l < n)  
    { 
        if (cnt == total) 
            break; 
  
        // Print the first column  
        // from the remaining columns 
        for (i = k; i < m; ++i) 
        { 
            cout << arr[i][l] << ", "; 
            cnt++; 
        } 
        l++; 
  
        if (cnt == total) 
            break; 
  
        // Print the last row from 
        // the remaining rows  
        for (i = l; i < n; ++i)  
        { 
            cout << arr[m - 1][i] << ", "; 
            cnt++; 
        } 
        m--; 
  
        if (cnt == total) 
            break; 
  
        // Print the last column  
        // from the remaining columns  
        if (k < m)  
        { 
            for (i = m - 1; i >= k; --i)  
            { 
                cout << arr[i][n - 1] << ", "; 
                cnt++; 
            } 
            n--; 
        } 
  
        if (cnt == total) 
            break; 
  
        // Print the first row  
        // from the remaining rows  
        if (l < n)  
        { 
            for (i = n - 1; i >= l; --i)  
            { 
                cout << arr[k][i] << ", "; 
                cnt++; 
            } 
            k++; 
        } 
    } 
} 

int main() {
	int m, n;
	cin >> m >> n;

	int mat[R][C];
	for(int i=0; i<m; ++i) 
		for(int j=0; j<n; ++j)
			cin >> mat[i][j];

	counterClockspiralPrint(m, n, mat);
	cout << "END";
	return 0;
}
