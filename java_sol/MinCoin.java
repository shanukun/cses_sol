import java.io.*;
import java.util.*;

public class MinCoin {
    static int inf = Integer.MAX_VALUE;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();

        int[] coins = new int[n];
        for (int i = 0; i < n; i++) {
            coins[i] = sc.nextInt();
        }

        long[] dp = new long[x + 1];
        dp[0] = 0;

        for (int i = 1; i <= x; i++) {
            dp[i] = inf;
            for (int j = coins.length - 1; j >= 0; j--) {
                if (i - coins[j] >= 0)
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        System.out.println(dp[x] == inf? -1 : dp[x]);
    }
}
