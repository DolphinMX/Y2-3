/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */

/**
 *
 * @author Max
 */
public class Q1 
{

    public static class check 
    {

        public static void main(String[] args) 
        {
            String text = "tfdc";
            String result = "true";
            int count = 0;
            char[] textChar = text.toCharArray();
            for (int i = 0; i < textChar.length - 1; i++)
            {
                if (count <= 0) 
                {
                    for (int j = 0; j < textChar.length - 1; j++) 
                    {
                        if ((Character.toString(textChar[i]).equals(Character.toString(textChar[j]))) && (i != j)) 
                        {
                            count++;
                        }
                    }
                } 
                else
                {
                    break;
                }
            }
            if (count != 0) 
            {
                result = "false";
            }
            System.out.println("Original String: " + text);
            System.out.println("String has all unique characters: " + result);
        }
    }
}
