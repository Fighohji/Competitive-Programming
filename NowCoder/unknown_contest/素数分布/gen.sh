#!/bin/zsh

# 检查是否传递了足够的参数
if [ "$#" -ne 2 ]; then
    echo "Usage: $0 l r"
    echo "l: the starting number of test cases"
    echo "r: the ending number of test cases"
    exit 1
fi

# 获取参数 l 和 r
l=$1
r=$2

# 编译 C++ 程序
g++ -o main main.cpp -std=c++20

# 检查编译是否成功
if [ ! -f main ]; then
    echo "Compilation failed!"
    exit 1
fi

# 生成测试数据并进行对拍
for (( count=$l; count<=$r; count++ )); do
    # 生成随机测试数据
    # python3 generator.py > "$count.in"
    
    # 运行待测程序并保存输出
    ./main < "$count.in" > "$count.out"

    echo "Generated test case $count: $count.in -> $count.out"
done
