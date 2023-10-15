import java.io.*;
import java.util.*;
import java.math.*;

public class MissingCoin {
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

        List<Integer> lst = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int x = fr.nextInt();
            lst.add(x);
        }
        Collections.sort(lst);
        long ans = 0, rv = 1;
        for (int i = 0; i < lst.size(); i++) {
            if (lst.get(i) <= rv) {
                ans += lst.get(i);
                rv = ans + 1;
            } else {
                break;
            }
        }
        System.out.println(ans + 1);

    }
}
