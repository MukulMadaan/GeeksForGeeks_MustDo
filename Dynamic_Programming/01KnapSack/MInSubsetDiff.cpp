int MinSubsetdiff(int set[], int n) 
{
    int sum = 0;  
    
    for (int i = 0; i < n; i++) sum += arr[i];
    
    bool DP[n + 1][sum + 1]; 
    
    for (int i = 0; i <= n; i++) 
      DP[i][0] = true;    // If sum is 0, then answer is true 
   
    for (int i = 1; i <= sum; i++) 
      DP[0][i] = false;   // If sum is not 0 and set is empty, then answer is false 
      
    for (int i = 1; i <= n; i++) { 
       for (int j = 1; j <= sum; j++) { 
          if(j < set[i - 1]) DP[i][j] = DP[i - 1][j]; 
          if (j >= set[i - 1]) DP[i][j] = DP[i-1][j] || DP[i - 1][j - set[i - 1]]; 
       } 
     } 
     
    int min = INT_MAX; 
    
    for (int i = sum/2; i >= 0; i--) 
    { 
        if (DP[n][i] == true) { 
            min = sum - 2 * i; 
            break; 
        }
    }
    return min; 
}
