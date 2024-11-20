#!/bin/bash

# 编译 C++ 程序
# g++ -o std_exec std.cpp
clang++ -o main_exec main.cpp -std=c++20
# if [ ! -f std_exec ] || [ ! -f main_exec ]; then
#     echo "Compilation failed!"
#     exit 1
# fi
# 运行次数
ITERATIONS=15

# 计数器
count=1

# 生成测试数据并进行对拍
while [ $count -lt $ITERATIONS ]; do
    # 生成随机测试数据
    python3 generator.py > "$count.in"
    # 运行标准程序和待测程序
    ./main_exec < "$count.in" > "$count.out"
    count=$((count + 1))  # 增加计数
done

# 删除生成的可执行文件和临时文件
rm main_exec

