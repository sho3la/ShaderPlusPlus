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
	include/MainWindow.h
	include/Openglwidget.h
	include/SyntaxStyle.h
	include/StyleSyntaxHighlighter.h
	include/Language.h
	include/HighlightRule.h
	include/HighlightBlockRule.h
	include/GLSLHighlighter.h
	include/GLSLCompleter.h
	include/LineNumberArea.h
	include/CodeEditor.h
)

# list the source files
set(SOURCE_FILES
	src/main.cpp
	src/MainWindow.cpp
	src/Openglwidget.cpp
	src/SyntaxStyle.cpp
	src/StyleSyntaxHighlighter.cpp
	src/Language.cpp
	src/GLSLHighlighter.cpp
	src/GLSLCompleter.cpp
	src/LineNumberArea.cpp
	src/CodeEditor.cpp
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
	glew
)

# list include directories
target_include_directories(Shader++
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/include
)