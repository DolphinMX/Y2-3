/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Max
 */
import java.util.Scanner;

public class Shape {
    public static void main(String[] args) {
       
        Scanner read = new Scanner(System.in);
         double radius = read.nextDouble();
        // Create a Circle object with radius 5
        Circle circle = new Circle(radius);

        // Calculate and print the perimeter of the circle
        System.out.println("Perimeter of the circle: " + circle.getPerimeter());

        // Calculate and print the area of the circle
        System.out.println("Area of the circle: " + circle.getArea());
    }
}

class Circle {
    private double radius;

    // Constructor
    public Circle(double radius) {
        this.radius = radius;
    }

    // Method to calculate the perimeter of a circle
    public double getPerimeter() {
        return 2 * Math.PI * radius;
    }

    // Method to calculate the area of a circle
    public double getArea() {
        return Math.PI * radius * radius;
    }
}
