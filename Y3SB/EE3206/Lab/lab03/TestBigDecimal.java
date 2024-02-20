/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package lab03;

import java.math.BigDecimal;

/**
 *
 * @author vanting
 */
public class TestBigDecimal {
    
    public static void main(String[] args) {
        long max = Long.MAX_VALUE;
        System.out.println("The maximum value represented by Long type is: " + max);
        System.out.println("Adding one to 'max' results in overflow: " + (max + 1));
        
        BigDecimal big = new BigDecimal(max);
        BigDecimal one = new BigDecimal(1);
        BigDecimal sum = big.add(one);
        System.out.println("Adding one to 'big' does not overflow: " + sum);
        System.out.println("The unscaled value of sum is: " + sum.unscaledValue());
        System.out.println("The scale of sum is: " + sum.scale());
        
        // following done by students
        BigDecimal fact100 = factorial(100);
        System.out.println("100! = " + fact100);
        BigDecimal fact99 = factorial(99);
        System.out.println("99! = " + fact99);
        System.out.println("100!/99! = " + fact100.divide(fact99));
        
    }
    
    public static BigDecimal factorial(long n) {
        BigDecimal factorial = new BigDecimal(n);
        for(long i = n-1; i > 1; i--) {
            factorial = factorial.multiply(new BigDecimal(i));
        }
        return factorial;
    }
    
}
