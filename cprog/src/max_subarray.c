#include <stdlib.h>

#include "dbg.h"

/*
  Calculates maximum sub-array of a given array by brute force.

  Takes 2 arguments
  - int *arr: pointer to an int array
  - int len: size of the int array *arr is pointing to

  Returns: int max[2]
  - max[0] is start of the maximum sub-array in *arr
  - max[1] is end of the maximum sub-array in *arr
*/
int *max_subarray_bf(int *arr, int len)
{
     check(arr, "max_subarray_bf() was passed a NULL pointer. Nothing to do.");
     check(len > 0, "max_subarray_bf() was passed a invalid len.");
     
     int left_max = 0, right_max = 0, max_sum = 0;
     int *max = malloc(2 * (sizeof (int)));
     check_mem(max);

     int i = 0, j = 0, sum = 0;
     for(i = 0; i < len; i++) {
	  sum = 0;
	  for(j = i; j < len; j++) {
	       sum = sum + arr[j];
	       if(sum > max_sum) {
		    max_sum = sum;
		    left_max = i;
		    right_max = j;
	       }
	  }
     }

     max[0] = left_max;
     max[1] = right_max;

     return max;
error:
     if(max) {
	  free(max);
     }
     return NULL;
}


int main(int argc, char **argv)
{
     int arr[8] = {1, 4, -1, -10, 20, -5, 7, -3};

     int *max = max_subarray_bf(arr, 8);
     check(max, "max_subarray_bf returned NULL.");

     log_info("Indices of the maximum subarray are: (%d, %d)", max[0], max[1]);
error:
     return -1;
}
