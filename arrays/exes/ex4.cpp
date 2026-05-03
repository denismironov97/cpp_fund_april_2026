#include <iostream>
#include <climits>

using namespace std;

void readArr(int array[], int length);
void printArr(int array[], int arr_length);
void countOccurrencesOfDigits(int *point_arr_source, int arr_source_length, int *point_arr_target, int arr_target_length);
int getMaxOccurrence(int *digit_occurrence_ledger, int decimal_digit_length);
void printMaxOccurrences(int *pointer_arr_ledger, int ledger_length, int max_occur_val);

int main()
{
    const int LENGTH = 15;
    int arr_nums[LENGTH] = {0};

    int N_input_lines;
    cin >> N_input_lines;

    readArr(arr_nums, N_input_lines);

    const int decimal_digit_length = 10;
    int *digit_occurrence_ledger = new int[decimal_digit_length]{0};

    countOccurrencesOfDigits(arr_nums, N_input_lines, digit_occurrence_ledger, decimal_digit_length);

    int max_occ_val_index = getMaxOccurrence(digit_occurrence_ledger, decimal_digit_length);

    // cout << "The number " << max_occ_val_index << " is the most frequent" << endl;
    // cout << max_occ_val_index << endl;

    printMaxOccurrences(digit_occurrence_ledger, decimal_digit_length, digit_occurrence_ledger[max_occ_val_index]);

    // remove dangling pointers
    delete digit_occurrence_ledger;
    digit_occurrence_ledger = nullptr;

    return 0;
}

void readArr(int array[], int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        int num;
        cin >> num;
        array[i] = num;
    }
}

void printArr(int array[], int arr_length)
{
    for (int i = 0; i < arr_length; i++)
    {
        cout << array[i] << " ";
    }

    cout << endl;
}

void countOccurrencesOfDigits(int *point_arr_source, int arr_source_length, int *point_arr_target, int arr_target_length)
{
    for (int i = 0; i < arr_source_length; i++)
    {
        // int curr_digit = *(point_arr_source + i);
        int curr_digit = point_arr_source[i];

        (point_arr_target[curr_digit])++;
    }
}

int getMaxOccurrence(int *digit_occurrence_ledger, int decimal_digit_length)
{
    int max_occ_count = INT_MIN;
    int occ_index_value = 0;
    for (int curr_index = 0; curr_index < decimal_digit_length; curr_index++)
    {
        int curr_occ = digit_occurrence_ledger[curr_index];
        if (curr_occ >= max_occ_count)
        {
            max_occ_count = curr_occ;
            occ_index_value = curr_index;
        }
    }

    return occ_index_value;
}

void printMaxOccurrences(int *pointer_arr_ledger, int ledger_length, int max_occur_val)
{
    for (int curr_index = 0; curr_index < ledger_length; curr_index++)
    {
        int curr_number = *(pointer_arr_ledger + curr_index);

        if (curr_number == max_occur_val)
        {
            cout << curr_index << " ";
        }
    }
}