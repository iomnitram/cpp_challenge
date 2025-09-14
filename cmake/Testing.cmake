

find_package(GTest)
if (NOT ${GTest_FOUND})
  message("GTest not found : Load via FetchContent")

  include(FetchContent)
  FetchContent_Declare(
          googletest
          GIT_REPOSITORY https://github.com/google/googletest.git
          GIT_TAG release-1.11.0
  )
  # For Windows: Prevent overriding the parent project's
  # compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  option(INSTALL_GMOCK "Install GMock" OFF)
  option(INSTALL_GTEST "Install GTest" OFF)
  FetchContent_MakeAvailable(googletest)
endif ()


include(GoogleTest)
enable_testing()

macro(AddTests target)
  target_link_libraries(${target} PRIVATE GTest::gtest_main)
  gtest_discover_tests(${target})
endmacro()
