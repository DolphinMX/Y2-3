package lab03;

public class TestSwap {

    public static void main(String[] args) {
        int num1 = 1;
        int num2 = 2;
        Integer num3 = 3;   // auto-boxing
        Integer num4 = 4;
        Int num5 = new Int(5);
        Int num6 = new Int(6);

        System.out.println("Before invoking the swap1, num1 is " + num1 + " and num2 is " + num2);
        swap1(num1, num2);
        System.out.println("After invoking the swap1, num1 is " + num1 + " and num2 is " + num2);

        System.out.println("\n");
        
        System.out.println("Before invoking the swap2, num3 is " + num3 + " and num4 is " + num4);
        swap2(num3, num4);      
        System.out.println("After invoking the swap2, num3 is " + num3 + " and num4 is " + num4);

        System.out.println("\n");

        System.out.println("Before invoking the swap3, num5 is " + num5 + " and num6 is " + num6);
        swap3(num5, num6);
        System.out.println("After invoking the swap3, num5 is " + num5 + " and num6 is " + num6);
    }

    /**
     * Pass by value, not working.
     */
    public static void swap1(int n1, int n2) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    
    /**
     * Pass by reference but Integer is immutable class, not working.
     */
    public static void swap2(Integer n3, Integer n4) {
        Integer temp = n3;
        n3 = n4;
        n4 = temp;
    }

    /**
     * Pass by reference and modify object's member field.
     */
    public static void swap3(Int n5, Int n6) {
        int temp = n5.value;
        n5.value = n6.value;
        n6.value = temp;
    }

    // wrapper class
    private static class Int {

        public int value;

        Int(int n) {
            value = n;
        }

        @Override
        public String toString() {
            return String.valueOf(value);
        }
    }
}
