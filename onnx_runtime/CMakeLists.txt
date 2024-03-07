cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 14)

add_executable(inference main.cpp)

# add_compile_options("-g -std=c++17")
add_compile_options("-O2 -mavx")

target_include_directories(inference PRIVATE "/opt/homebrew/Cellar/onnxruntime/1.17.1/include/" "/opt/homebrew/Cellar/google-benchmark/1.8.3/include")
target_link_libraries(inference PRIVATE "/opt/homebrew/Cellar/onnxruntime/1.17.1/lib/libonnxruntime.dylib"  "/opt/homebrew/Cellar/google-benchmark/1.8.3/lib/libbenchmark.a" "/opt/homebrew/Cellar/gperftools/2.15/lib/libprofiler.dylib")