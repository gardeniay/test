#include<stdio.h>
#include<math.h> 
int main()
{
	float a,b,c;
	scanf(\"%f %f %f\",&a,&b,&c);
	
	if(a<b&&b<c)	
		
    printf(\"%d %d %d\\n\",(int)a,(int)b,(int)c);
    
	if(a<c&&c<b)
	printf(\"%d %d %d\\n\",(int)a,(int)c,(int)b);
	if(b<a&&a<c)
	
	printf(\"%d %d %d\\n\",(int)b,(int)a,(int)c);
	
	if(b<c&&c<a)
	
	printf(\"%d %d %d\\n\",(int)b,(int)c,(int)a);
	
	if(c<b&&b<a)
	
	printf(\"%d %d %d\\n\",(int)c,(int)b,(int)a);
	
	if(c<a&&a<b)
	
	printf(\"%d %d %d\\n\",(int)c,(int)a,(int)b);
	
}
