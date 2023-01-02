cmake_minimum_required(VERSION 3.5)

project(michauowy-build-system LANGUAGES C)

add_executable(michauowy-build-system
    main.c BuildFile.c
    Parser.h BuildFile.h)

install(TARGETS michauowy-build-system
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
