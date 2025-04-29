class Solution {
public:
    int fib(int n) {

        if(n == 0) return 0;
        if(n == 1) return 1;

        vector<int> dp(n+1,-1);

        // pehla step hota h ki aapko pehle base cases likhne hoet h tabulation k case me
        // we already define the base cases pehle hi

        dp[0] = 0;
        dp[1] = 1;

        // we start with the case 2 kyuki baaki cases humne define krdiye h
        for(int i = 2; i<=n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];

    }
};

// class Solution {
// public:

// int func(int n, vector<int>& dp)
// {
//     if(n <= 1)
//     {
//         return n;
//     }

//     if(dp[n] != -1)
//     {
//         return dp[n];
//     }

//     return dp[n] = func(n-1,dp) + func(n-2,dp);
// }
//     int fib(int n) {

//         vector<int> dp(n+1,-1);

//         if(n == 0) return 0;

//         if(n==1) return 1;

//         return func(n-1,dp) + func(n-2,dp);
        
//     }
// };



// class Solution {
// public:

// int func(int num)
// {
//     if(num <= 1)
//     {
//         return num;
//     }

//     return func(num-1) + func(num-2);
// }
//     int fib(int n) {
        
//         if(n == 0)
//         {
//             return 0;
//         }
//         if(n == 1)
//         {
//             return 1;
//         }

//         return func(n-1) + func(n-2);
        
//     }
// };