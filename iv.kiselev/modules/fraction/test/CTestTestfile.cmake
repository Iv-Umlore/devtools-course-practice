# CMake generated Testfile for 
# Source directory: D:/PROGRAMS/devtools-course-practice/modules/fraction/test
# Build directory: D:/PROGRAMS/devtools-course-practice/iv.kiselev/modules/fraction/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(fraction_gtest "D:/PROGRAMS/devtools-course-practice/iv.kiselev/bin/test_fraction.exe")
  set_tests_properties(fraction_gtest PROPERTIES  LABELS "fraction")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(fraction_gtest "D:/PROGRAMS/devtools-course-practice/iv.kiselev/bin/test_fraction.exe")
  set_tests_properties(fraction_gtest PROPERTIES  LABELS "fraction")
else()
  add_test(fraction_gtest NOT_AVAILABLE)
endif()
