#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <iterator>
#include <cmath>

using namespace std;

void benchmark(int x, int y);
int getArray(int x, int y);
void myFunction(int* input, int size);

// Changed back to template with RandomAccessIterator
template<typename RandomAccessIterator>
void gnome_sort(RandomAccessIterator begin, RandomAccessIterator end) {
    //i and j are pointers
    auto i = begin + 1;
    auto j = begin + 2;

    //runs while i is less than end value
    while (i < end) {
        //if i is less than value before i
        if (!(i <(i - 1))) {
            //set j ahead of i
            i = j;
            ++j;
        }
        else {
            //swaps i and value before i
            std::iter_swap(i - 1, i);
            --i; // decrements i
            //if i is at beginning 
            if (i == begin) {
                //set j ahead of i
                i = j;
                ++j;
            }
        }
    }
}

int main()
{
    benchmark(100, 7);
    return 0;
}

void benchmark(int x, int y)
{
    int myTests = getArray(x, y);

    for (int i = 0; i < x; ++i) {
        int size = 2 * i * static_cast<int>(pow(y, 5));
        myFunction(myTests[i], size);
    }

    for (int i = 0; i < x; ++i) {
        delete[] myTests[i];
    }
    delete[] myTests;
}

int getArray(int x, int y)
{
    int result = new int* [x];
    srand((unsigned)time(0));
    for (int i = 0; i < x; ++i) {
        int size = 2 * i * static_cast<int>(pow(y, 5));
        result[i] = new int[size];
        for (int j = 0; j < size; ++j) {
            result[i][j] = (rand() % 500000) - 50000;
        }
    }
    return result;
}

void myFunction(int* input, int size)
{
    // Start the timer
    auto start = chrono::high_resolution_clock::now();

    // Sort the array using template version
    gnome_sort(input, input + size);

    // Stop the timer
    auto finish = chrono::high_resolution_clock::now();
    auto algTime = chrono::duration_cast<chrono::nanoseconds>(finish - start).count();

    // Output the time taken and the size of the array
    cout << "It takes " << algTime << " nanoseconds to sort an array of size "
        << size << endl;
}
