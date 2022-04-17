cmake_minimum_required(VERSION 3.21)
project(template)

set(CMAKE_CXX_STANDARD 11)

add_executable(template main.cpp graph/UnionFind.cpp graph/Kruskal.cpp graph/Prim.cpp)
add_executable(743 graph/leetcodeDebug/743.cpp)
add_executable(1514 graph/leetcodeDebug/1514.cpp)
add_executable(886 graph/leetcodeDebug/886.cpp)

add_executable(split string/split.cpp)