import java.io.*;
import java.util.*; 


public class TwoSet {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();

        long a1 = n * (n + 1) / 2;
        StringBuilder sb1 = new StringBuilder("");
        StringBuilder sb2 = new StringBuilder("");
        if (a1 % 2 == 0) {
            System.out.println("YES");
            long a2 = a1 / 2;
            int cnt = 0;
            for (long i = n; i >= 1; i--) {
                if (i <= a2) {
                    sb1.append(i + " ");
                    a2 -= i;
                    cnt++;
                } else {
                    sb2.append(i + " ");
                }
            }
            System.out.println(cnt);
            System.out.println(sb1);
            System.out.println(n - cnt);
            System.out.println(sb2);

        } else {
            System.out.println("NO");
        }
    }
}
