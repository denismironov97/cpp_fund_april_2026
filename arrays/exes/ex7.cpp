#include <iostream>

using namespace std;

void readArr(int arr[], const int &length);
void printArr(const int arr[], const int length);
void rotateArr(int array[], const int length);
void performSimpleRotation(int arr_nums[], const int &length);
void performLeftShift(int arr[], const int &length);

int main()
{
    const int LENGTH = 100;

    int N_size;
    cin >> N_size;

    /*
    int *point_dyn_arr = new int[N_size];
    readArr(point_dyn_arr, N_size);

    delete[] point_dyn_arr;
    point_dyn_arr = nullptr;
    */

    int nums_arr[LENGTH];
    readArr(nums_arr, N_size);

    int num_rotations;
    cin >> num_rotations;

    while (num_rotations > 0)
    {
        performSimpleRotation(nums_arr, N_size);

        num_rotations--;
    }

    printArr(nums_arr, N_size);

    return 0;
}

void readArr(int arr[], const int &length)
{
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
}

void printArr(const int arr[], const int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }
}

void rotateArr(int array[], const int length)
{
    const int rotation_length = length / 2;
    for (int curr_index = 0; curr_index <= rotation_length; curr_index++)
    {
        int curr_elem_from_beginning = array[curr_index];
        int curr_elem_from_end = array[(length - 1) - curr_index];

        array[curr_index] = curr_elem_from_end;
        array[(length - 1) - curr_index] = curr_elem_from_beginning;
    }
}

// simple rotation is where we push_back the first element to last place
void performSimpleRotation(int arr_nums[], const int &length)
{
    int first_val = arr_nums[0];

    performLeftShift(arr_nums, length);

    arr_nums[length - 1] = first_val;
}

void performLeftShift(int arr[], const int &length)
{
    // perform left shift <- 1 space left
    // simple << shift space of array nums
    for (int i = 1; i < length; i++)
    {
        arr[i - 1] = arr[i];
    }
}