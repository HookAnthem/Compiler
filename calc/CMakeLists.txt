cmake_minimum_required(VERSION 2.8)
project(calc)

find_package(BISON)
find_package(FLEX)
bison_target(Parser parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
flex_target(Scanner scanner.l ${CMAKE_CURRENT_BINARY_DIR}/scanner.cpp)
add_flex_bison_dependency(Scanner Parser)

set(EXTRA_COMPILE_FLAGS "-g3 -std=c++14")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EXTRA_COMPILE_FLAGS}")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}")
set(HEADER_HPP
	Global.hpp
	Expression.hpp
	ArrayType.hpp
	Operations.hpp
	RecordType.hpp
	SimpleType.hpp
	SymbolTable.hpp
	Type.hpp
	)

set(SOURCE_CPP
	Global.cpp
	Expression.cpp
	ArrayType.cpp
	Operations.cpp
	RecordType.cpp
	SimpleType.cpp
	SymbolTable.cpp
	Type.cpp
	)


set(calc_srcs
  main.cpp               
  ${HEADER_HPP}
  ${SOURCE_CPP}
  ${BISON_Parser_OUTPUTS}
  ${FLEX_Scanner_OUTPUTS}
)
source_group("Calc" FILES ${calc_srcs})

add_executable(calc ${calc_srcs})
target_link_libraries(calc ${FLEX_LIBRARIES} ${BISON_LIBRARIES})
target_include_directories(calc PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

