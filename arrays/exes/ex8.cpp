#include <iostream>
#include <cmath>

using namespace std;

void readArr(int dyn_arr[], int length);
void printArr(int dyn_arr[], int length);
void bubbleSortArr(int dyn_arr[], int length);

int main()
{
    const int LENGTH = 100;

    int N_input_lines;
    cin >> N_input_lines;

    int arr_nums[LENGTH] = {0};
    readArr(arr_nums, N_input_lines);

    for (int i = 0; i < N_input_lines; i++)
    {
        bool is_top_int = true;
        for (int j = i + 1; j < N_input_lines; j++)
        {
            int anchor_num = arr_nums[i];
            int curr_following_num = arr_nums[j];

            if (anchor_num <= curr_following_num)
            {
                is_top_int = false;
                break;
            }
        }

        if (is_top_int)
        {
            cout << arr_nums[i] << " ";
        }
    }

    return 0;
}

void readArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
}

void printArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

void bubbleSortArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {

        for (int j = 0; j < length; j++)
        {
            int anchor_num = arr[i];
            int following_num = arr[j];

            int tmp_bag_num = anchor_num;

            if (anchor_num < following_num)
            {

                arr[i] = arr[j];
                arr[j] = tmp_bag_num;
            }
        }
    }
}