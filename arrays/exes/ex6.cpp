#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

void readArray(int arr[], int arr_length);
int getGeneralTerm(int arr_source_length);
void calcAbsOffsetBetweenArrElems(int *point_arr_source, int arr_source_length, int *point_destination_arr);
void printArr(int arr_source[], int arr_length);
int getMinIntValue(int arr_source[], int arr_source_length);

int main()
{
    int N_input_lines;
    cin >> N_input_lines;

    if (N_input_lines < 2)
    {
        cout << 0 << endl;

        return 0;
    }

    int *pointer_num_arr = new int[N_input_lines];

    readArray(pointer_num_arr, N_input_lines);

    const int abs_offset_length = getGeneralTerm(N_input_lines);
    int *pointer_abs_offset_values_arr = new int[abs_offset_length];

    calcAbsOffsetBetweenArrElems(pointer_num_arr, N_input_lines, pointer_abs_offset_values_arr);

    int closest_min_val = getMinIntValue(pointer_abs_offset_values_arr, abs_offset_length);

    cout << closest_min_val << endl;

    // removing dangling pointers
    delete[] pointer_num_arr;
    pointer_num_arr = nullptr;

    delete[] pointer_abs_offset_values_arr;
    pointer_abs_offset_values_arr = nullptr;

    /*
    //solution 1

    int N_input_lines;
    cin >> N_input_lines;

    if (N_input_lines == 1)
    {
        cout << 0 << endl;

        return 0;
    }

    int *pointer_dyn_arr = new int[N_input_lines];

    readArray(pointer_dyn_arr, N_input_lines);

    int min_diff = INT_MAX;
    for (int curr_index = 0; curr_index < (N_input_lines - 1); curr_index++)
    {
        for (int inner = (curr_index + 1); inner < N_input_lines; inner++)
        {
            int curr_diff = abs(pointer_dyn_arr[curr_index] - pointer_dyn_arr[inner]);

            if (curr_diff < min_diff)
            {
                min_diff = curr_diff;
            }
        }
    }

    cout << min_diff << endl;

    delete[] pointer_dyn_arr;
    pointer_dyn_arr = nullptr;
    */

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

void calcAbsOffsetBetweenArrElems(int *point_arr_source, int arr_source_length, int *point_destination_arr)
{
    for (int i = 0; i < arr_source_length; i++)
    {
        for (int j = (i + 1); j < arr_source_length; j++)
        {
            int curr_abs_offset = abs(point_arr_source[i] - point_arr_source[j]);
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

int getMinIntValue(int arr_source[], int arr_source_length)
{
    int min = INT_MAX;
    for (int i = 0; i < arr_source_length; i++)
    {
        int curr_num = arr_source[i];
        if (curr_num < min)
        {
            min = curr_num;
        }
    }

    return min;
}
