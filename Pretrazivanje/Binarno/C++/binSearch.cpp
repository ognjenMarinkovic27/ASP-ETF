#include <iostream>
#include <vector>

int binSearch(const std::vector<int>& arr, int key) {

    int low = 0;
    int high = arr.size() - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }

    return arr.size();

}

int main () {

    std::vector<int> arr = {5, 12, 3, 7, 4, 1, 37};

    std::cout << "Unesi trazeni kljuc: ";

    int key;
    std::cin >> key;

    std::cout << binSearch(arr, key) << std::endl;   
}