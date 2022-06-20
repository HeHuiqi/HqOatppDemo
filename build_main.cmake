
# 编译main.cpp为可执行文件
add_executable(main main.cpp)
# 设置main编译目标属性
set_target_properties(main PROPERTIES
        CXX_STANDARD 11 # -std=c++11
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED ON #-stdlib=libc++
)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries (main oatpp)