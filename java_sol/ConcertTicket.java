import java.io.*;
import java.util.*;

public class ConcertTicket {
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

        TreeMap<Integer, Integer> tm = new TreeMap<>();
        while (n-- > 0) {
            int x = fr.nextInt();
            tm.put(x, tm.getOrDefault(x, 0) + 1);
        }

        StringBuilder sb = new StringBuilder("");
        while (m-- > 0) {
            int x = fr.nextInt();
            if (tm.floorKey(x) != null) {
                int key = tm.floorKey(x);
                int val = tm.get(key);
                sb.append(key + "\n");
                
                if (val == 1) tm.remove(key);
                else tm.put(key, val - 1);
            } else {
                sb.append("-1\n");
            }
        }
        System.out.print(sb);
    }
}
