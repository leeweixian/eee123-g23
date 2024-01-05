#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>  // Include the cmath header for ceil function

void getInputFromFile(const std::string& filePath, std::vector<int>& inputData) {
    std::ifstream inputFile(filePath);

    if (inputFile.is_open()) {
        int value;
        while (inputFile >> value) {
            inputData.push_back(value);
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open file '" << filePath << "'\n";
    }

    // Print input data for debugging
    std::cout << "Read " << inputData.size() << " values from file.\n";
}

void processTextData(std::vector<int>& data) {
    // Process the raw data (sort & convert) as needed
    std::sort(data.begin(), data.end());
}

void displayMatrix(const std::vector<int>& data, int rows, std::vector<int>::size_type cols) {
    std::vector<int>::size_type index = 0;
    for (int i = 0; i < rows; ++i) {
        for (std::vector<int>::size_type j = 0; j < cols; ++j) {
            if (index < data.size()) {
                std::cout << data[index++] << "\t";
            } else {
                // Handle the case where we run out of elements in the vector
                std::cout << "N/A\t";
            }
        }
        std::cout << "\n";
    }
}

void outputData(const std::string& filePath, const std::vector<int>& dataMatrix) {
    std::ofstream outputFile(filePath);

    if (outputFile.is_open()) {
        // Output matrix form
        outputFile << "Matrix Form:\n";
        for (int value : dataMatrix) {
            outputFile << value << "\t";
        }

        // Output array form
        outputFile << "\n\nArray Form:\n";
        for (int value : dataMatrix) {
            outputFile << value << " ";
        }

        outputFile.close();
    } else {
        std::cerr << "Error: Unable to open output file '" << filePath << "'\n";
    }
}

int main() {
    // Step 1: Get input from text file
    std::string inputFilePath = "sorteddata.txt";  // Replace with the correct file name or path
    std::vector<int> inputData;

    // Print file path for debugging
    std::cout << "Attempting to read from file: " << inputFilePath << "\n";

    getInputFromFile(inputFilePath, inputData);

    // Step 2: Process text data
    processTextData(inputData);

    // Step 3: Display data in matrix form
    std::vector<int>::size_type rows = 2;  // Adjust the number of rows based on your requirement
    std::vector<int>::size_type cols = static_cast<std::vector<int>::size_type>(std::ceil(static_cast<double>(inputData.size()) / static_cast<double>(rows)));
    displayMatrix(inputData, static_cast<int>(rows), cols);

    // Step 4: Output data to a new text file
    std::string outputFilePath = "output.txt";  // Replace with your desired output file path
    outputData(outputFilePath, inputData);

    return 0;
}