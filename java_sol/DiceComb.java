import java.io.*;
import java.util.*;


public class DiceComb {
    static int mod = (int) 1e9 + 7;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] dp = new long[n + 1];
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 6; j++) {
                if (i - j >= 0)
                    dp[i] += dp[i - j] % mod;
            }
        }
        System.out.println(dp[n] % mod);
    }
}
