#include <iostream>
#include <vector>

// Verzija sa indeksima
int seqSearch(const std::vector<int>& arr, int key) {

    for(int i = 0; i < arr.size(); i++) {

        if(arr[i] == key)
            return i; 

    }

    return arr.size();
}

// Verzija sa iteratorom
auto seqSearchIterator(const std::vector<int>& arr, int key) {

    for(auto it = arr.begin(); it != arr.end(); it++) {
        if(*it == key)
            return it;
    }

    return arr.end();
}

int main () {

    std::vector<int> arr = {5, 12, 3, 7, 4, 1, 37};

    std::cout << "Unesi trazeni kljuc: ";

    int key;
    std::cin >> key;

    std::cout << seqSearch(arr, key) << std::endl;   
}