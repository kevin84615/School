package hw2;
import java.util.Scanner;
public class hw2 {
	
	public static void main ( String args[])
	{
		int num1=0;
        Scanner scanner = new Scanner(System.in);
        
        while (num1 <=1)
        {
            System.out.println("請輸入一個大於1的數字：");
        	num1 = scanner.nextInt();
        }//end input
        System.out.println("Triangle Pattern：");
        for (int i=num1;i>0;i--)
        {
        	for (int j=i;j>0;j--)
        		System.out.print("*");
        	System.out.println();
        }//end of printing Triangle
        System.out.println("Square Pattern：");
        for (int i=num1;i>0;i--)
        {
        	System.out.print("*");
        	for (int j = 0; j<num1-2;j++)
        		if (i==1 || i==num1)
        			System.out.print("*");
        		else
        			System.out.print(" ");
            System.out.print("*");
    		System.out.println();
        }//end of printing Square
        
        System.out.println("Diamond Pattern：");
        if (num1 % 2 == 0)
        	System.out.println("n is an even number!!");
        else
        {
        	for (int i =0;i<=num1/2;i++)
        	{
        		for (int j=0;j<num1/2-i;j++)
        			System.out.print(" ");
        		for (int j=1;j<2*(i+1);j++)
        			System.out.print("*");
        		System.out.println();
        	}
        	for (int i =num1/2-1;i>=0;i--)
        	{
        		for (int j=0;j<num1/2-i;j++)
        			System.out.print(" ");
        		for (int j=1;j<2*(i+1);j++)
        			System.out.print("*");
        		System.out.println();
        	}
        }//end of printing Diamond
        
        System.out.print("Process end!");
	}
}
