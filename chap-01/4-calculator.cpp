#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Function that parses argv.
 *
 * @param op +, * or -
 * @param values int value
 * @param argc length argv
 * @param argv arguments
 * @return true if it is the parsing did not cause an error
 * @return false if the parsing resulted in an error
 */
bool parse_params(char& op, std::vector<int>& values, int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Expected operator as first argument." << std::endl;
        return false;
    }

    op = argv[1][0];

    if (op != '+' && op != '*' && op != '-') {
        std::cerr << "Expected operator to be '+', '*' or '-'." << std::endl;
        return false;
    }

    for (auto arg_i = 2; arg_i < argc; ++arg_i) {
        auto value = std::stoi(argv[arg_i]);
        values.emplace_back(value);
    }

    if (op == '-' && values.empty()) {
        std::cerr << "Operator '-' expects at least one operand to substract from." << std::endl;
        return false;
    }

    return true;
}

/**
 * @brief return the sum of the elements of the vectors.
 *
 * @param values vector<int>
 * @return int result
 */
int add(const std::vector<int>& values) {
    int result = 0;
    for (auto v : values) {
        result += v;
    }
    return result;
}

/**
 * @brief return the product of the elements of the vectors.
 *
 * @param values vector<int>
 * @return int result
 */
int multiply(const std::vector<int>& values) {
    auto result = 1;
    for (auto v : values) {
        result *= v;
    }
    return result;
}

/**
 * @brief return the diference of the elements of the vectors.
 *
 * @param values vector<int>
 * @return int result
 */
int sub(const std::vector<int>& values) {
    auto result = values[0];
    for (auto i = 1u; i < values.size(); ++i) {
        result -= values[i];
    }
    return result;
}

/**
 * @brief Apply the sign of the operand to values.
 *
 * @param op
 * @param values vector<int>
 * @return int result
 */
int compute_result(char op, const std::vector<int>& values) {
    switch (op) {
    case '+':
        return add(values);
    case '*':
        return multiply(values);
    case '-':
        return sub(values);
    default:
        return 0;
    }
}

/**
 * @brief Function that displays an integer.
 *
 * @param result
 */
void display_result(int result) {
    std::cout << "Result is " << result << std::endl;
}

/**
 * @brief displays the results of the operation with the values
 * resulting from the parsing of the arguments.
 *
 * @param argc
 * @param argv
 * @return 0 No problem
 * @return 1 Problem during parsing
 */
int main(int argc, char** argv) {
    auto op     = '.';
    auto values = std::vector<int>();

    if (!parse_params(op, values, argc, argv)) {
        return -1;
    }

    auto result = compute_result(op, values);

    display_result(result);

    return 0;
}
