#include <iostream>
#include <vector>

int iterativeBinarySearch(const std::vector<int>& array, int target, int& comparisons) {
    // array indexes
    int low = 0;
    int high = array.size() - 1;

    //continue searching while the range is valid
    while (low <= high) { 
        // find middle index
        int mid = (low + high) / 2; 

        ++comparisons; // counts first comparison

        //binary search process
        if (array[mid] == target) { 
            return mid; 
        }

        ++comparisons; // counts second comparison

        if (array[mid] > target) { 
            high = mid - 1; // search left side
        }
        else { // target greater than middle element
            low = mid + 1; // search right side
        }
    }
    return -1; // if array number not found
}

int recursiveBinarySearch(const std::vector<int>& array, int target, int low, int high, int& comparisons) {
    // checks left and right array indexes
    if (low > high) {
        return -1;
    }

    int mid = (low + high) / 2; 

    // counts element comparisons
    ++comparisons; // counts first comparison

    if (array[mid] == target) {
        return mid; // target found at middle index
    }

    comparisons++; // counts second comparison

    if (array[mid] > target) {
        // function calls itself with new values
        return recursiveBinarySearch(array, target, low, mid - 1, comparisons); // search left side 
    }
    else { // target greater than middle element
        return recursiveBinarySearch(array, target, mid + 1, high, comparisons); // search right side
    }
}

void printIterativeResult(const std::vector<int>& array, int target, int& comparisons) {
    comparisons = 0;

    int result = iterativeBinarySearch(array, target, comparisons);
    
    std::cout << "Iterative Binary Search\n";
    std::cout << "Target: " << target << "\n";

    if (result != -1) { // if target was found 
        std::cout << "Index: " << result << "\n";
    }
    else {
        std::cout << "Index: Not Found\n";
    }

    std::cout << "Number of Comparisons: " << comparisons << "\n\n";
}

void printRecursiveResult(const std::vector<int>& array, int target, int& comparisons) {
    comparisons = 0;

    int result = recursiveBinarySearch(array, target, 0, array.size()-1, comparisons);
    
    std::cout << "Recursive Binary Search\n";
    std::cout << "Target: " << target << "\n";

    if (result != -1) { // if target was found
        std::cout << "Index: " << result << "\n";
    }
    else {
        std::cout << "Index: Not Found\n";
    }

    std::cout << "Number of Comparisons: " << comparisons << "\n\n";
}

int main() {
    std::vector<int> array1 = {5, 10, 15, 20, 25};
    std::vector<int> targets1 = {5, 25, 15, 3, 18};
    
    for (int target: targets1) { //for loop to check all 5 targets
        int comparisons = 0; // initializes variable
        printIterativeResult(array1, target, comparisons);
        printRecursiveResult(array1, target, comparisons);
    }

    std::vector<int> array2 = {1, 4, 9, 17, 26, 37};
    std::vector<int> targets2 = {1, 37, 9, 0, 12};

    for (int target: targets2) { 
        int comparisons = 0;
        printIterativeResult(array2, target, comparisons);
        printRecursiveResult(array2, target, comparisons);
    }

    std::vector<int> array3 = {4, 13, 25, 39, 54, 68, 91};
    std::vector<int> targets3 = {4, 91, 39, 3, 45};

    for (int target: targets3) { 
        int comparisons = 0;
        printIterativeResult(array3, target, comparisons);
        printRecursiveResult(array3, target, comparisons);
    }

    std::vector<int> array4 = {3, 8, 15, 21, 27, 32};
    std::vector<int> targets4 = {3, 32, 15, 1, 29};

    for (int target: targets4) { 
        int comparisons = 0;
        printIterativeResult(array4, target, comparisons);
        printRecursiveResult(array4, target, comparisons);
    }

    std::vector<int> array5 = {10, 22, 33, 42, 56, 78, 90, 103, 120};
    std::vector<int> targets5 = {10, 120, 56, 6, 17};

    for (int target: targets5) { 
        int comparisons = 0;
        printIterativeResult(array5, target, comparisons);
        printRecursiveResult(array5, target, comparisons);
    }
    
    return 0;
}