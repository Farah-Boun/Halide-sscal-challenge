#include "Halide.h"
#include <stdio.h>
#include "c_sscal.h"
#include "h_sscal.h"
#include "clock.h"

using namespace Halide;


int main(int argc, char **argv) {
    // reading from command line and inits
    int n = atoi(argv[1]);
    int a = atoi(argv[2]);
    int incx = atoi(argv[3]);
    float* vect = new float[n]; 
    //generating vector
    for(int i = 0; i<n;i++){
        vect[i]=i;
    }

    //calling the two sscals while measuring performance
    double t1 = current_time();

    h_sscal(n,a,vect,incx);

    double t2 = current_time();

    c_sscal(n,a,vect,incx);
    
    double t3 = current_time();
    printf("\nFor vector length n =%d\n",n);
    printf("Halide time: %lf\nC time: %lf\n",t2-t1,t3-t2);
    return 0;
}


