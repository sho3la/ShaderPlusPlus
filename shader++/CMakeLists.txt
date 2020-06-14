cmake_minimum_required(VERSION 3.9)

project(Shader++)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC On)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core    CONFIG REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Gui     CONFIG REQUIRED)

# list the header files
set(HEADER_FILES
	include/MainWindow.hpp
	include/Openglwidget.h
	include/QHighlightRule.hpp
    include/QHighlightBlockRule.hpp
    include/QCodeEditor.hpp
    include/QLineNumberArea.hpp
	include/QFunctionsArea.hpp
    include/QStyleSyntaxHighlighter.hpp
    include/QSyntaxStyle.hpp
    include/QGLSLCompleter.hpp
    include/QGLSLHighlighter.hpp
    include/QLanguage.hpp
)

# list the source files
set(SOURCE_FILES
    src/main.cpp
    src/MainWindow.cpp
	src/Openglwidget.cpp
    src/QCodeEditor.cpp
    src/QLineNumberArea.cpp
	src/QFunctionsArea.cpp
    src/QSyntaxStyle.cpp
    src/QStyleSyntaxHighlighter.cpp
    src/QGLSLCompleter.cpp
    src/QGLSLHighlighter.cpp
    src/QLanguage.cpp
)

set(RESOURCES_FILE
    resources/shaderPlusPlus_resources.qrc
)

add_executable(Shader++
    
	${HEADER_FILES}
	${SOURCE_FILES}
	${RESOURCES_FILE}
)

target_link_libraries(Shader++
    Qt5::Core
    Qt5::Widgets
    Qt5::Gui
	opengl32
	glew32
)

add_custom_command(
	TARGET Shader++ POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy 
	${CMAKE_CURRENT_SOURCE_DIR}/resources/glew/glew32.dll
	$<TARGET_FILE_DIR:Shader++>
)

# list include directories
target_include_directories(Shader++ PUBLIC
	include
	${CMAKE_CURRENT_SOURCE_DIR}/resources/glew
)

# list Libs directories
target_link_directories (Shader++ PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/resources/glew
)