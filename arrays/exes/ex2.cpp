#include <iostream>

using namespace std;

void readArr(int array[], int length);
void printArr(int arr[], int length);

int main()
{
    const int LENGTH = 100;

    int N_input_lines;
    cin >> N_input_lines;

    int arr[LENGTH] = {0};
    readArr(arr, N_input_lines);

    int seq_ccur = 1;
    int curr_occur = 1;
    int repeating_num = arr[0];
    for (int i = 1; i < N_input_lines; i++)
    {
        int curr_num = arr[i];
        int prev_num = arr[i - 1];

        if (curr_num == prev_num)
        {
            curr_occur++;
        }
        else
        {
            curr_occur = 1;
        }

        if (curr_occur >= seq_ccur)
        {
            seq_ccur = curr_occur;
            repeating_num = arr[i];
        }
    }

    for (int i = 0; i < seq_ccur; i++)
    {
        cout << repeating_num << ' ';
    }

    return 0;
}

void readArr(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cin >> array[i];
    }
}