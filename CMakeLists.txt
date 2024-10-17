project(File_Explorer)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
add_executable(${PROJECT_NAME} src/find.c src/main.c)
