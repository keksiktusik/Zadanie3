cmake_minimum_required(VERSION 3.10)
project(MergeSortTestProject)

# Ustawienie wersji standardu C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Dodaj katalog googletest jako podprojekt i wyłącz niektóre opcje
option(gtest_force_shared_crt ON)
option(BUILD_GMOCK OFF)
option(INSTALL_GTEST OFF)
add_subdirectory(googletest)

# Dodanie pliku z testami jednostkowymi
# Zmień nazwę celu, aby uniknąć konfliktu nazw
add_executable(MergeSortTestsApp MergeSortTest.cpp MergeSort.h)

# Linkowanie bibliotek Google Test do testów
target_link_libraries(MergeSortTestsApp gtest gtest_main)

# Konfiguracja testów
enable_testing()
add_test(NAME MergeSortTests COMMAND MergeSortTestsApp)