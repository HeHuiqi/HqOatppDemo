# oattp 本地编译demo 

## 编译环境
```
MacOS 12.4
Xcode 13.1
cmake 3.21.1
Make 3.81

```

## 安装必要的软件
```
Xcode
brew install cmake
brew install make

```

## 编译和运行
```
mkdir build && cd build
# 配置make
cmake .. 或 ccmake .. # 交互式配置可选项的开关
# 编译和安装，导出头文件和静态库
make install
# 对main.cpp 自动编译
sh run.sh

```
