package u0251024;

public class Triangle {
	private int num = 0;
	
	void callTriangle(int TAT){
		num = TAT;
	}
	void showTriangle(){
		for (int i=0;i<=num;i++){
			for (int j=1;j<=num-i;j++){
				System.out.print("¡¹");
		    }
			System.out.println("");
		}
	}

}
