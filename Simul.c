#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double funUniformSingle()
{
    double randUni;
    randUni = (double)rand() / (double)((unsigned)RAND_MAX + 1); //generate random variables on (0,1)
    return randUni;
}

int funPoissonSingle(double lambda)
{
    double exp_lambda = exp(-lambda); //constant for terminating loop
    double randUni; //uniform variable
    double prodUni; //product of uniform variables
    int randPoisson; //Poisson variable

//initialize variables
    randPoisson = -1;
    prodUni = 1;
    do
    {
        randUni = funUniformSingle(); //generate uniform variable
        prodUni = prodUni * randUni; //update product
        randPoisson++; //increase Poisson variable

    }
    while (prodUni > exp_lambda);
    return randPoisson;
}

int main()
{
    int g,n,i,interarrival[100],arrival[100], random[1000];

    arrival[0]=0, random[0] = 0;

    for(i=1; i<19; i++)
    {
        random[i]= funPoissonSingle(8.5);
        arrival[i] = arrival[i-1] + random[i];
    }
    printf("Customer\tInterarrival Time\t Arrival Time\n");
    for(int c=1; c<=10; c++)
    {
        printf(" %d\t\t\t%d \t\t\t%d\t\n", c, random[c-1], arrival[c-1]);
    }
}
