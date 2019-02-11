package u0251024;

public class Diamond {
	private int num = 0;

	void callDiamond(int TAT) {
		num = TAT;		
	}
	void showDiamond(){
		for (int j=1;j<=num;j++){
	        for ( int i=1;i<=num;i++ ){
	        	if(i+j<=(num+1)/2||Math.abs(i-(num+1))+j<=(num+1)/2||Math.abs(j-(num+1))+i<=(num+1)/2||Math.abs(j-(num+1))+Math.abs(i-(num+1))<=(num+1)/2){	        		
	        		System.out.print("¡@");
	        	}
	        	else{
	        		System.out.print("¡¹");
	        	}
	        	
	        	
	        	
	        }
	        System.out.print("\n");
	    }
	}	
}
