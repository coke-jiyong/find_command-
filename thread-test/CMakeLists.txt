project(fsearch)


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

find_package(Threads REQUIRED)
 
add_executable(${PROJECT_NAME} src/find.c src/main.c src/thpool.c)
target_link_libraries(${PROJECT_NAME} "${CMAKE_THREAD_LIBS_INIT}")

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION /usr/local/bin)
