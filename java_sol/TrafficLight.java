import java.io.*;
import java.util.*;
import java.math.*;

public class TrafficLight {
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferParter, bytesRead;

        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferParter = bytesRead = 0;
        }
        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferParter = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException
        {
            if (bufferParter == bytesRead)
                fillBuffer();
            return buffer[bufferParter++];
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

        int x = r.nextInt();
        int n = r.nextInt();
        TreeSet<Integer> ts = new TreeSet<>();
        ts.add(0);
        ts.add(x);
        TreeMap<Integer, Integer> tm = new TreeMap<>();
        HashSet<Part> hs = new HashSet<>();
        hs.add(new Part(0, x));
        tm.put(x, 1);

        StringBuilder sb = new StringBuilder("");
        while (n-- > 0) {
            int y = r.nextInt();
            int y2 = ts.ceiling(y);
            int y1 = ts.floor(y);
            ts.add(y);
            int l = y2 - y1;

            Part p = new Part(y1, y2);
            if (hs.contains(p)) {
                hs.remove(p);
                if (tm.containsKey(l)) {
                    int z = tm.get(l);
                    if (z == 1)
                        tm.remove(l);
                    else
                        tm.put(l, z - 1);
                }
            }
            hs.add(new Part(y1, y));
            hs.add(new Part(y, y2));
            tm.put(y - y1, tm.getOrDefault(y - y1, 0) + 1);
            tm.put(y2 - y, tm.getOrDefault(y2 - y, 0) + 1);
            
            sb.append(tm.lastKey() + " ");
        }
        System.out.println(sb);
    }
}

class Part {
    int x1;
    int x2;
    Part(int x1, int x2) {
        this.x1 = x1;
        this.x2 = x2;
    }
    @Override
    public int hashCode() {
        return Objects.hash(x1, x2);
    }
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        Part p = (Part) o;
        return this.x1 == p.x1 && this.x2 == p.x2;
    }
}
