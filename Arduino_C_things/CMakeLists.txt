cmake_minimum_required(VERSION 3.5)
project(Arduino_C_things)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Arduino_C_things.ino
    communication.ino
    constant.ino
    grelci.ino
    logging.ino
    masa.ino
    pancake_count.ino
    trak.ino
    zvijanje.ino)

add_executable(Arduino_C_things ${SOURCE_FILES})