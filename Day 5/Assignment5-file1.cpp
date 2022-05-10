namespace maths
{	
	// Nested inline namespace	
	inline namespace calculator
	{
		 class result
		{
			public:
				int v1, v2;
				
			result()
			{
				this->v1 = 0;
				this->v2 = 0;
			}	
			
			int sum(int v1, int v2) {return v1+v2;}	
			int difference(int v1, int v2) {return v1-v2;}
			int multiplication(int v1, int v2) {return v1*v2;}
    		float division(float v1, float v2) {if(v2!=0) return (v1/v2); else return -1;}
		};
	}

	// Namespace alias
	namespace m = maths;
	// Nested namespace 
	namespace temperature
	{
		float celciusToFarenheit(float celcius)
		{
			m::result r1;
			return (celcius*(r1.division(9,5))+32);	// F = C(9/5)+32
		}
	}
}
