import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class EditDistance {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        char[] s = br.readLine().toCharArray();
        char[] t = br.readLine().toCharArray();

        int n = s.length;
        int m = t.length;

        int[][] dp = new int[n][m];

        for (int i = 0; i < n; i++) {
            dp[i][0] = s[i] == t[0] ? i : i + 1;
        }
        for (int i = 0; i < m; i++) {
            dp[0][i] = s[0] == t[i] ? i : i + 1;
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; ++j) {
                if (s[i] == t[j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = Math.min(1 + dp[i][j - 1], 1 + dp[i - 1][j]);
                    dp[i][j] = Math.min(dp[i][j], 1 + dp[i - 1][j - 1]);
                }
            }
        }
        
        System.out.println(dp[n - 1][m - 1]);
    }
}
