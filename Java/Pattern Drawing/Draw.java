package u0251024;
import java.util.Scanner;

public class Draw {

	public static void main(String[] args) {
		int input = 0;
		Scanner scan = new Scanner(System.in);
		System.out.println("�п�J�@�ӼƦr �G");
		input = scan.nextInt();
		//System.out.println(input);
		
		Triangle TAT = new Triangle();
		TAT.callTriangle(input);
		TAT.showTriangle();
		System.out.println("");
		
		Square OAO = new Square();
		OAO.callSquare(input);
		OAO.showSquare();
		System.out.println("");
		
		Diamond QAQ = new Diamond();
		QAQ.callDiamond(input);
		QAQ.showDiamond();
		System.out.println("");

	}

}
