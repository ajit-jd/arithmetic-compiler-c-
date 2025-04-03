#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

class arithmetic {
    string expression;
    vector<int> numbers; // Use vector to store individual numbers
    string symbols;      // Store symbols as is
    int result;

public:
    arithmetic() {
        cout << "This is a project for an Arithmetic Compiler" << endl;
    }

    ~arithmetic() {
        cout << "End of the project" << endl;
    }

    void input() {
        cout << "Enter the calculation expression (e.g., 1+2*3): ";
        getline(cin, expression);

        string temp = ""; // Temporary string to hold digits

        // Tokenize input into numbers and symbols
        for (char ch : expression) {
            if (isdigit(ch)) {
                temp += ch; // Accumulate digits
            } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                if (!temp.empty()) {
                    // Convert accumulated digits into an integer
                    numbers.push_back(stoi(temp));
                    temp = ""; // Clear temporary string
                }
                symbols += ch; // Add symbol to symbols
            }
        }

        // Handle last number in the expression
        if (!temp.empty()) {
            numbers.push_back(stoi(temp));
        }

        // Debugging: Print numbers and symbols
        cout << "Numbers: ";
        for (int num : numbers) cout << num << " ";
        cout << "\nSymbols: " << symbols << endl;
    }

    void evaluate() {
        int i = 0;

        // Handle operator precedence (e.g., *, / before +, -)
        while (symbols.size() > 0) {
            for (size_t j = 0; j < symbols.size(); ++j) {
                if (symbols[j] == '*') {
                    numbers[j] *= numbers[j + 1];
                } else if (symbols[j] == '/') {
                    numbers[j] /= numbers[j + 1];
                } else if (symbols[j] == '+') {
                    numbers[j] += numbers[j + 1];
                } else if (symbols[j] == '-') {
                    numbers[j] -= numbers[j + 1];
                }
                // Remove the processed operator and number
                numbers.erase(numbers.begin() + j + 1);
                symbols.erase(symbols.begin() + j);
                break; // Restart loop after processing
            }
        }
        result = numbers[0]; // Final result
    }

    void output() {
        cout << "Result: " << result << endl;
    }
};

int main() {
    arithmetic ar;
    ar.input();
    ar.evaluate();
    ar.output();
    return 0;
}