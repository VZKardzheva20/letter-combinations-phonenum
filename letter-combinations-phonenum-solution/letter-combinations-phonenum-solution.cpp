#include <iostream>
#include <vector>
#include <string>
#include <map>

std::map<char, std::string> mapping = {
    {'0', " "}, {'1', "@"}, {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
    {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
};

void generateCombinations(const std::string& digits, std::vector<std::string>& result, std::string current, int index) {
    if (index == digits.size()) {
        result.push_back(current);
        return;
    }

    std::string letters = mapping[digits[index]];
    for (char letter : letters) {
        generateCombinations(digits, result, current + letter, index + 1);
    }
}

std::vector<std::string> letterCombinations(const std::string& digits) {
    std::vector<std::string> result;
    if (digits.empty()) return result;
    generateCombinations(digits, result, "", 0);
    return result;
}

int main() {
    std::string input1, input2, input3;
    std::cin >> input1 >> input2 >> input3;
    std::vector<std::string> inputs = { input1, input2, input3 };

    for (int i = 0; i < inputs.size(); ++i) {
        std::vector<std::string> combinations = letterCombinations(inputs[i]);

        std::cout << i + 1 << ".\t\tAll letter combinations for '" << inputs[i] << "': [\"";

        for (int j = 0; j < combinations.size(); ++j) {
            std::cout << combinations[j];
            if (j != combinations.size() - 1)
                std::cout << "\", \"";
        }

        std::cout << "\"]\n----------------------------------------------------------------------------------------------------" << std::endl;
    }

    return 0;
}
