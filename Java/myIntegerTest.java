package hw3;
import java.util.Scanner;
public class myIntegerTest
{
	public static void main(String args[])
	{
		Scanner scanner = new Scanner(System.in);
		int x;
		myInteger integer = new myInteger();
		System.out.print("請輸入第一個整數 : ");
		integer.Set(scanner.nextInt());
		if(integer.IsEven())
			System.out.println(integer.Get() + " 是偶數");
		else
			System.out.println(integer.Get() + " 是奇數");
		if(integer.IsPrime())
			System.out.println(integer.Get() + " 是質數");
		else
			System.out.println(integer.Get() + " 非質數");
		integer.ListFactor();
		integer.DoFactorize();
		System.out.print("請輸入第二個整數 : ");
		x=scanner.nextInt();
		scanner.close();
		System.out.println("GCD(" + integer.Get() + "," + x + ") : " + integer.GCD(x));
		System.out.println("LCM(" + integer.Get() + "," + x + ") : " + integer.LCM(x));
	}// end of main()
}// end of myIntegerTest
