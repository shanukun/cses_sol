import java.io.*;
import java.util.*; 


class BS {
    public static long be(long a, long b, long mod) {
        long ans = 1;
        while (b > 0) {
            if ((b & 1) == 1) {
                ans = (ans * a) % mod;
            }
            a  = (a * a) % mod;
            b >>= 1;
        }
        return ans;
    }
    public static void main(String[] args) {
        long mod = 1000000007;
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();
        System.out.println(be(2, n, mod));
    }
}
