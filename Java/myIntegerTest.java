package hw3;
import java.util.Scanner;
public class myIntegerTest
{
	public static void main(String args[])
	{
		Scanner scanner = new Scanner(System.in);
		int x;
		myInteger integer = new myInteger();
		System.out.print("�п�J�Ĥ@�Ӿ�� : ");
		integer.Set(scanner.nextInt());
		if(integer.IsEven())
			System.out.println(integer.Get() + " �O����");
		else
			System.out.println(integer.Get() + " �O�_��");
		if(integer.IsPrime())
			System.out.println(integer.Get() + " �O���");
		else
			System.out.println(integer.Get() + " �D���");
		integer.ListFactor();
		integer.DoFactorize();
		System.out.print("�п�J�ĤG�Ӿ�� : ");
		x=scanner.nextInt();
		scanner.close();
		System.out.println("GCD(" + integer.Get() + "," + x + ") : " + integer.GCD(x));
		System.out.println("LCM(" + integer.Get() + "," + x + ") : " + integer.LCM(x));
	}// end of main()
}// end of myIntegerTest
