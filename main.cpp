
/* Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent elements if they are in wrong order.
* The pass through the list is repeated until the list is sorted. The algorithm, which is a comparison sort, is named for the way smaller elements "bubble" to the top of the list.
* Although the algorithm is simple, it is too slow and impractical for most problems even when compared to insertion sort. It can be practical if the input is usually in sort order but may occasionally have some out-of-order elements nearly in position.
* Time Complexity: O(n^2) where n is the number of elements in the array.
* Space Complexity: O(1)
* Stable: Yes
* In-place: Yes
* Online: Yes
* Advantages: Simple, easy to implement, and can be used for small data sets.
* Disadvantages: Very slow and inefficient for large data sets.
* Applications: Bubble sort is used in computer graphics to detect and remove hidden surfaces in 3D objects.
* It is also used in the card game Bridge to rank players according to their skill level.
* It is also used in the game of billiards to rank players according to their skill level.
* It is also used in the game of chess to rank players according to their skill level.
* Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure to sort elements. It divides its input into a sorted and an unsorted region, and it iteratively shrinks the unsorted region by extracting the largest element and moving that to the sorted region.
* The heap sort algorithm involves preparing the list by first turning it into a max heap. The algorithm then repeatedly swaps the first value of the list with the last value, decreasing the range of values considered in the heap operation by one, and sifting the new first value into its position in the heap.
* This repeats until the range of considered values is one value in length.
* The steps are:
* 1. Create a Heap from the input data.
* 2. At this point, the largest item is stored at the root of the heap. Replace it with the last item of the heap followed by reducing the size of heap by 1. Finally, heapify the root of the tree.
* 3. Repeat step 2 while the size of the heap is greater than 1.
* Time Complexity: O(n log n) where n is the number of elements in the array.
* Space Complexity: O(1)
* Stable: No
* In-place: Yes
* Online: No
* Advantages: It is an in-place algorithm and has a time complexity of O(n log n).
* Disadvantages: It is not a stable algorithm and has a space complexity of O(1).
* Applications: Heap sort is used in operating systems to allocate memory blocks of different sizes.
* It is also used in network routing algorithms to find the shortest path between two nodes.
* It is also used in the game of chess to rank players according to their skill level.
* It is also used in the game of billiards to rank players according to their skill level.
* Insertion sort is a simple sorting algorithm that works similar to the way you sort playing cards in your hands. The array is virtually split into a sorted and an unsorted part. Values from the unsorted part are picked and placed at the correct position in the sorted part.
* Time Complexity: O(n^2) where n is the number of elements in the array.
* Space Complexity: O(1)
* Stable: Yes
* In-place: Yes
* Online: Yes
* Advantages: Simple, efficient for small data sets, and adaptive.
* Disadvantages: Inefficient for large data sets.
* Applications: Insertion sort is used in the card game Bridge to rank players according to their skill level.
* It is also used in the game of chess to rank players according to their skill level.
* It is also used in the game of billiards to rank players according to their skill level.
* It is also used in computer graphics to detect and remove hidden surfaces in 3D objects.
* Merge Sort is a divide and conquer algorithm that was invented by John von Neumann in 1945. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves.
* The merge() function is used for merging two halves. The merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted and merges the two sorted sub-arrays into one.
* Time Complexity: O(n log n) where n is the number of elements in the array.
* Space Complexity: O(n)
* Stable: Yes
* In-place: No
* Online: No
* Advantages: Merge sort is a stable sort, which means it retains the relative order of equal elements.
* Disadvantages: Merge sort requires additional memory space of O(n) for the temporary array.
* Applications: Merge sort is used in network routing algorithms to find the shortest path between two nodes.
* It is also used in the game of chess to rank players according to their skill level.
* It is also used in the game of billiards to rank players according to their skill level.
* It is also used in computer graphics to detect and remove hidden surfaces in 3D objects.
* Selection sort is an in-place comparison sorting algorithm that divides the input list into two parts: a sorted sublist of items that is built up from left to right at the front (left) of the list and a sublist of the remaining unsorted items that occupy the rest of the list.
* Initially, the sorted sublist is empty and the unsorted sublist is the entire input list. The algorithm proceeds by finding the smallest (or largest, depending on sorting order) element in the unsorted sublist, exchanging (swapping) it with the leftmost unsorted element (putting it in sorted order), and moving the sublist boundaries one element to the right.
* Time Complexity: O(n^2) where n is the number of elements in the array.
* Space Complexity: O(1)
* Stable: No
* In-place: Yes
* Online: No
* Advantages: Selection sort is simple and easy to implement.
* Disadvantages: Selection sort is inefficient on large lists and generally performs worse than the similar insertion sort.
* Applications: Selection sort is used in the card game Bridge to rank players according to their skill level.
* It is also used in the game of chess to rank players according to their skill level.
* It is also used in the game of billiards to rank players according to their skill level.
* It is also used in computer graphics to detect and remove hidden surfaces in 3D objects.
* Intro Sort is a hybrid sorting algorithm that provides both fast average performance and optimal worst-case performance. It begins with quicksort and switches to heapsort when the recursion depth exceeds a level based on the number of elements being sorted.
* Time Complexity: O(n log n) where n is the number of elements in the array.
* Space Complexity: O(log n)
* Stable: No
* In-place: Yes
* Online: No
* Advantages: Intro sort is a hybrid sorting algorithm that provides both fast average performance and optimal worst-case performance.
* Disadvantages: Intro sort requires additional memory space of O(log n) for the recursion stack.
* Applications: Intro sort is used in network routing algorithms to find the shortest path between two nodes.
* It is also used in the card game Bridge to rank players according to their skill level.
* It is also used in the game of chess to rank players according to their skill level.
* It is also used in the game of billiards to rank players according to their skill level.
* It is also used in computer graphics to detect and remove hidden surfaces in 3D objects.
* Programming Language: C++
* Software Engineer: Mohamed Jamal
* Date: 7/23/2024
*/

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
