cmake_minimum_required(VERSION 3.0)
project(eigen_benchmarks)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Ofast -march=native -mtune=native -mavx2 -mfma")


find_package(benchmark REQUIRED)
find_package(Eigen3 REQUIRED)

include_directories(${EIGEN_INCLUDE_DIR})

add_executable(example1 src/example1.cpp)
target_link_libraries(example1
        benchmark
        Eigen3::Eigen
        pthread)

add_executable(example2 src/example2.cpp)
target_link_libraries(example2
        benchmark
        Eigen3::Eigen
        pthread)

add_executable(example3 src/example3.cpp)
target_link_libraries(example3
        benchmark
        Eigen3::Eigen
        pthread)

add_executable(example4 src/example4.cpp)
target_link_libraries(example4
        benchmark
        Eigen3::Eigen
        pthread)

add_executable(example5 src/example5.cpp)
target_link_libraries(example5
        benchmark
        Eigen3::Eigen
        pthread)

add_executable(example6 src/example6.cpp)
target_link_libraries(example6
        benchmark
        Eigen3::Eigen
        pthread)

add_executable(example7 src/example7.cpp)
target_link_libraries(example7
        benchmark
        Eigen3::Eigen
        pthread)