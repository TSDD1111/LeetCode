bool isMatch(char * s, char * p){
    int sLength = strlen(s), pLength = strlen(p);
    int dp[sLength + 1][pLength + 1];
    memset(dp, 0, sizeof(dp));    //dp全部赋值为0
    dp[0][0] = 1;
    //对第一行进行赋值，p开头连续几个*就几个1
    for(int i = 1; i <= pLength; i++){
        if(p[i - 1] == '*'){
            dp[0][i] = 1;
        }
        else{
            break;
        }
    }
    //进行状态转移判断
    for(int i = 1; i <= sLength; i++){
        for(int j = 1; j <= pLength; j++){
            //当新的字符相同时，dp[i][j]的值与dp[i - 1][j - 1]相同
            if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                dp[i][j] = dp[i - 1][j - 1];
            }
            //当p为*时，可以使用*也可以不使用，此时dp[i][j]可以等于dp[i - 1][j]也可以等于dp[i][j - 1]
            else if(p[j - 1] == '*'){
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            }
        }
    }
    return dp[sLength][pLength];
}
