import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class RectCut {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());

        int[][] dp = new int[a + 1][b + 1];
        for (int i = 2; i <= a; i++) 
            dp[i][1] = dp[i - 1][1] + 1;
        for (int i = 2; i <= b; i++) 
            dp[1][i] = dp[1][i - 1] + 1;
        for (int i = 2; i <= a; i++) {
            for (int j = 2; j <= b; j++) {
                if (i == j) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = Integer.MAX_VALUE;
                for (int k = 1; k < i; k++) {
                    dp[i][j] = Math.min(dp[i][j], 1 + dp[i - k][j] + dp[k][j]);
                }
                for (int k = 1; k < j; k++) {
                    dp[i][j] = Math.min(dp[i][j], 1 + dp[i][j - k] + dp[i][k]);
                }
            }
        }

        System.out.println(dp[a][b]);
    }
}
