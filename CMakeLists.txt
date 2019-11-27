cmake_minimum_required(VERSION 3.5)
project(EmbedResource)

# specify that this binary is to be built with C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

function(embed_resource out_var)
    set(in_f ${ARGN})
    set(result "${PROJECT_SOURCE_DIR}/gen/${in_f}.h")
    file(RELATIVE_PATH src_f ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/${in_f})

    add_custom_command(OUTPUT ${result}
            COMMAND embed-resource ${result} ${src_f}
            DEPENDS ${in_f}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            COMMENT "Building binary file for embedding ${result}")

    set(${out_var} "${result}" PARENT_SCOPE)
endfunction()

add_executable(embed-resource embedresource.cpp)

set(EMBED_RES_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
