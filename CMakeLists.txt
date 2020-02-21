CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

ADD_EXECUTABLE(rshell
    src/main.cpp
    src/Base.cpp
    src/Command.cpp
    src/Connector.cpp
    src/Group.cpp
)

ADD_EXECUTABLE(test
    unit_tests/test.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
