#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double exp_dist(double alpha) {
    double x = ((double) rand() / (RAND_MAX));
    return -log(1 - x) / alpha;
}

int main() {
    const int n = 100000;
    const double alpha = 2.0;
    double random[n];

    srand((unsigned) time(NULL));
    for (int i = 0; i < n; ++i) {
        random[i] = exp_dist(alpha);
    }


    FILE *fout = fopen("exp_dist.txt", "w");
    if (fout == NULL) {
        perror("Unable to open file for writing");
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        fprintf(fout, "%f\n", random[i]);
    }

    fclose(fout);

//    printf("Generated 10,000 exponential random numbers and saved to 'exponential_numbers.txt'\n");

    return 0;
}
