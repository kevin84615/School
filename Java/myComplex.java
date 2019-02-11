package u0251024hw03;

public class myComplex {
	float	real;
	float	imaginary;
	float   ans_real;
	float   ans_imaginary;
	
	public myComplex(){
		real          = 0.0f;
		imaginary     = 0.0f;
		ans_real      = 0.0f;
		ans_imaginary = 0.0f;
	}
	public myComplex(float r, float i){
		real           = r;
		imaginary      = i;
		ans_real       = r;
		ans_imaginary  = i;
	}
	public void  Conjugate(){
		ans_imaginary  = - 1.0f * imaginary;
		ans_real       = real;
	}	
	public void  Add(myComplex c){
		ans_real       = real+c.real;
		ans_imaginary  = imaginary+c.imaginary;
	}
	public void  Sub(myComplex c){
		ans_real       = real-c.real;
		ans_imaginary  = imaginary-c.imaginary;
	}
	public void  Mul(myComplex c){
		ans_real       = (real*c.real)-(imaginary*c.imaginary);
		ans_imaginary  = (imaginary*c.real)+(real*c.imaginary);
	}
	public void  Div(myComplex c){
		ans_real       = ((real*c.real)+(imaginary*c.imaginary))/((c.real*c.real)+(c.imaginary*c.imaginary));
		ans_imaginary  = ((imaginary*c.real)-(real*c.imaginary))/((c.real*c.real)+(c.imaginary*c.imaginary));
	}
	public void  Pow(int order){
		float pow_real=real;
		float pow_imaginary=imaginary;
		ans_real     =real;
		ans_imaginary=imaginary;
		for(int i=1;i<order;i++){
			ans_real     =(real*pow_real)-(imaginary*pow_imaginary);
			ans_imaginary=(imaginary*pow_real)+(real*pow_imaginary);
			pow_real=ans_real;
			pow_imaginary=ans_imaginary;
		}
	}
	public void  List(){
		System.out.printf("%f + %f i\n", ans_real, ans_imaginary);
	}

}
