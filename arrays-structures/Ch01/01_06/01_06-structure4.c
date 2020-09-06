#include <stdio.h>

int main()
{
	/*
	struct some_struct {
		int a;
		int b;
	};
	typedef struct some_struct s_s;

	Shown above is the difference between defining just a struct, and defining a typedef _along_with_ a struct; 
	These can be combined to save space:

	typedef struct some_struct {
		int a;
		int b;
	} s_s;

	Note that the s_s typedef *can* be named some_struct, and in most cases, is. This is because the two exist in separate name spaces.
	Typedef essentially makes an alias of a certain item, and scopes it to the function/typedef namespace

	C has four different name spaces for identifiers:
		* Label names (the goto type).
		* Tags (names of structures, unions and enumerations).
		* Members of structures and unions (these have a separate namespace per structure/union).
		* All other identifiers (function names, object names, type(def) names, enumeration constants, etc).
	*/

	struct pixel {
		int horz;
		int vert;
		char color;
	} 
	top = { 0, 0, 'g' },
	center = { 320, 240, 'r' },
	bottom = { 300, 200, 'b' };

	// You can declare and use multiple struct variables inside the definition of the struct itself (as above)
	// Or you can place them after

	struct pixel top2 = { 0, 0, 'g' };
	struct pixel center2 = { 320, 240, 'r' };
	struct pixel bottom2 = { 300, 200, 'b' };

	printf("The pixel at %d,%d is colored ",
			center.horz,
			center.vert
		  );
	switch(center.color)
	{
		case 'r':
			puts("red");
			break;
		case 'g':
			puts("green");
			break;
		case 'b':
			puts("blue");
			break;
		default:
			puts("Invalid");
	}

	return(0);
}

