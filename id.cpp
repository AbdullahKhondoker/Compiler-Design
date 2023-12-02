#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>

using namespace std;

void extractFunctionNames(const string& line, unordered_set<string>& functionNames) {
    istringstream iss(line);
    string token;
    while (iss >> token) {
        if (token == "int" || token == "void") {
            iss >> token; // Get the next token (potential function name)
            size_t pos = token.find('(');
            if (pos != string::npos && token != "main()") {
                functionNames.insert(token.substr(0, pos));
            }
        }
    }
}

void extractOperators(const string& line, unordered_set<string>& operators) {
    if (line.find('=') != string::npos) {
        operators.insert("assignment");
    }
    if (line.find('+') != string::npos) {
        operators.insert("addition");
    }
    if (line.find('-') != string::npos) {
        operators.insert("subtraction");
    }
    if (line.find('*') != string::npos) {
        operators.insert("multiplication");
    }
    if (line.find('/') != string::npos) {
        operators.insert("division");
    }
}

int main() {
    ifstream inputFile("program_read.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    unordered_set<string> functionNames;
    unordered_set<string> operators;

    string line;
    while (getline(inputFile, line)) {
        extractFunctionNames(line, functionNames);
        extractOperators(line, operators);
    }

    inputFile.close();


    cout << " Functions:" << endl;
    int functionCount = 0;
    for (const auto& functionName : functionNames) {
        cout << "Function-" << ++functionCount << ": " << functionName << endl;
    }
    cout << "Total number of user-defined functions: " << functionCount-1 << endl;


    cout << "\nOperators:" << endl;
    int operatorCount = 0;
    for (const auto& op : operators) {
        cout << "Operator-" << ++operatorCount << ": " << op << endl;
    }
    cout << "Total number of operators: " << operatorCount << endl;

    return 0;
}
