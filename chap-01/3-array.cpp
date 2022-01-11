#include <iostream>
#include <vector>

/**
 * @brief Display the array [0, 1, 2, 3]
 *
 */
void array1() {
    int array[] = { 0, 1, 2, 3 };

    for (int i = 0; i < 4; ++i) {
        std::cout << array[i] << std::endl;
    }
}

/**
 * @brief Display the array [1, 2, ..., 50]
 *
 */
void array2() {
    int length        = 50;
    int array[length] = {};

    for (int i = 0; i < length; ++i) {
        array[i] = i + 1;
    }
}

/**
 * @brief Get the 1st argument n, create a vector of size n,
 * fill the vector of 1 (included) to n (included)
 * then display it
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char** argv) {
    // We check if there is an argument
    if (argc < 2) {
        std::cerr << "Expected argument for array size." << std::endl;
        return -1;
    }

    // We check the argument
    int length = std::stoi(argv[1]);
    if (length <= 0) {
        std::cerr << "Expected strictly positive value for array size." << std::endl;
        return -1;
    }
    std::cout << "Size: " << length << std::endl;

    std::vector<int> array; // We create a vector
    array.reserve(length);  // We reserve the sufficient size

    // We fill the vector
    for (int i = 0; i < length; ++i) {
        array.emplace_back(i + 1);
    }

    // We display the vector
    for (int value : array) {
        std::cout << value << std::endl;
    }

    return 0;
}
