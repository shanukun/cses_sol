import java.io.*;
import java.util.*;
import java.math.*;

public class CollectingNum2 {
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do
            {
                ret = ret * 10 + c - '0';
            }  while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }
    }
    public static void main(String[] args) throws IOException {
        Reader fr = new Reader();
        int n = fr.nextInt();
        int m = fr.nextInt();

        int[] v = new int[n];
        List<int[]> lst = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = fr.nextInt();
            v[i] = x;
            lst.add(new int[]{x, i});
        }
        Collections.sort(lst, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[0] < b[0] ? -1: 1;
            }
        });
        long cnt = 1;
        for (int i = 1; i < lst.size(); i++)
            if (lst.get(i)[1] < lst.get(i - 1)[1]) cnt++;

        TreeMap<Integer, Integer> hm = new TreeMap<>();
        StringBuffer sb = new StringBuffer("");
        while (m-- > 0) {
            int x = fr.nextInt() - 1;
            int y = fr.nextInt() - 1;

            // values at those index
            int xv = v[x];
            int yv = v[y];

            if (xv - 1 >= 1)
                hm.put(xv - 1, xv);
            if (xv + 1 <= n)
                hm.put(xv, xv + 1);
            if (yv - 1 >= 1)
                hm.put(yv - 1, yv);
            if (yv + 1 <= n)
                hm.put(yv, yv + 1);

            // remove all inversion
            for (Map.Entry<Integer, Integer> p: hm.entrySet()) {
                int i1 = p.getKey() - 1;
                int i2 = p.getValue() - 1;

                int i1i = lst.get(i1)[1];
                int i2i = lst.get(i2)[1];

                if (i1i > i2i) {
                    cnt--;
                }
            }
            lst.set(xv - 1, new int[]{xv, y});
            lst.set(yv - 1, new int[]{yv, x});

            for (Map.Entry<Integer, Integer> p: hm.entrySet()) {
                int i1 = p.getKey() - 1;
                int i2 = p.getValue() - 1;

                int i1i = lst.get(i1)[1];
                int i2i = lst.get(i2)[1];

                if (i1i > i2i) {
                    cnt++;
                }
            }

            v[x] = v[y] + v[x] - (v[y] = v[x]);
            sb.append(cnt + "\n");
            hm.clear();
        }
        System.out.print(sb);
        fr.close();

    }
}
