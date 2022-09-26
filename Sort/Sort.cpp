#include <iostream>
#include <string>
const int size = 1000;

int Max(int array[size]) {
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}

void PopulateArray(int* array) {
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
    }
}

void PrintArray(int* array) {
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i] << "\n";
    }
}

void CountElements(int* array, int* count) {
    for (int i = 0; i < size; i++)
    {
        count[array[i]]++;
    }
}

void CumulativeCount(int* count,int max) {
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }
}

void FinalSort(int* array, int* count, int* output) {
    for (int i = size - 1; i >= 0; i--)
    {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
}

int main()
{
    srand(time(0));

    int output[size] = {};
    int array[size] = {};
    PopulateArray(array);

    int max = Max(array);

    int* count = new int[max+1] {0};

    CountElements(array, count);

    CumulativeCount(count,max);

    FinalSort(array, count, output);

    PrintArray(output);
}
