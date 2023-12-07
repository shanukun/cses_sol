import java.io.*;
import java.util.*;

public class GridPath2 {
    static int[][] dp;
    static int mod = (int) 1e9 + 7;
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int n = 0;
        try {
            st = new StringTokenizer(br.readLine());
            n = Integer.parseInt(st.nextToken());
        } catch (IOException e) { }

        String[] grid = new String[n];
        try {
            for (int i = 0; i < n; i++) {
                grid[i] = br.readLine();
            }
        } catch (IOException e) { }

        dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) dp[i][j] = 1;
                else {
                    if (i - 1 >= 0 && grid[i - 1].charAt(j) != '*')
                        dp[i][j] = dp[i - 1][j];
                    if (dp[i][j] >= mod) dp[i][j] -= mod;
                    if (j - 1 >= 0 && grid[i].charAt(j - 1) != '*')
                        dp[i][j] += dp[i][j - 1];
                    if (dp[i][j] >= mod) dp[i][j] -= mod;
                }
            }
        }

        if (dp[n - 1][n - 1] >= mod) dp[n - 1][n - 1] -= mod;
        if (grid[n - 1].charAt(n - 1) == '*') dp[n - 1][n - 1] = 0;
        System.out.println(dp[n - 1][n - 1]);
    }
}
