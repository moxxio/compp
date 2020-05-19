import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNext()) {
            List<BigInteger> nums = new ArrayList<>();
            for (int n = scanner.nextInt(); n != -999999; n = scanner.nextInt()) {
                nums.add(BigInteger.valueOf(n));
            }
            BigInteger mxx = nums.get(0);
            for (int i = 0; i < nums.size(); i++) {
                BigInteger can = nums.get(i);
                mxx = mxx.max(can);
                for (int j = i + 1; j < nums.size(); j++) {
                    can = can.multiply(nums.get(j));
                    mxx = mxx.max(can);
                }
            }
            System.out.println(mxx);
        }
    }
}
