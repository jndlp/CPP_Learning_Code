#include <iostream>
#include <string.h>

/**
 * @brief Request and display the integers entering the terminal.
 * -1 to exit the loop.
 *
 */
void loopWhile() {
    while (true) {
        int number = 0;
        std::cin >> number;

        if (number == -1) {
            break;
        }

        std::cout << "Craow " << number << "!" << std::endl;
    }
}

/**
 * @brief Request and display the integers entering the terminal.
 * -1 to exit the loop.
 *
 */
void loopDoWhile() {
    int number = 0;

    do {
        std::cin >> number;
        std::cout << "Craow " << number << "!" << std::endl;
    } while (number != -1);
}

/**
 * @brief Request and display the first 10 integers to enter the terminal.
 *
 */
void loopForInt() {
    for (int i = 0; i < 10; ++i) {
        int number = 0;
        std::cin >> number;
        std::cout << "Craow " << number << "!" << std::endl;
    }
}

/**
 * @brief Request and display the first 10 strings to enter the terminal.
 *
 */
void loopForString() {
    for (int i = 0; i < 10; ++i) {
        std::string word;
        std::cin >> word;
        std::cout << "Craow " << word << "!" << std::endl;
    }
}

/**
 * @brief Request and display the first 10 strings to enter the terminal.
 *
 */
void loopForString2() {
    using namespace std;

    for (int i = 0; i < 10; ++i) {
        string word;
        cin >> word;
        cout << "Craow " << word << "!" << endl;
    }
}

/**
 * @brief Use the loopForString2 function.
 *
 * @return int
 */
int main() {
    loopForString2();
    return 0;
}
