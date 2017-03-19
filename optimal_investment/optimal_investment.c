#include <stdlib.h>
#include <stdio.h>

double **zip(unsigned *arr1, double *arr2, unsigned length)
{
    double **ret = (double **) calloc(length, sizeof(double*));
    for(unsigned i = 0; i<length; i++)
    {
        ret[i] = (double *) calloc(2, sizeof(double));
        ret[i][0] = arr1[i];
        ret[i][1] = arr2[i];
    }
    return ret;
}

/**
* Optimal investment strategy at the end of 10 years with d dollars, n number
* of investments, r_i,j return rates in each year and a fee of f1 if you
* decide to leave your money in the same set of investments or a fee of f2 if
* you decide to switch your money to a different set of investments.
*/
double **optimal_investment(double d, unsigned n, double r[][10], double f1, double f2) {
  // I[i] tells which investment should be made in year i
  unsigned *I = (unsigned*) calloc( 11, sizeof(unsigned) );
  // R[i] gives the total return on the investment in years i through 10
  double *R = (double*) calloc( 11, sizeof(double) );

  // for each year
  for (int k = 9; k >= 0; k--) {
    unsigned q = 0;

    // check if there are better investment possibilities
    for (unsigned i = 0; i < n; i++) if (r[i][k] > r[q][k]) q = i;

    //  decide if stay or switch investment
    double stay_rev = d * r[I[k + 1]][k] - f1;
    double switch_rev = d * r[q][k] - f2;
    if (stay_rev > switch_rev) {
      R[k] = R[k + 1] + stay_rev;
      I[k] = I[k + 1];
    } else {
      R[k] = R[k + 1] + switch_rev;
      I[k] = q;
    }

  }
  return zip(I, R, 10);
}

int main(int argc, char const *argv[]) {
  double r[2][10] = {{2.1, 2.5, 2.7, 1.2, 0.7, 1.8, 1.2, 3.4, 2.1, 1.0},
                      1.2, 2.6, 2.4, 2.7, 1.1, 0.9, 1.5, 2.0, 3.0, 1.2};

  unsigned d = 1, n = 2, f1 = 4, f2 = 100;

  double ** result = optimal_investment(d, n, r, f1, f2);

  for (int i = 0; i < 10; i++) {
    printf("year: %d, investment: %f, revenue: %f\n", abs(i-10), result[i][0]+1, result[i][1]);
  }

  return 0;
}
