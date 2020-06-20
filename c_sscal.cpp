#include <stdio.h>

using namespace Halide;


int c_sscal(const int n, const float a, float *V, const int incx){
    for (int i =0;i<n;i=i+incx){
        V[i] = V[i] + a;
    }
    //printing
    //for (int i =0;i<n;i++){
    //    printf("\nV[%d] = %f",i,V[i]);
    //}

    return 0;
}


