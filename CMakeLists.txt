# CMake entry point
cmake_minimum_required (VERSION 3.0)
project (Tutorials)

find_package(OpenGL REQUIRED)


if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
    message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like bin_Visual2012_64bits/)" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()



# Compile external dependencies
add_subdirectory (external)

# On Visual 2005 and above, this module can set the debug working directory
cmake_policy(SET CMP0026 OLD)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/external/rpavlik-cmake-modules-fe2273")
include(CreateLaunchers)
include(MSVCMultipleProcessCompile) # /MP

if(INCLUDE_DISTRIB)
	add_subdirectory(distrib)
endif(INCLUDE_DISTRIB)



include_directories(
	external/AntTweakBar-1.16/include/
	external/glfw-3.1.2/include/GLFW/
	external/glm-0.9.7.1/
	external/glew-1.13.0/include/
	external/assimp-3.0.1270/include/
	external/bullet-2.81-rev2613/src/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_1130
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# Exercise 01
add_executable(ex01
	ex01src/ex01.cpp
)
target_link_libraries(ex01
	${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(ex01 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ex01src/")
create_target_launcher(ex01 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/ex01src/")

# Exercise 02
add_executable(ex02
        ex02src/ex02.cpp
        common/shader.cpp
        common/shader.hpp

        ex02src/SimpleVertexShader.vs
        ex02src/SimpleFragmentShader.fs
)
target_link_libraries(ex02
        ${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(ex02 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ex02src/")
create_target_launcher(ex02 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/ex02src/")

# Exercise 03
add_executable(ex03
        ex03src/ex03.cpp
        common/shader.cpp
        common/shader.hpp

        ex03src/SimpleTransform.vs
        ex03src/SingleColor.fs
)
target_link_libraries(ex03
        ${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(ex03 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ex03src/")
create_target_launcher(ex03 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/ex03src/")

# Exercise 04
add_executable(ex04
        ex04src/ex04.cpp
        common/shader.cpp
        common/shader.hpp

        ex04src/TransformVertexShader.vs
        ex04src/ColorFragmentShader.fs
)
target_link_libraries(ex04
        ${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(ex04 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ex04src/")
create_target_launcher(ex04 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/ex04src/")

# Exercise 05
add_executable(ex05
        ex05src/ex05.cpp
        common/shader.cpp
        common/shader.hpp
        common/texture.cpp
        common/texture.hpp

        ex05src/TransformVertexShader.vs
        ex05src/TextureFragmentShader.fs
)
target_link_libraries(ex05
        ${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(ex05 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ex05src/")
create_target_launcher(ex05 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/ex05src/")

# Exercise 06
add_executable(ex06
        ex06src/ex06.cpp
        common/shader.cpp
        common/shader.hpp
        common/controls.cpp
        common/controls.hpp
        common/texture.cpp
        common/texture.hpp
        common/objloader.cpp
        common/objloader.hpp

        ex06src/StandardShading.vs
        ex06src/StandardShading.fs
)
target_link_libraries(ex06
        ${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(ex06 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ex06src/")
create_target_launcher(ex06 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/ex06src/")

# Exercise 07
add_executable(ex07
        ex07src/ex07.cpp
        common/shader.cpp
        common/shader.hpp
        common/controls.cpp
        common/controls.hpp
        common/texture.cpp
        common/texture.hpp
        common/objloader.cpp
        common/objloader.hpp
        common/vboindexer.cpp
        common/vboindexer.hpp
        common/text2D.hpp
        common/text2D.cpp
        common/tangentspace.hpp
        common/tangentspace.cpp
#
        ex07src/NormalMapping.vs
        ex07src/NormalMapping.fs
)
target_link_libraries(ex07
        ${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(ex07 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ex07src/")
create_target_launcher(ex07 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/ex07src/")

# Exercise 08
add_executable(ex08
        ex08src/ex08.cpp
        common/shader.cpp
        common/shader.hpp
        common/controls.cpp
        common/controls.hpp
        common/texture.cpp
        common/texture.hpp
        common/objloader.cpp
        common/objloader.hpp
        common/vboindexer.cpp
        common/vboindexer.hpp

        ex08src/ShadowMapping.vs
        ex08src/ShadowMapping.fs
        ex08src/DepthRTT.vs
        ex08src/DepthRTT.fs
#        ex08src/Passthrough.vs
#        ex08src/SimpleTexture.fs
)
target_link_libraries(ex08
        ${ALL_LIBS}
)
# Xcode and Visual working directories
set_target_properties(ex08 PROPERTIES XCODE_ATTRIBUTE_CONFIGURATION_BUILD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ex08src/")
create_target_launcher(ex08 WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/ex08src/")

SOURCE_GROUP(common REGULAR_EXPRESSION ".*/common/.*" )
SOURCE_GROUP(shaders REGULAR_EXPRESSION ".*/.*shader$" )
