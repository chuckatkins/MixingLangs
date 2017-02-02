cmake_minimum_required(VERSION 3.3)

project(TestLib C CXX Fortran)

set(CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)

add_library(TestLib
  TestLib.h         TestLib.cxx
  TestLib_C.h       TestLib_C.cxx
  TestLib_Fortran.h TestLib_Fortran.cxx
  testlib_mod.f90
)

add_executable(TestMain_CXX TestMain.cxx)
target_link_libraries(TestMain_CXX TestLib)

add_executable(TestMain_C TestMain.c)
target_link_libraries(TestMain_C TestLib)

add_executable(TestMain_Fortran TestMain.f90)
target_link_libraries(TestMain_Fortran TestLib)
