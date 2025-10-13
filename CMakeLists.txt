cmake_minimum_required(VERSION 4.0)
project(EjerciciosColaborativos2)

set(CMAKE_CXX_STANDARD 23)

add_executable(EjerciciosColaborativos2 main.cpp
        include/Exercise1_StudentManagement.h
        include/Exercise2_BackpackGame.h
        include/Exercise3_AdvancedCalculator.h
        include/Exercise4_UserSystem.h
        src/Exercise1_StudentManagement.cpp
        src/Exercise2_BackpackGame.cpp
        src/Exercise3_AdvancedCalculator.cpp
        src/Exercise4_UserSystem.cpp
        include/StaticList.h)
