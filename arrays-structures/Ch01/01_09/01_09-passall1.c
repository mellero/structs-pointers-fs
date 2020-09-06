#include <stdio.h>

void show_pixel(struct pixel p);

int main()
{
	struct pixel {
		int horz;
		int vert;
		char color;
	} center;

	center.horz = 320;
	center.vert = 240;
	center.color = 'r';

	show_pixel(center);

	return(0);
}

// ** This error is Incomplete Type is not allowed: This is because the struct pixel is _not_ within the scope of show_pixel, as it is local only to main()
// You must define struct pixel globally, outside of main, in order to be able to use it as an argument to show_pixel. As in 01_09-passall2
void show_pixel(struct pixel p)
{
	printf("Pixel found at %d,%d, color = ",
			p.horz,
			p.vert
		  );
	switch(p.color)
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
}

