#include <stdio.h>
#include <math.h>
#include "int_recur.c"
#include "int_gsl.c"
#define NMAX 100
#include "timer.c"
#include "timer.h"
#include "adjust.c"
int main (void)
{
	double vals1[NMAX+1],vals2[NMAX+1];
	integral_recur (0,NMAX,vals1);
	integral_gen (0,NMAX,vals2);
	for (int i=0;i<=NMAX;i++)
	{
		printf("--------------------------------------------------------------\n");
		printf(" n Value       Recursion                        General\n");
		printf(" %d            %f                         %f     \n",i,vals1[i],vals2[i]);
	}
	int count=1000;	
	double time,time_recur,tmax=2.,tmin=1.;
	printf("Time for recursion integral\n");
	printf("--------------------------------------------------------------\n");
	do
	{
		timer_start ();
		for (int i=0; i<count;i++)
		{
			integral_recur (0,NMAX,vals1);
		}
		time= timer_stop ();
		time_recur=time/count;
		printf ("%10.2f usec     %10.6f sec     %10d\n",time_recur*1.e6,time,count);
		count = adjust_rep_count (count,time,tmin,tmax);
	}
	while ((time>tmax) || (time< tmin));
	double time1,time_gsl;
	printf("Time for general integral\n");
	printf("--------------------------------------------------------------\n");
	do
        {
                timer_start ();
                for (int j=0; j<count;j++)
                {
                        integral_gen (0,NMAX,vals2);
                }
                time1= timer_stop ();
                time_gsl=time1/count;
                printf ("%10.2f usec     %10.6f sec     %10d\n",time_recur*1.e6,time,count);
                count = adjust_rep_count (count,time1,tmin,tmax);
        }
        while ((time1>tmax) || (time1< tmin));
	printf ( " Time Ratio %10.2f \n",time_gsl/time_recur);
	return 0;







}

