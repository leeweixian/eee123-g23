//welcome...


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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
}

void processTextData(std::vector<int>& data) {
    // Process the raw data (sort & convert) as needed
    std::sort(data.begin(), data.end());
}

void displayMatrix(const std::vector<int>& data, int rows, int cols) {
    int index = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << data[index++] << "\t";
        }
        std::cout << "\n";
    }
}

void outputData(const std::string& filePath, const std::vector<int>& dataMatrix, const std::vector<int>& dataArray) {
    std::ofstream outputFile(filePath);

    if (outputFile.is_open()) {
        // Output matrix form
        outputFile << "Matrix Form:\n";
        for (int value : dataMatrix) {
            outputFile << value << "\t";
        }

        // Output array form
        outputFile << "\n\nArray Form:\n";
        for (int value : dataArray) {
            outputFile << value << " ";
        }

        outputFile.close();
    } else {
        std::cerr << "Error: Unable to open output file '" << filePath << "'\n";
    }
}

int main() {
    // Step 1: Get input from text file
    std::string inputFilePath = "input.txt";  // Replace with your actual file path
    std::vector<int> inputData;
    getInputFromFile(inputFilePath, inputData);

    if (!inputData.empty()) {
        // Step 2: Process text data
        processTextData(inputData);

        // Step 3: Display data in matrix form
        int rows = 2;  // Adjust the number of rows based on your requirement
        int cols = inputData.size() / rows;
        displayMatrix(inputData, rows, cols);

        // Step 4: Output data to a new text file
        std::string outputFilePath = "output.txt";  // Replace with your desired output file path
        outputData(outputFilePath, inputData, inputData);
    }

    return 0;
}
