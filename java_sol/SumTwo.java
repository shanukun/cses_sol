import java.io.*;
import java.util.*;
import java.math.*;

public class SumTwo {
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
        int x = fr.nextInt();

        HashMap<Integer, Integer> hm = new HashMap<>();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = fr.nextInt();
            hm.put(a[i], i);
        }
        int i1 = -1, i2 = -1;
        for (int i = 0; i < n; i++) {
            if (hm.containsKey(x - a[i])) {
                if (hm.get(x - a[i]) != i) {
                    i1 = i + 1;
                    i2 = hm.get(x - a[i]) + 1;
                    break;
                }
            }
        }
        if (i1 < 0)
            System.out.println("IMPOSSIBLE");
        else
            System.out.println(i1 + " " + i2);
    }
}
