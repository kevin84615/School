package hw3;

public class myInteger
{
	private int iInteger;
	
	public myInteger()
	{
		iInteger = 0;
	}//end of myInteger()
	
	public int Get()
	{
		return iInteger;
	}// end of Get()

	public void Set(int iInteger)
	{
		this.iInteger = iInteger;
	}// end of Set()
	
	public boolean IsEven()
	// check if it is a even integer
	{
		if (iInteger%2==0)
			return true;
		else
			return false;	
	}// end of IsEven()
	
	public boolean IsPrime()
	// check if it is a prime integer
	{
		for (int i=2 ; i*i<=iInteger ; i++)
			if (iInteger % i ==0)
				return false;
		return true;
	}// end of IsPrime()
	
	public void ListFactor()
	// list all factors
	{
		System.out.print(iInteger + "'s factors : 1, ");
		for (int i=2;i<iInteger;i++)
			if (iInteger % i==0)
				System.out.print(i+", ");
		System.out.println(iInteger);
	}// end of ListFactor()
	
	public int GCD(int iInt)
	// find greatest common divider
	{
		int t1=iInteger,t2=iInt;
		while (true)
		{
			if (t1>t2)
			{
				t1=t1%t2;
				if (t1==0)
					return t2;
			}
			else
			{
				t2=t2%t1;
				if (t2==0)
					return t1;
			}
		}
	}// end of GCD()
	
	public int LCM(int iInt)
	// find lowest common multiple
	{
		return iInteger*iInt/this.GCD(iInt);
	}// end of LCM()
	
	public void DoFactorize()
	// perform factorization
	{
		int tmp = iInteger;
		System.out.print(iInteger + "'s factorziation : ");
		for (int i = 2 ; i<=iInteger;i++)
			while (tmp % i ==0 )
			{
				if (i==tmp)
					System.out.println(i);
				else
					System.out.print(i+ " * ");
				tmp /= i;
			}	
	}//end of DoFactorize()
}// End of class Pattern
