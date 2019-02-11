package u0251024hw03;
import java.util.Scanner;
public class myComplexTest {

	public static void main(String[] args) {
		myComplex c1 = new myComplex(1.0f, 1.0f);
		myComplex c2 = new myComplex(2.0f, 3.0f);
		int num = 0;
		Scanner scan = new Scanner(System.in);
		System.out.printf("½Ð¿é¤J¼Æ¦r ¡G\n");	
		num = scan.nextInt();
		System.out.printf("c1 = ");
		c1.List();
		System.out.printf("c2 = ");
		c2.List();
		System.out.printf("c1's conjugate = ");
		c1.Conjugate();
		c1.List();	
		System.out.printf("c2's conjugate = ");
		c2.Conjugate();
		c2.List();	
		System.out.printf("c1+c2 = ");
		c1.Add(c2);
		c1.List();
		System.out.printf("c1-c2 = ");
		c1.Sub(c2);
		c1.List();
		System.out.print("c1*c2 = ");
		c1.Mul(c2);
		c1.List();
		System.out.print("c1/c2 = ");
		c1.Div(c2);
		c1.List();
		System.out.print("(c1)^" + num +" = ");
		c1.Pow(num);
		c1.List();
		System.out.print("(c2)^" + num +" = ");
		c2.Pow(num);
		c2.List();
	}
}
