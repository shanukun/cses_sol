import java.io.*;
import java.util.*;
 
 
public class DistNum {
    static class FastR {
        BufferedReader br;
        StringTokenizer st;
        public FastR() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch(IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt() {
            return Integer.parseInt(next());
        }
        void print(int v) {
            System.out.println(v);
        }
    }
    public static void main(String[] args) {
        FastR fr = new FastR();
        HashSet<Integer> hs = new HashSet<>();
        int n = fr.nextInt();
        while (n-- > 0) {
            int x = fr.nextInt();
            hs.add(x);
        }
        fr.print(hs.size());
    }
}
