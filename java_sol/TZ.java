import java.io.*;
import java.util.*; 


class TZ {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();
        int ans = 0;
        long f = 5;
        while (n >= f) {
            ans += n / f;
            f *= 5;
        }
        System.out.println(ans);
    }
}
