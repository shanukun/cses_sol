import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class BookShop {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int x = Integer.parseInt(st.nextToken());
        int[] h = new int[n];
        int[] s = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) 
            h[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) 
            s[i] = Integer.parseInt(st.nextToken());

        int[][] dp = new int[2][x + 1];

        for (int i = h[0]; i <= x; i++) {
            dp[0][i] = s[0];
        }
        int k = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= x; j++) {
                dp[k][j] = dp[2 - (k + 1)][j];
                if (j - h[i] >= 0) {
                    dp[k][j] = Math.max(dp[k][j], dp[2 - (k + 1)][j - h[i]] + s[i]);
                }
            }
            k = 1 - k;
        }
        System.out.println(dp[1 - (n % 2)][x]);
    }
}
