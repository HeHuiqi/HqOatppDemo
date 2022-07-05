
if [ -f main ]; then
    rm -rf main
fi
# -I 指定优先搜索头文件目录，没有找到再从本地系统头文件目录查找 /usr/local/include，没有找到就找系统库目录了
# 直接使用oatpp源码中的头文件，这里优先从当前目录查找头文件
c++ -std=c++17 -I . ./lib/liboatpp.a main.cpp -o main


# 使用编译安装后的在include文件中的头文件
# c++ -std=c++11 -I ./include ./lib/liboatpp.a main.cpp -o main

./main

