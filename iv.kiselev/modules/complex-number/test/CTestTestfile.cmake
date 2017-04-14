# CMake generated Testfile for 
# Source directory: D:/PROGRAMS/devtools-course-practice/modules/complex-number/test
# Build directory: D:/PROGRAMS/devtools-course-practice/iv.kiselev/modules/complex-number/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(complex-number_gtest "D:/PROGRAMS/devtools-course-practice/iv.kiselev/bin/test_complex-number.exe")
  set_tests_properties(complex-number_gtest PROPERTIES  LABELS "complex-number")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(complex-number_gtest "D:/PROGRAMS/devtools-course-practice/iv.kiselev/bin/test_complex-number.exe")
  set_tests_properties(complex-number_gtest PROPERTIES  LABELS "complex-number")
else()
  add_test(complex-number_gtest NOT_AVAILABLE)
endif()
