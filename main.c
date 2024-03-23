#include<stdio.h>
#include<stdlib.h>
#include"util.h"

int main()
{
    int first_element,seqlen,i;
    printf("Please enter the sequence length: ");
    scanf("%d",&seqlen);
    printf("Please enter the first element: ");
    scanf("%d",&first_element);

    int *loop = malloc(sizeof(int)*(seqlen/2));
    int *histogram = calloc(9,sizeof(int));
    int digit = 0;
    int looplen = seqlen/2;

    check_loop_iterative(generate_sequence,first_element,seqlen,loop,&looplen);

    if(looplen>1)
    {
    printf("Loop: {");
    for (i = 0; i < looplen; i++)     /* Prints loop */
    {
        if(i == looplen-1)
            printf("%d}",loop[i]);
        else
            printf("%d, ",loop[i]);
    }
    }

    hist_of_firstdigits(generate_sequence,first_element,seqlen,histogram,digit);

    printf("\n\n\nHistogram of the sequence : {");
    int j;
    for (j = 0; j < 9; j++)     /* Prints histogram */
    {
        if(j == 8)
            printf("%d}",histogram[j]);
        else
            printf("%d, ",histogram[j]);
    }
    printf("\n");
    return 0;
}
