import java.io.*;
import java.util.*;

public class RemovingDigits {
    static long[] dp;
    static int inf = Integer.MAX_VALUE;
    static int mod = (int) 1e9 + 7;
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = 0;
        try {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
        } catch (IOException e) {
        }


        dp = new long[n + 1];
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = inf;
            int t = i;
            while (t > 0) {
                int y = t % 10;
                if (i - y >= 0) {
                    dp[i] = Math.min(dp[i], dp[i - y] + 1);
                }
                t /= 10;
            }
        }
        System.out.println(dp[n]);
    }
}
