typedef struct SubArray {
     int start;
     int end;
     int *arr;
     int sum;
} SubArray;

SubArray *max_subarray_bf(int *arr, int len);
SubArray *max_crossing_subarray(int *arr, int start, int mid, int end);
SubArray *max_subarray_dq(int *arr, int start, int end);
