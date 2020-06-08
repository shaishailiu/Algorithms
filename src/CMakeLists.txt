# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Algorithms)

set(ROOT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_FOLDER ${CMAKE_CURRENT_SOURCE_DIR}/*/*.*)

function(assign_source_group)
    if(MSVC)
    foreach(_source IN ITEMS ${ARGN})
        if (IS_ABSOLUTE "${_source}")
            file(RELATIVE_PATH _source_rel "${ROOT_FOLDER}" "${_source}")
        else()
            set(_source_rel "${_source}")
        endif()
        get_filename_component(_source_path "${_source_rel}" PATH)
        string(REPLACE "/" "\\" _source_path_msvc "${_source_path}")
        source_group("${_source_path_msvc}" FILES "${_source}")
    endforeach()
    endif(MSVC)
endfunction(assign_source_group)

function(group_vs)
    foreach(_source IN ITEMS ${ARGN})
        assign_source_group(${_source})
    endforeach()
endfunction(group_vs)

file(GLOB SOURCES "main.cc" ${SRC_FOLDER})

group_vs(${SOURCES})

add_executable(Algorithms ${SOURCES})
