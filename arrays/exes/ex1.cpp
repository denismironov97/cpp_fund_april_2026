#include <iostream>

using namespace std;

void printArr(int array[], int length);

int main()
{
    const int SIZE = 100;
    int arr_1[SIZE];
    int arr_2[SIZE];

    int N_input_lines;
    cin >> N_input_lines;

    for (int indx = 0; indx < N_input_lines; indx++)
    {
        int num_1;
        int num_2;
        cin >> num_1 >> num_2;

        // checking if curr intput line is even or odd line;
        //  based on that we decide how to position the numbers;
        if (indx % 2 == 0)
        {
            arr_1[indx] = num_1;
            arr_2[indx] = num_2;
        }
        else
        {
            arr_1[indx] = num_2;
            arr_2[indx] = num_1;
        }
    }

    printArr(arr_1, N_input_lines);
    printArr(arr_2, N_input_lines);

    return 0;
}

void printArr(int array[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}