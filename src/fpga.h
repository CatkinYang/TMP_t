#pragma once

#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>
namespace TMP {

class Fpga {
  public:
    using ptr = std::shared_ptr<Fpga>;
    Fpga(std::string name) {
        m_name = name;
        initFromFile(name);
    }
    void initFromFile(const std::string &filename);
    std::string getName() const { return m_name; }
    int getDsp() const { return m_dsp; }
    int getClb() const { return m_clb; }
    int getBram() const { return m_bram; }
    void graph();

  private:
    std::string m_name;
    std::vector<std::vector<char>> m_graph;
    int m_clb = 0, m_dsp = 0, m_bram = 0;
};

class FpgaSet {
  public:
    using ptr = std::shared_ptr<FpgaSet>;
    FpgaSet(){};
    void addToFpgaSet(Fpga::ptr);
    void info();

  private:
    std::vector<Fpga::ptr> m_fs;
};

} // namespace TMP
