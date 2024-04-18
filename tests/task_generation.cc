#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;
std::tuple<int, int, int> processLineData(const std::string &line) {
    std::istringstream iss(line);
    int data1, data2, data3;
    if (iss >> data1 >> data2 >> data3) {
        return std::make_tuple(data1, data2, data3);
    } else {
        std::cerr << "无法解析行数据: " << line << std::endl;
        return std::make_tuple(0, 0, 0); // 返回默认值
    }
}

void readFileLineByLine(const std::string &filename) {
    std::ifstream inputFile(filename);
    if (inputFile.is_open()) {
        std::string line;
        vector<string> vec;
        while (std::getline(inputFile, line)) {
            tuple<int, int, int> task = processLineData(line);
        }
        inputFile.close();
    } else {
        std::cerr << "Can't open file: '" << filename << std::endl;
    }
}

int main() {
    readFileLineByLine("input/task_resources_requirements.txt");

    return 0;
}
