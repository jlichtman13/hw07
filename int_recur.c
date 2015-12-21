#include <stdio.h>
#include <math.h>

void integral_recur (int nmin, int nmax, double vals[]);
void integral_recur (int nmin, int nmax, double vals[])
{
	vals[100]=0.0036784302814;
	for (int i=nmax-1;i>=nmin;i--)
	{
	vals[i]=(vals[i+1]+1/M_E)/(i+1);

	}
}
