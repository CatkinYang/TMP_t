#pragma once
#include "fpga.h"
#include "task.h"
#include <memory>
#include <string>
// input
// 1. TaskSet
// 2. FpgaSet
// 3.
// output
namespace TMP {

class shape {
  public:
    using ptr = std::shared_ptr<shape>;

  private:
    std::string m_t_name;
    int m_width;
    int m_height;
};

class shapeSet {};

} // namespace TMP
