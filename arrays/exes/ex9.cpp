#include <iostream>
#include <vector>
#include <utility>
#include <array>

using namespace std;

const int PAIR_LENGTH = 2;

void readArr(int arr[], int length);
vector<array<int, PAIR_LENGTH>> getPairsEqualToMagicNum(const int array_source[], const int &arr_source_length, const int &magic_num);
void printMagicPairs(const vector<array<int, PAIR_LENGTH>> &unique_pairs);

// Magic Sum-Ex 9
int main()
{
    const int LENGTH = 100;

    int N_size;
    cin >> N_size;

    int arr_nums[LENGTH] = {0};

    readArr(arr_nums, N_size);

    int magic_num;
    cin >> magic_num;

    const vector<array<int, PAIR_LENGTH>> unique_pairs = getPairsEqualToMagicNum(arr_nums, N_size, magic_num);

    printMagicPairs(unique_pairs);

    return 0;
}

void readArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
    }
}

void printMagicPairs(const vector<array<int, PAIR_LENGTH>> &unique_pairs)
{
    for (int i = 0; i < unique_pairs.size(); i++)
    {
        // auto curr_arr_pair = unique_pairs[i];
        const array<int, PAIR_LENGTH> curr_arr_pair = unique_pairs[i];
        int num_1 = curr_arr_pair.at(0);
        int num_2 = curr_arr_pair.at(1);

        cout << num_1 << " " << num_2 << endl;
    }
}

// finds a pair of int numbers equal to read third int(magic number) from terminal
vector<array<int, PAIR_LENGTH>> getPairsEqualToMagicNum(const int array_source[], const int &arr_source_length, const int &magic_num)
{
    vector<array<int, PAIR_LENGTH>> unique_pair_nums;

    for (int i = 0; i < arr_source_length - 1; i++)
    {
        for (int j = i + 1; j < arr_source_length; j++)
        {
            int curr_pair_sum = array_source[i] + array_source[j];

            if (curr_pair_sum == magic_num)
            {
                array<int, PAIR_LENGTH> curr_unique_pair;
                curr_unique_pair[0] = array_source[i];
                curr_unique_pair[1] = array_source[j];

                unique_pair_nums.push_back(curr_unique_pair);
            }
        }
    }

    return unique_pair_nums;
}