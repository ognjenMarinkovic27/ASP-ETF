#include <iostream>
#include <vector>

// Verzija sa indeksima
std::vector<int> seqSearchMul(const std::vector<int>& arr, const std::vector<int>& keys) {

    std::vector<int> positions(keys.size(), arr.size());

    int i, j;
    i = j = 0;

    while(i < arr.size() && j < keys.size()) {

        while(i < arr.size() && keys[j] > arr[i])
            i++;

        if(keys[j] == arr[i])
            positions[j] = i;

        j++;
    }
    
    return positions;
}

// Verzija sa iteratorom
std::vector<int> seqSearchMulIterator(const std::vector<int>& arr, const std::vector<int>& keys) {

    std::vector<int> positions(keys.size(), arr.size());

    auto i = arr.begin();
    auto j = keys.begin();

    while(i != arr.end() && j != keys.end()) {

        while(i != arr.end() && *j > *i)
            i++;

        if(*j == *i)
            positions[j - keys.begin()] = i - arr.begin();

        j++;
    }
    
    return positions;
}

int main () {

    std::vector<int> arr = {1, 3, 4, 5, 7, 12, 37};
    
    int n;
    std::cout << "Unesi broj trazenih kljuceva: ";
    std::cin >> n;

    std::cout << "Unesi trazene kljuceve: ";

    std::vector<int> keys(n);

    for(auto& key : keys)
        std::cin >> key;

    std::vector<int> positions = seqSearchMul(arr, keys);

    for(auto position : positions)
        std::cout << position << " ";

    std::cout << std::endl;
}