#include <stdlib.h>

#include "max_subarray.h"
#include "dbg.h"

/*
  Calculates maximum sub-array of a given array by brute force.

  Takes 2 arguments
  - int *arr: pointer to an int array
  - int len: size of the int array *arr is pointing to

  Returns: SubArray *sub_array
*/
SubArray *max_subarray_bf(int *arr, int len)
{
     check(arr, "max_subarray_bf() was passed a NULL pointer. Nothing to do.");
     check(len > 0, "max_subarray_bf() was passed a invalid len.");

     SubArray *sub_array = malloc(sizeof (SubArray));
     check_mem(sub_array);
     sub_array->arr = arr;

     int i = 0, j = 0, sum = 0;
     for(i = 0; i < len; i++) {
	  sum = 0;
	  for(j = i; j < len; j++) {
	       sum = sum + arr[j];
	       if(sum > sub_array->sum) {
		    sub_array->sum = sum;
		    sub_array->start = i;
		    sub_array->end = j;
	       }
	  }
     }

     return sub_array;
error:
     if(sub_array) {
	  free(sub_array);
     }
     return NULL;
}

/*
  Calculates maximum sub-array crossing the mid-point of
  a given array by Divide & Conquer.

  Takes 4 arguments
  - int *arr: pointer to an int array
  - int start: index of the int array *arr to start from
  - int mid: index of the mid-point of the int array *arr
  - int end: index of the int array *arr to end at

  Returns: SubArray *sub_array
*/
SubArray *max_crossing_subarray(int *arr, int start, int mid, int end)
{
     check(arr, "max_crossing_subarray() was passed a NULL array.");
     check(start >= 0 && mid >= 0 && end >= 0,
	   "max_crossing_subarray() was passed invalid indexes (%d, %d, %d)",
	   start, mid, end);
     SubArray *sub_array = malloc(sizeof (SubArray));
     check_mem(sub_array);
     sub_array->arr = arr;
     sub_array->sum = 0;

     int i = 0, sum = 0, left_sum = 0, right_sum = 0;
     for(i = mid; i >= start; i--) {
	  sum = sum + arr[i];
	  if(sum > left_sum) {
	       left_sum = sum;
	       sub_array->start = i;
	  }
     }
     for(i = mid + 1; i <= end; i++) {
	  sum = sum + arr[i];
	  if(sum > right_sum) {
	       right_sum = sum;
	       sub_array->end = i;
	  }
     }
     sub_array->sum = left_sum + right_sum;
     return sub_array;
error:
     return NULL;
}

/*
  Calculates maximum sub-array of a given array by Divide & Conquer.

  Takes 3 arguments
  - int *arr: pointer to an int array
  - int start: index of the int array *arr to start from
  - int end: index of the int array *arr to end at

  Returns: SubArray *sub_array
*/
SubArray *max_subarray_dq(int *arr, int start, int end)
{
     check(arr, "max_subarray_dq() was passed a NULL array.");
     check(start >= 0 && end >= 0,
	   "max_subarray_dq() was passed invalid indexes (%d, %d)",
	   start, end);

     if(start == end) {
	  SubArray *sub_array = malloc(sizeof (SubArray));
	  sub_array->arr = arr;
	  sub_array->start = start;
	  sub_array->end = end;
	  sub_array->sum = arr[start];
	  return sub_array;
     }

     int mid = start + ((end - start)
			/ 2);
     SubArray *max_left = max_subarray_dq(arr, start, mid);
     SubArray *max_right = max_subarray_dq(arr, mid + 1, end);
     SubArray *max_crossing = max_crossing_subarray(arr, start, mid, end);

     if(max_left->sum > max_right->sum) {
	  if(max_left->sum > max_crossing->sum) {
	       return max_left;
	  } else {
	       return max_crossing;
	  }
     } else {
	  if(max_right->sum > max_crossing->sum) {
	       return max_right;
	  } else {
	       return max_crossing;
	  }
     }
error:
     return NULL;
}

int main(int argc, char **argv)
{
     int arr[8] = {1, 4, -1, -10, 20, -5, 7, -3};

     SubArray *sub_array = max_subarray_bf(arr, 8);
     check(sub_array, "max_subarray_bf returned NULL.");
     log_info("Using brute force, indices of the maximum subarray"
	      " are: (%d, %d)", sub_array->start, sub_array->end);

     SubArray *sub_array_dq = max_subarray_dq(arr, 0, 7);
     check(sub_array_dq, "max_subarray_dq returned NULL.");
     log_info("Using Divide & Conquer, indices of the maximum subarray"
	      " are: (%d, %d)", sub_array_dq->start, sub_array_dq->end);

     return 0;
error:
     return -1;
}
