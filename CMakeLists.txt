cmake_minimum_required(VERSION 3.0)
project(TMP)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

# 设置可执行文件和库的输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# 添加 src 目录下的源文件以创建库
set(LIB_SRC
    src/task.cc
    src/fpga.cc
    )
add_library(TMP SHARED ${LIB_SRC})

set(LIBS
    TMP
    )
# 添加 tests 目录下的测试可执行文件 添加依赖关系和链接库
add_executable(test_task tests/test_task.cc)
add_dependencies(test_task TMP)
target_link_libraries(test_task TMP)

add_executable(test_fpga tests/test_fpga.cc)
add_dependencies(test_fpga TMP)
target_link_libraries(test_fpga TMP)
