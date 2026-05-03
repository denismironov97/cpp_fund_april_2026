#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

void readArray(int arr[], int arr_length);
int getGeneralTerm(int arr_source_length);
void calcAbsOffsetBetweenArrElems(int *point_arr_source, int arr_source_length, long long *point_destination_arr);
void printArr(int arr_source[], int arr_length);
long long getMinIntValue(long long arr_source[], int arr_source_length);

int main()
{
    int N_input_lines;
    cin >> N_input_lines;

    int *pointer_num_arr = new int[N_input_lines];

    readArray(pointer_num_arr, N_input_lines);

    const int abs_offset_length = getGeneralTerm(N_input_lines);
    long long *pointer_abs_offset_values_arr = new long long[abs_offset_length];

    calcAbsOffsetBetweenArrElems(pointer_num_arr, N_input_lines, pointer_abs_offset_values_arr);

    long long closest_min_val = getMinIntValue(pointer_abs_offset_values_arr, abs_offset_length);

    cout << closest_min_val << endl;

    // removing dangling pointers
    delete[] pointer_num_arr;
    pointer_num_arr = nullptr;

    delete[] pointer_abs_offset_values_arr;
    pointer_abs_offset_values_arr = nullptr;

    return 0;
}

void readArray(int arr[], int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        cin >> arr[i];
    }
}

int getGeneralTerm(int arr_source_length)
{
    // general term an=(n*(n-1))/2
    int arr_length = (arr_source_length * (arr_source_length - 1)) / 2;

    return arr_length;
}

void calcAbsOffsetBetweenArrElems(int *point_arr_source, int arr_source_length, long long *point_destination_arr)
{
    for (int i = 0; i < arr_source_length; i++)
    {
        for (int j = (i + 1); j < arr_source_length; j++)
        {
            long long diff = (long long)point_arr_source[i] - (long long)point_arr_source[j];
            long long curr_abs_offset = abs(diff);
            *(point_destination_arr) = curr_abs_offset;

            (point_destination_arr)++;
        }
    }
}

void printArr(int arr_source[], int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        cout << arr_source[i] << " ";
    }

    cout << endl;
}

long long getMinIntValue(long long arr_source[], int arr_source_length)
{
    long long min = LLONG_MAX;
    for (int i = 0; i < arr_source_length; i++)
    {
        long long curr_num = arr_source[i];
        if (curr_num < min)
        {
            min = curr_num;
        }
    }

    return min;
}
