#include <stdio.h>
#include <math.h>


void heart() {
    double x, y, z, f;

    for (y=1.5;y>-1.5;y-=0.095) 
    {    
        for (x=-1.5;x<1.5;x+=0.05)
        {
            z = x*x+y*y-1;
            f = z*z*z-x*x*y*y*y;

            if (f <= 0) printf("#");
            else printf(" ");  

        }

        putchar('\n');
    }
}

int main() {

    printf("Tamam\n");
    heart(); 
}
