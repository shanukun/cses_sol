import java.io.*;
import java.util.*;
import java.math.*;

public class MovieFest {
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

        List<int[]> lst = new ArrayList<>();
        while (n-- > 0) {
            lst.add(new int[]{fr.nextInt(), fr.nextInt()});
        }
        Collections.sort(lst, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[1] < b[1] ? -1: 1;
            }
        });
        int ans = 1, lo = lst.get(0)[1];
        for (int i = 1; i < lst.size(); i++) {
            if (lo <= lst.get(i)[0]) {
                ans++;
                lo = lst.get(i)[1];
            }
        }
        System.out.println(ans);
    }
}
