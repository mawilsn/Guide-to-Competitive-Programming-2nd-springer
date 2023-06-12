#include <bits/stdc++.h>

using namespace std;

int main(){
 // Redirecting input.txt to standard input
    FILE* inputFile = freopen("input.txt", "r", stdin);
    if (inputFile == nullptr) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }

    // Redirecting output.txt to standard output
    FILE* outputFile = freopen("output.txt", "w", stdout);
    if (outputFile == nullptr) {
        std::cerr << "Failed to open output.txt" << std::endl;
        return 1;
    }

    // Your program logic goes here
    // Read from standard input using std::cin
    // Write to standard output using std::cout

    int num1, num2;
    std::cin >> num1 >> num2;
    std::cout << "Sum: " << num1 + num2 << std::endl;

    // Closing the file streams
    fclose(stdin);
    fclose(stdout);

    return 0;

}