import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class ArrayDesc {
    static int mod = (int) 1e9 + 7;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int[] h = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) 
            h[i] = Integer.parseInt(st.nextToken());

        int[][] dp = new int[x + 1][n];

        if (h[0] == 0) {
            for (int i = 1; i <= x; i++)
                dp[i][0] = 1;
        } else {
            dp[h[0]][0] = 1;
        }
        for (int i = 1; i < n; i++) {
            if (h[i] != 0) {
                dp[h[i]][i] += dp[h[i]][i - 1];
                if (h[i] - 1 >= 1) {
                    dp[h[i]][i] += dp[h[i] - 1][i - 1];
                    if (dp[h[i]][i] >= mod) dp[h[i]][i] -= mod;
                }
                if (h[i] + 1 <= x) {
                    dp[h[i]][i] += dp[h[i] + 1][i - 1];
                    if (dp[h[i]][i] >= mod) dp[h[i]][i] -= mod;
                }
            } else {
                for (int j = 1; j <= x; j++) {
                    dp[j][i] += dp[j][i - 1];
                    if (j - 1 >= 1) {
                        dp[j][i] += dp[j - 1][i - 1];
                        if (dp[j][i] >= mod) dp[j][i] -= mod;
                    }
                    if (j + 1 <= x) {
                        dp[j][i] += dp[j + 1][i - 1];
                        if (dp[j][i] >= mod) dp[j][i] -= mod;
                    }
                }
            }
            
        }
        int ans = 0;
        for (int i = 1; i <= x; i++) {
            ans += dp[i][n - 1];
            if (ans >= mod) ans -= mod;
        }
        System.out.println(ans);
    }
}
