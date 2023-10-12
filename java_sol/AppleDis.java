import java.io.*;
import java.util.*; 
import java.math.*; 

public class AppleDis {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] aps = new int[n];
        int sm = 0;

        for (int i = 0; i < n; i++) {
            aps[i] = sc.nextInt();
            sm += aps[i];
        }

        int ans = sm;
        for (int i = 0; i < (1 << n); i++) {
            int cs = 0;
            for (int j = 0; j < n; j++) {
                if (((i >> j) & 1) == 1) {
                    cs += aps[j];
                }
            }
            ans = Math.min(ans, Math.abs((sm - cs) - cs));
        }
        System.out.println(ans);
    }
}
