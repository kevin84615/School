package hw4;

public class MatrixTest
{
		// main method begins execution of Java application
		public static void main( String args[] )
		{

				// test identity	
				System.out.print("[---Test Identity Operation---] \n");
				Matrix3x3 matrixIdentity = new Matrix3x3();
				matrixIdentity.Identity();
				matrixIdentity.Show();

				// test transpose

				// test multiply
		
				// test determinant

				// test inverse
				double[][] inverse={{0.0, 2.0, 2.0}, {1.0, 4.0, 1.0}, {2.0, 8.0, 4.0}};
				Matrix3x3 matrixInverse = new Matrix3x3(inverse);
				matrixInverse.Show();
				if(matrixInverse.Inverse() == true)
				{
						matrixInverse.Show();
						// verify the inverse
						matrixInverse.Multiplication(inverse);
						matrixInverse.Show();
				}
				else
				{
						System.out.print("This matrix has no inverse\n");
				}//End of if-condition


		}// End of main class

}
