
if [ -f main ]; then
    rm -rf main
fi
# -I 指定头文件目录
# 直接使用oatpp源码中的头文件
c++ -std=c++17 -I . ./lib/liboatpp.a main.cpp -o main


# 使用编译安装后的在include文件中的头文件
# c++ -std=c++11 -I ./include ./lib/liboatpp.a main.cpp -o main

./main

