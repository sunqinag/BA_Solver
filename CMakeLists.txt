cmake_minimum_required(VERSION 3.5.0)
project(BA_Solver VERSION 0.1.0 LANGUAGES C)

include_directories("include")
# add_executable(BA_Solver main.c src/Matrix.c src/Vertex.c)
add_executable(test test/test.c src/Matrix.c src/Vertex.c)
add_executable(matrix_test test/testMatrix.c src/Matrix.c)


