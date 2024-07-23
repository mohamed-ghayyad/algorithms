#include <iostream>
#include <deque>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace chrono;

template <typename T>
class SortAlgorithm {
public:
    auto bubbleSort(std::deque<T>& arr) {
        auto begin = high_resolution_clock::now();
        for (size_t i = 0; i < arr.size(); ++i) {
            for (size_t j = 0; j < arr.size() - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - begin);
        return duration.count();
    }

    auto selectionSort(std::deque<T>& arr) {
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
        auto duration = duration_cast<microseconds>(end - begin);
        return duration.count();
    }

    auto insertionSort(std::deque<T>& arr) {
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
        auto duration = duration_cast<microseconds>(end - begin);
        return duration.count();
    }

    auto introSort(std::deque<T>& arr) {
        auto begin = high_resolution_clock::now();
        std::sort(arr.begin(), arr.end());
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - begin);
        return duration.count();
    }

    auto heapSort(std::deque<T>& arr) {
        auto begin = high_resolution_clock::now();
        std::make_heap(arr.begin(), arr.end());
        std::sort_heap(arr.begin(), arr.end());
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - begin);
        return duration.count();
    }

    auto mergeSort(std::deque<T>& arr) {
        auto begin = high_resolution_clock::now();
        std::stable_sort(arr.begin(), arr.end());
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - begin);
        return duration.count();
    }

    void whichIsBestSort(std::deque<T> arr) {
        std::deque<T> arr_copy;

        arr_copy = arr;
        auto bubble = bubbleSort(arr_copy);
        
        arr_copy = arr;
        auto selection = selectionSort(arr_copy);
        
        arr_copy = arr;
        auto insertion = insertionSort(arr_copy);
        
        arr_copy = arr;
        auto heap = heapSort(arr_copy);
        
        arr_copy = arr;
        auto intro = introSort(arr_copy);
        
        arr_copy = arr;
        auto merge = mergeSort(arr_copy);

        std::cout << "Starting Time Analysis of different algo:" << std::endl;
        std::cout << "Bubble Sort: " << bubble << " microseconds" << std::endl;
        std::cout << "Selection Sort: " << selection << " microseconds" << std::endl;
        std::cout << "Insertion Sort: " << insertion << " microseconds" << std::endl;
        std::cout << "Heap Sort: " << heap << " microseconds" << std::endl;
        std::cout << "Intro Sort: " << intro << " microseconds" << std::endl;
        std::cout << "Merge Sort: " << merge << " microseconds" << std::endl;
        std::cout << "====================================" << std::endl;

        if (bubble < selection && bubble < insertion && bubble < heap && bubble < merge && bubble < intro) {
            std::cout << "Bubble Sort is the best" << std::endl;
        } else if (selection < bubble && selection < insertion && selection < heap && selection < merge && selection < intro) {
            std::cout << "Selection Sort is the best" << std::endl;
        } else if (insertion < bubble && insertion < selection && insertion < heap && insertion < merge && insertion < intro) {
            std::cout << "Insertion Sort is the best" << std::endl;
        } else if (heap < bubble && heap < selection && heap < insertion && heap < merge && heap < intro) {
            std::cout << "Heap Sort is the best" << std::endl;
        } else if (merge < bubble && merge < selection && merge < insertion && merge < heap && merge < intro) {
            std::cout << "Merge Sort is the best" << std::endl;
        } else {
            std::cout << "Intro Sort is the best" << std::endl;
        }
    }

    void print(const std::deque<T>& arr) const {
        for (const auto& elem : arr) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    std::deque<int> arr = {5, 4, 3, 2, 1, 5, 6, 7, 8, 9, 2, 1, 4, 5, 7, 8, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    SortAlgorithm<int> s;
    std::deque<std::string> arr2 = {"hello", "world", "this", "is", "a", "test", "for", "string", "sorting", "algorithm", "using", "c++", "stl", "library", "and", "templates", "and", "classes"};
    SortAlgorithm<std::string> s2;

    std::cout << "Integers sorting:" << std::endl;
    s.whichIsBestSort(arr);

    std::cout << "Strings sorting:" << std::endl;
    s2.whichIsBestSort(arr2);

    return 0;
}
