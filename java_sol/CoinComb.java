import java.io.*;
import java.util.*;

public class CoinComb {
    static int[] dp;
    static int mod = (int) 1e9 + 7;
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = 0, x = 0;
        try {
            st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        x = Integer.parseInt(st.nextToken());
        } catch (IOException e) {
        }

        int[] coins = new int[n];
        try {
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                coins[i] = Integer.parseInt(st.nextToken());
            }
        } catch (IOException e) {
        }


        dp = new int[x + 1];
        dp[0] = 1;

            for (int i = 1; i <= x; i++) {
        for (int j = coins.length - 1; j >= 0; j--) {
                if (i - coins[j] >= 0) {
                    dp[i] += dp[i - coins[j]];
                    if (dp[i] >= mod) dp[i] -= mod;
                }

            }
        }
        if (dp[x] >= mod) dp[x] -= mod;
        System.out.println(dp[x]);
    }
}
