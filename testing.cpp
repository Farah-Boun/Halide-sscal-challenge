#include "Halide.h"
#include <stdio.h>
#include "clock.h"

using namespace Halide;


int h_sscal(const int n, const float a, float *V, const int incx){
	//inits
	Var x("x"), y("y");
	Func f("f"),g("g");
        Halide::Buffer<float> buf(V, n);
	//had to use g because I couldn't figure out how you'd do a condition on a coordinate,
	//since they're not normal types
	g(x) = x;
	f(x) = select(g(x) % incx == 0, buf(x) + a, buf(x)); 
	
        f.trace_stores();
	f.realize(n);
	
	return 0;
}


int c_sscal(const int n, const float a, float *V, const int incx){
    for (int i =0;i<n;i=i+incx){
        V[i] = V[i] + a;
    }
    //printing
    for (int i =0;i<n;i++){
        printf("\nV[%d] = %f",i,V[i]);
    }

    return 0;
}


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


