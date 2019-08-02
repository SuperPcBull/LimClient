cmake_minimum_required(VERSION 2.8)
project(LimClient)

#使能c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -w")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -w")

#加载自定义模块
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
#设置库文件路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
#设置可执行程序路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

#设置工程源码根目录
set(MediaKit_Root ${CMAKE_SOURCE_DIR}/../ZLMediaKit/src)
set(ToolKit_Root ${MediaKit_Root}/../3rdpart/ZLToolKit/src)
set(Json_Root ${MediaKit_Root}/../3rdpart)
set(App_Root ${CMAKE_SOURCE_DIR}/src)
set(FTAPI_SDK_Root ${CMAKE_SOURCE_DIR}/3rdpart/FTAPI4CPP)
set(FTAPI_PB_SRC_Root ${CMAKE_SOURCE_DIR}/3rdpart/FTAPI4CPP/Include/Proto)


#设置头文件目录
INCLUDE_DIRECTORIES(${ToolKit_Root})
INCLUDE_DIRECTORIES(${Json_Root})
INCLUDE_DIRECTORIES(${App_Root})
INCLUDE_DIRECTORIES(${FTAPI_SDK_Root}/Include)

if(${CMAKE_BUILD_TYPE} MATCHES "Release")
    message(STATUS "Release版本")
    set(BuildType "Release")
else()
    set(BuildType "Debug")
    message(STATUS "Debug版本")
endif()

set(BuildType "Release")

if (CMAKE_SYSTEM_NAME MATCHES "Linux")
    LINK_DIRECTORIES(${FTAPI_SDK_Root}/Bin/Centos7)
elseif (CMAKE_SYSTEM_NAME MATCHES "Windows")
    LINK_DIRECTORIES(${FTAPI_SDK_Root}/Bin/Windows/${BuildType})
elseif (CMAKE_SYSTEM_NAME MATCHES "Darwin")
    LINK_DIRECTORIES(${FTAPI_SDK_Root}/Bin/Mac/${BuildType})
endif ()


#收集源代码
file(GLOB ToolKit_src_list ${ToolKit_Root}/*/*.cpp ${ToolKit_Root}/*/*.h ${ToolKit_Root}/*/*.c)
file(GLOB Json_src_list ${Json_Root}/jsoncpp/*.cpp ${Json_Root}/jsoncpp/*.h)
file(GLOB App_src_list ${App_Root}/*/*.cpp ${App_Root}/*/*.c ${App_Root}/*/*.h ${App_Root}/*.cpp ${App_Root}/*.c ${App_Root}/*.h)
file(GLOB FTAPI_pb_src_list ${FTAPI_PB_SRC_Root}/*.cc)


#去除win32的适配代码
if (NOT WIN32)
    list(REMOVE_ITEM ToolKit_src_list ${ToolKit_Root}/win32/getopt.c)
endif ()

set(LINK_LIB_LIST pthread)

#添加库
add_library(zltoolkit_static STATIC ${ToolKit_src_list})
add_library(json_static STATIC ${Json_src_list})
add_library(FTAPI_pb_static STATIC ${FTAPI_pb_src_list})

#主程序
add_library(lim_client ${App_src_list})

target_link_libraries(
        lim_client
        app_static
        json_static
        zltoolkit_static
        ${LINK_LIB_LIST}
        pthread)



