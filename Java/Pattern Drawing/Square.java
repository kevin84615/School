package u0251024;

public class Square {
    private int num = 0;
	
	void callSquare(int TAT){
		num = TAT;
	}
	void showSquare(){
		for (int i=1;i<=num;i++){
			for (int j=1;j<=num;j++){
				if(j!=1&&j!=num&&i!=1&&i!=num){
	        		System.out.print("¡@"); 
	        	}
	        	else{
	        		System.out.print("¡¹"); 
	        	}
		    }
			System.out.println("");
		}
	}

}
