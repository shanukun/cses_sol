import java.io.*;
import java.util.*;
import java.math.*;

public class Towers {
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
        Reader r = new Reader();

        TreeMap<Integer, Integer> tm = new TreeMap<>();
        int n = r.nextInt();
        while (n-- > 0) {
            int x = r.nextInt();

            if (tm.ceilingKey(x + 1) != null) {
                int y = tm.ceilingKey(x + 1);
                int z = tm.get(y);
                if (z == 1) 
                    tm.remove(y);
                else
                    tm.put(y, z - 1);
                tm.put(x, tm.getOrDefault(x, 0) + 1);
            } else {
                tm.put(x, tm.getOrDefault(x, 0) + 1);
            }
        }
        int cnt = 0;
        for (int y: tm.keySet()) 
            cnt += tm.get(y);
        System.out.println(cnt);

    }
}
