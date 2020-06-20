#include "Halide.h"
#include <stdio.h>

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
	
        //f.trace_stores();
	f.realize(n);
	
	return 0;
}



