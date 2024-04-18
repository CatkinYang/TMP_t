#include "fpga.h"

namespace TMP {

void Fpga::initFromFile(const std::string &filename) {
    std::string path = "/Users/catkin/Study/DFX/TMP/input/" + filename + ".txt";
    std::ifstream inputFile(path);
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::vector<char> row;
            std::istringstream iss(line);
            char value;
            while (iss >> value) {
                if (value == 'c')
                    m_clb++;
                else if (value == 'd')
                    m_dsp++;
                else if (value == 'b')
                    m_bram++;
                row.push_back(value);
            }
            m_graph.push_back(row);
        }
        inputFile.close();
    }
}

void Fpga::graph() {
    for (auto col : m_graph) {
        for (auto v : col) {
            std::cout << v << ' ';
        }
        std::cout << std::endl;
    }
}

void FpgaSet::addToFpgaSet(Fpga::ptr f) { m_fs.push_back(f); }

void FpgaSet::info() {
    for (auto f : m_fs) {
        std::cout << f->getName() << std::endl;
    }
}
} // namespace TMP
