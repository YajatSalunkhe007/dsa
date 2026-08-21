	#include <stdio.h>
int main()
{
    int bt[10], rem[10];
    int n, tq;
    int i, time = 0;
    int completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter burst time of each process:\n");
    for(i = 0; i < n; i++)
    {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }
    printf("Enter time quantum: ");
    scanf("%d", &tq);
    printf("\nExecution Order:\n");
    while(completed < n)
    {
        for(i = 0; i < n; i++)
        {
            if(rem[i] > 0)
            {
                printf("P%d ", i + 1);
                if(rem[i] > tq)
                {
                    time = time + tq;
                    rem[i] = rem[i] - tq;
                }
                else
                {
                    time = time + rem[i];
                    rem[i] = 0;
                    completed++;
                }
            }
        }
    }
    printf("\n\nTotal CPU Time = %d", time);
    return 0;
}
