import java.io.*;
import java.util.*;
import java.math.*;

public class RestCust {
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
            lst.add(new int[]{fr.nextInt(), 1});
            lst.add(new int[]{fr.nextInt(), -1});
        }
        Collections.sort(lst, new Comparator<int[]>() {
            public int compare(int[] a, int[] b) {
                return a[0] < b[0] ? -1: 1;
            }
        });
        int ans = 0, cs = 0;
        for (int i = 0; i < lst.size(); i++) {
            cs += lst.get(i)[1];
            ans = Math.max(ans, cs);
        }
        System.out.println(ans);
    }
}
