#include <iostream>

using namespace std;

void readArr(int *point_arr_nums, const int &arr_length);
void calcCartesianProd(int *point_arr_source, const int &arr_source_length, int *point_arr_target);
void printArr(int arr[], const int &arr_length);

int main()
{
    const int LENGTH = 100;
    int *point_arr_nums = new int[LENGTH];

    int N_input_lines;
    cin >> N_input_lines;

    readArr(point_arr_nums, N_input_lines);

    const int cartesian_prod_length = N_input_lines * N_input_lines;
    int *point_cartesian_prod_arr = new int[cartesian_prod_length];

    calcCartesianProd(point_arr_nums, N_input_lines, point_cartesian_prod_arr);

    printArr(point_cartesian_prod_arr, cartesian_prod_length);

    // removing dangling pointers
    delete point_arr_nums;
    point_arr_nums = nullptr;

    delete point_cartesian_prod_arr;
    point_cartesian_prod_arr = nullptr;

    return 0;
}

void readArr(int *point_arr_nums, const int &arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        cin >> point_arr_nums[i];
    }
}

void calcCartesianProd(int *point_arr_source, const int &arr_source_length, int *point_arr_target)
{
    for (int i = 0; i < arr_source_length; i++)
    {
        for (int j = 0; j < arr_source_length; j++)
        {
            int curr_cartesian_prod_val = point_arr_source[i] * point_arr_source[j];

            *(point_arr_target) = curr_cartesian_prod_val;
            (point_arr_target)++;
        }
    }
}

void printArr(int arr[], const int &arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}