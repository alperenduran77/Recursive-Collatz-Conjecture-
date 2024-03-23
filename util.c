#include<stdio.h>
#include<stdlib.h>
#include"util.h"



void generate_sequence(int xs, int currentlen,int seqlen, int *seq)
{
    int temp;
    if(currentlen<seqlen)
    seq[currentlen] = xs;

    if(seqlen > currentlen && xs%2 == 0) /* even number */
    {
    temp=xs/2;
    generate_sequence(temp,currentlen+1,seqlen,seq);  /* recursive call */
     }
    else if(seqlen > currentlen && xs%2 == 1) /* odd number */
    {
    temp=(3*xs)+1;
    generate_sequence(temp,currentlen+1,seqlen,seq); /* recursive call     */
    }


}

void check_loop_iterative(void (*f)(int, int ,int, int*), int xs, int seqlen, int *loop, int *looplen)
{
    int *seq_array = malloc(sizeof(int)*seqlen);
    f(xs,0,seqlen,seq_array); /* calls generate_sequence */

    int i=0;

    if (*looplen == seqlen/2)
    {
        while ( i < seqlen)
        {
            if(i == 0)
            {
            printf("Sequence: {");
            }
            else if(i == seqlen-1)
            {
            printf("%d}\n",seq_array[i]);
            }
            else
            {
                 printf("%d, ",seq_array[i]);
            }
            i++;
        }

    }

    int ls, le;
    if (*looplen > 1)  /* searches for loop until find one*/
        {
        printf("\nChecking if there is a loop of length %d...",*looplen);

        if(*looplen == 2)
            {
                 printf("\nNo loop found.\n");
            }

        int result = has_loop(seq_array,seqlen, *looplen,&ls,&le);
        if (result == 0)
            {
            (*looplen)--;
            check_loop_iterative(f,xs,seqlen,loop,looplen); /* recursive call */
            }
        else if (result == 1)
            {
            printf("\n\nLoop detected with a length of %d.\n",*looplen);
            printf("The indexes of the loop's first occurance: %d(first digit), %d(last digit)\n",ls,le);
            }
         }
      else
        {
        *looplen=0;

        }

}

int has_loop(int *arr, int n, int looplen, int *ls, int *le)
{
    int counter = 0,i,j;
    for(i=0;i<n;i++)
    {
        j=i;
        while(j<looplen+i)
        {
          {
          if(arr[j] == arr[looplen+j])
                counter++;
          }
          j++;
         }
          if(counter == looplen)
          {
            *le = j - 1;
            *ls = j - counter  ;
            return 1;
          }
        counter = 0;
    }
    return 0;
}

int find_digit(int num)  /* finds first digit of the number */
{
    int j=0,i=1,num1;
    num1 = num;
    while(num1)
        {
        num1/=10;
        j++;
        }

    while(i<j)
    {
        num = num/10;
        i++;
    }
    return num;
}

void hist_of_firstdigits(void (*f)(int, int ,int, int*), int xs, int seqlen, int *h, int digit)
{
    int *loop_arr = malloc(sizeof(int)*seqlen);
    f(xs,0,seqlen, loop_arr);
    int first;

    if (digit != seqlen)
    {
    first = find_digit(loop_arr[digit]);
    h[first-1] ++;
    digit ++;
    hist_of_firstdigits(f,xs,seqlen,h,digit); /* recursive call */
    }

}
