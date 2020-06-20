# Halide-sscal-challenge
Small program to test a simple Halide implementation of the sscal function from the BLAS library and comparing it to a C implementation

## How to run
There are two scripts you could run: Bench and runTesting.

### Bench
This one simply run both the Halide implementation (h_sscal) and the C one (c_sscal) several times with different vector sizes while printing the time it took to run for each version.

### runTesting
This one was used to verify if both versions give the same results. Currently it is set at vector length = 15, alpha = 2 and incx = 2, you could easily modify those to test it yourself.
