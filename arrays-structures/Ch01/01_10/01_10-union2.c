#include <stdio.h>

int main()
{
	// A union is similar to a struct, but *all* members within the union *share* its storage space
	// Unions are dangerous/unsafe. The compiler does not check to enure proper data type is used.
	// Modifying one member, can modify any other members. 
	union storage {
		char a;
		int b;
	} reg;

	reg.a = 'A';
	printf("reg.a stores %c\n",reg.a);

	reg.b = 1346;
	printf("reg.b stores %d\n",reg.b);
	printf("reg.a stores %c\n",reg.a);

	return(0);
}

