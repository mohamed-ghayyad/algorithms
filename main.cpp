#include <iostream>
#include <deque>
#include <algorithm>
#include <chrono>
#include <vector>
#include <iomanip>

using namespace std;
using namespace chrono;

template <typename T>
class SortAlgorithm {
public:
    auto bubbleSort(std::deque<T> &arr) {
        auto begin = high_resolution_clock::now();
        for (size_t i = 0; i < arr.size(); ++i) {
            for (size_t j = 0; j < arr.size() - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
        auto end = high_resolution_clock::now();
        return duration_cast<microseconds>(end - begin).count();
    }

    auto stableSort(std::deque<T> &arr) {
        auto begin = high_resolution_clock::now();
        std::stable_sort(arr.begin(), arr.end());
        auto end = high_resolution_clock::now();
        return duration_cast<microseconds>(end - begin).count();
    }

    auto selectionSort(std::deque<T> &arr) {
        auto begin = high_resolution_clock::now();
        for (size_t i = 0; i < arr.size() - 1; ++i) {
            size_t min = i;
            for (size_t j = i + 1; j < arr.size(); ++j) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            std::swap(arr[i], arr[min]);
        }
        auto end = high_resolution_clock::now();
        return duration_cast<microseconds>(end - begin).count();
    }

    auto insertionSort(std::deque<T> &arr) {
        auto begin = high_resolution_clock::now();
        for (size_t i = 1; i < arr.size(); ++i) {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = key;
        }
        auto end = high_resolution_clock::now();
        return duration_cast<microseconds>(end - begin).count();
    }

    auto introSort(std::deque<T> &arr) {
        auto begin = high_resolution_clock::now();
        std::sort(arr.begin(), arr.end());
        auto end = high_resolution_clock::now();
        return duration_cast<microseconds>(end - begin).count();
    }

    auto heapSort(std::deque<T> &arr) {
        auto begin = high_resolution_clock::now();
        std::make_heap(arr.begin(), arr.end());
        std::sort_heap(arr.begin(), arr.end());
        auto end = high_resolution_clock::now();
        return duration_cast<microseconds>(end - begin).count();
    }

    void merge(std::deque<T> &array, int const left, int const mid, int const right) {
        int const subArrayOne = mid - left + 1;
        int const subArrayTwo = right - mid;

        std::deque<T> leftArray(subArrayOne);
        std::deque<T> rightArray(subArrayTwo);

        for (auto i = 0; i < subArrayOne; i++)
            leftArray[i] = array[left + i];
        for (auto j = 0; j < subArrayTwo; j++)
            rightArray[j] = array[mid + 1 + j];

        int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
        int indexOfMergedArray = left;

        while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
            if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
                array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            } else {
                array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
            indexOfMergedArray++;
        }

        while (indexOfSubArrayOne < subArrayOne) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
            indexOfMergedArray++;
        }

        while (indexOfSubArrayTwo < subArrayTwo) {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            indexOfMergedArray++;
        }
    }

    long long mergeSort(std::deque<T> &array, int const begin, int const end) {
        if (begin >= end) {
            return 0;
        }

        auto be = high_resolution_clock::now();
        int mid = begin + (end - begin) / 2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
        auto en = high_resolution_clock::now();
        return duration_cast<microseconds>(en - be).count();
    }

    void measureSortingTimes(const std::deque<T> &arr, std::vector<std::vector<long long>> &results) {
        std::deque<T> arr_copy = arr;

        results[0].push_back(bubbleSort(arr_copy));
        arr_copy = arr;
        results[1].push_back(selectionSort(arr_copy));
        arr_copy = arr;
        results[2].push_back(insertionSort(arr_copy));
        arr_copy = arr;
        results[3].push_back(heapSort(arr_copy));
        arr_copy = arr;
        results[4].push_back(introSort(arr_copy));
        arr_copy = arr;
        results[5].push_back(mergeSort(arr_copy, 0, arr_copy.size() - 1));
        arr_copy = arr;
        results[6].push_back(stableSort(arr_copy));
    }

    void printTable(const std::vector<std::vector<long long>> &results, const std::vector<std::string> &names) {
        cout << setw(15) << "Algorithm" << " | ";
        for (size_t i = 0; i < results[0].size(); ++i) {
            cout << setw(10) << "Run " << i + 1 << " | ";
        }
        cout << endl;

        for (size_t i = 0; i < results.size(); ++i) {
            cout << setw(15) << names[i] << " | ";
            for (const auto &time : results[i]) {
                cout << setw(10) << time << " | ";
            }
            cout << endl;
        }
    }
};

int main() {
    std::deque<int> arr = {5, 4, 3, 2, 1, 5, 6, 7, 8, 9, 2, 1, 4, 5, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};
    std::deque<std::string> arr2 = {"hello", "world", "this", "is", "a", "test", "for", "string", "sorting", "algorithm", "using", "c++", "stl", "library", "and", "templates", "and", "classes"};

    SortAlgorithm<int> s;
    SortAlgorithm<std::string> s2;

    std::vector<std::vector<long long>> intResults(7);
    std::vector<std::vector<long long>> stringResults(7);
    std::vector<std::string> algorithmNames = {"Bubble Sort", "Selection Sort", "Insertion Sort", "Heap Sort", "Intro Sort", "Merge Sort", "Stable Sort"};

    std::cout << "Integers sorting:" << std::endl;
    for (int i = 0; i < 15; ++i) {
        s.measureSortingTimes(arr, intResults);
    }
    s.printTable(intResults, algorithmNames);

    std::cout << "Strings sorting:" << std::endl;
    for (int i = 0; i < 15; ++i) {
        s2.measureSortingTimes(arr2, stringResults);
    }
    s2.printTable(stringResults, algorithmNames);

    return 0;
}
