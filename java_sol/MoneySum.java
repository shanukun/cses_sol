import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class MoneySum {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int sum = 0;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(st.nextToken());
            sum += a[i];
        }

        boolean[] dp = new boolean[sum + 1];
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = sum; j > 0; j--) {
                if (j - a[i] >= 0 && dp[j] != true) {
                    dp[j] |= dp[j - a[i]];
                    if (dp[j]) cnt++;
                }
            }
            if (!dp[a[i]]) {
                dp[a[i]] = true;
                cnt++;
            }
        }
        StringBuilder sb = new StringBuilder("");
        sb.append(cnt + "\n");
        for (int i = 1; i <= sum; i++) {
            if (dp[i])
                sb.append(i + " ");
        }
        System.out.println(sb);
    }
}
