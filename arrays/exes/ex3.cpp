#include <iostream>

using namespace std;

void readArr(int arr[], int length);
int getAverage(int *point_arr, int length);
int getFilteredLength(int *point_arr, int length, int average_val);
void filterAboveAndAverage(int *point_arr_source, int length, int average_val, int *target_point_arr);
void printArr(int *pointer_arr, int length);

int main()
{
    const int LENGTH = 100;

    int arr_nums[LENGTH];

    int N_input_lines;
    cin >> N_input_lines;

    readArr(arr_nums, N_input_lines);

    int average = getAverage(arr_nums, N_input_lines);
    const int filtered_length = getFilteredLength(arr_nums, N_input_lines, average);
    int *point_filtered_arr_vals = new int[filtered_length];
    filterAboveAndAverage(arr_nums, N_input_lines, average, point_filtered_arr_vals);

    printArr(point_filtered_arr_vals, filtered_length);

    // removing dangling pointers
    delete point_filtered_arr_vals;
    point_filtered_arr_vals = nullptr;

    return 0;
}

void readArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
}

int getAverage(int *point_arr, int length)
{
    int acc_sum = 0;
    for (int i = 0; i < length; i++)
    {
        int curr_num = *(point_arr + i);
        acc_sum += curr_num;
    }

    int average = acc_sum / length;

    return average;
}

int getFilteredLength(int *point_arr, int length, int average_val)
{
    int filteredLength = 0;
    for (int i = 0; i < length; i++)
    {
        int curr_num = *(point_arr);
        (point_arr)++;

        if (curr_num >= average_val)
        {
            filteredLength++;
        }
    }

    return filteredLength;
}

void filterAboveAndAverage(int *point_arr_source, int length, int average_val, int *target_point_arr)
{
    for (int i = 0; i < length; i++)
    {
        // int curr_num = *(point_arr_source + i);
        int curr_num = (point_arr_source[i]);

        if (curr_num >= average_val)
        {
            *(target_point_arr) = curr_num;
            (target_point_arr)++;
        }
    }
}

void printArr(int *pointer_arr, int length)
{
    int count = 0;
    while (count < length)
    {
        cout << pointer_arr[count] << " ";
        count++;
    }
}