import java.util.*;
import java.math.BigInteger;
import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int t = in.nextInt();
        ArrayList<BigInteger> a = new ArrayList<>();
        ArrayList<BigInteger> b = new ArrayList<>();
        TreeSet<BigInteger> st = new TreeSet<>();
        HashMap<BigInteger, Character> mp = new HashMap<>();
        for (int tt = 1; tt <= t; tt++) {
            st.clear();
            mp.clear();
            a.clear();
            b.clear();
            System.out.printf("Case #%d: ", tt);
            BigInteger n = in.nextBigInteger();
            int l = in.nextInt();
            for (int i = 0; i < l; i++) {
                BigInteger temp = in.nextBigInteger();
                a.add(temp);
            }
            int s;
            for (s = 0; s < l - 1; s++)
                if (!a.get(s).equals(a.get(s+1)))
                    break;
            b.add(a.get(s).gcd(a.get(s+1)));
            for (int i = s; i >= 0; i--)
                b.add(a.get(i).divide(b.get(b.size()-1)));
            Collections.reverse(b);
            for (int i = s + 2; i <= l; i++)
                b.add(a.get(i-1).divide(b.get(i-1)));
            st.addAll(b);
            Iterator<BigInteger> it = st.iterator();
            Character c = 'A';
            while (it.hasNext()) {
                BigInteger temp = it.next();
                mp.put(temp, c);
                c++;
            }
            for (int i = 0; i <= l; i++)
                System.out.print(mp.get(b.get(i)));
            System.out.println();
        }
    }
}
