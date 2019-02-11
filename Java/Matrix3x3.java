package hw4;
public class Matrix3x3
{
		// field
		double[][] 		matrix = new double[3][3];
	
		//constructor
		public Matrix3x3()
		{
				// initialize all the elements to zero
				for(int r=0; r < 3; r++)
						for(int c=0; c < 3; c++)
								matrix[r][c] = 0.0;
		}// End of Matrix3x3
		
		public Matrix3x3(double[][] m)
		{
		    	for(int r=0; r < 3; r++)
		    	{
		    			for(int c=0; c < 3; c++)
		    			{
		    					if(r==c) matrix[r][c] = m[r][c];
		    					else matrix[r][c] =m[r][c];
		    			}// End of for-loop
		    	}
		}// End of Matrix3x3
		
		//operations		
		public void Identity()
		{
				// set elements at diagonal to 1.0
				for(int r=0; r < 3; r++)
				{
						for(int c=0; c < 3; c++)
						{
								if(r==c) matrix[r][c] = 1.0;
								else matrix[r][c] = 0.0;
						}// End of for-loop
				}// End of for-loop
		} // End of Identity
		
	 	public void Multiplication(double[][] m)
	 	{
	 			double[][] tmp=new double[3][3];
	 			for ( int r=0; r<3; r++)
	 	 		{
	 	 				for (int c=0 ; c<3;c++)
	 	 				{
	 	 						tmp[r][c]=matrix[r][0]*m[0][c]+matrix[r][1]*m[1][c]+matrix[r][2]*m[2][c];
	 	 				}
	 	 		}
	 	 		matrix=tmp;
	 	} // End of Multiplication
	 	
		public boolean Inverse()
		{
				if (det(matrix)==0.0)
						return false;
				double[][] tmp = new double[3][3];
				for(int r=0; r<3; r++)
				{
					   for(int c=0; c<3; c++)
					   {
						   		tmp[r][c] = matrix[r][c];
					   }
				} //複製原矩陣到tmp
				
				double[][] unit = {{1.0,0.0,0.0},{0.0,1.0,0.0},{0.0,0.0,1.0}};
				//單位矩陣
				
				for(int i=0; i<3; i++)
				{
				    	for(int j=i+1; j<3; j++) 
				    	{
				    			if(Math.abs(tmp[j][i]) > Math.abs(tmp[i][i])) 
				    			{
				    					double tmp2[] = new double[3];
				    					tmp2=tmp[i]; tmp[i]=tmp[j]; tmp[j]=tmp2; // 互換矩陣兩行
				    					tmp2=unit[i]; unit[i]=unit[j]; unit[j]=tmp2; // 單位矩陣做同樣運算
				    			}
				    	}

				    	// 消去
				    	for(int j=0; j<3; j++)
				    	{
				    			if(j != i)
				    			{   				
				    					double temp = tmp[j][i]/tmp[i][i];

				    					for(int k=i+1; k<3; k++) 
				    							tmp[j][k] -= (tmp[i][k] * temp);				    					
				    					for(int k=0; k<3; k++)
				    					{ 
				    							unit[j][k] -= (unit[i][k] * temp);
				    					}
				    			}
				    	}
				}
				for(int i=0; i<3; i++)
				{
				    	for(int j=0; j<3; j++)
				    	{
				    			unit[i][j] /= tmp[i][i];
				    	}
				}
				matrix=unit;
				return true;
		}// End of Inverse
		
		public void	Show()
		{
		    	for(int r=0;r<3;r++)
		    	{
		    			for(int c=0;c<3;c++)
		    					//System.out.print(matrix[r][c]+"\t\t");
		    					System.out.printf("%f\t", matrix[r][c]);
		    			System.out.println();
		    	}
		    	System.out.println();
		}// End of Matrix3x3::Show
		
		double det(double[][] matrix)
		{
			return matrix[0][0]*matrix[1][1]*matrix[2][2]+matrix[1][0]*matrix[2][1]*matrix[0][2]+matrix[2][0]*matrix[0][1]*matrix[1][2]-
					matrix[0][2]*matrix[1][1]*matrix[2][0]-matrix[0][0]*matrix[1][2]*matrix[2][1]-matrix[2][2]*matrix[1][0]*matrix[0][1];
		}// End of det
}
