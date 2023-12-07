import java.io.*;
import java.util.*;

public class RangeCheck {
    static class Reader {
        BufferedReader br;
        StringTokenizer st;
        public FastReader() {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
        }
        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

    }

    public static void main(String[] args) throws IOException {
        Reader r = new Reader();
        int n = r.nextInt();

        int[] ans1 = new int[n];
        int[] ans2 = new int[n];
        List<Range> l1 = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            long x = r.nextLong();
            long y = r.nextLong();
            l1.add(new Range(x, y, i));
        }
        Collections.sort(l1, new RC());

        TreeMap<Long, Integer> tm = new TreeMap<>();
        for (int i = n - 1; i >= 0; i--) {
            Range r1 = l1.get(i);
            if (tm.floorKey(r1.x) != null) {
                long z = tm.floorKey(r1.x);
                ans1[tm.get(z)] = 1;
                ans2[r1.i] = 1;
            }
            tm.put(r1.x, r1.i);
        }
        tm.clear();
        for (int i = 0; i < n; i++) {
            Range r1 = l1.get(i);
            if (tm.ceilingKey(r1.x) != null) {
                long z = tm.ceilingKey(r1.x);
                ans1[r1.i] = 1;
                ans2[tm.get(z)] = 1;
            }
            tm.put(r1.x, r1.i);
        }

        StringBuilder sb = new StringBuilder("");
        for (int i : ans1)
            sb.append(i + " ");
        sb.append("\n");
        for (int i : ans2)
            sb.append(i + " ");
        System.out.println(sb);
    }
}

class Range {
    long x, y;
    int i;

    public Range(long x, long y, int i) {
        this.x = x;
        this.y = y;
        this.i = i;
    }
}

class RC implements Comparator<Range> {
    @Override
    public int compare(Range r1, Range r2) {
        if (r1.y < r2.y) {
            return -1;
        } else if (r1.y == r2.y) {
            if (r1.x > r2.x) return -1;
            else if (r1.x < r2.x) return 1;
            else return 0;
        } else {
            return 1;
        }
    }
}
