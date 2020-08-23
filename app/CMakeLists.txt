# cmake_minimum_required(VERSION 3.1)

# project(app_project LANGUAGES CXX)
# set(SOURCE_EXE main.cpp s
# add_subdirectory(src)
# include_directories(../3dparty/SFML/include/SFML/)

# add_compile_options(
#         -std=c++17
#         -Werror
#         -Wall
#         -Wextra
#         -Wpedantic
#         -Wno-unused-parameter
# )

# add_executable(MyProject main.cpp)
# target_link_libraries (MyProject sfml-graphics sfml-window sfml-system)
# # add_executable(race00 ${SOURCE_EXE})
# # target_link_libraries(race00 src)


cmake_minimum_required(VERSION 3.1)
project(race00 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(SOURCE_EXE main.cpp)
include_directories(../3dparty/SFML/include/SFML/)

add_subdirectory(src)
# include_directories(../3dparty/sfml/include/)
add_compile_options(
        -std=c++17
        # -Werror
        -Wall
        # -Wextra
        -Wpedantic
        -Wno-unused-parameter
)
add_executable(race00 ${SOURCE_EXE})
target_link_libraries(race00 sfml-graphics sfml-window sfml-system src)
include_directories(race00 ${SFML_INCLUDE_DIR})
# configure_file(resources/ArialBold.ttf ${CMAKE_CURRENT_BINARY_DIR}/ArialBold.ttf COPYONLY)
