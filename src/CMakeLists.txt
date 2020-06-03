find_package(LLVM REQUIRED CONFIG)
include_directories(.)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

if(APPLE)
    include_directories(/usr/local/opt/llvm/include)
    string(APPEND CMAKE_CXX_FLAGS " -Wno-c++11-narrowing")
ENDIF(APPLE)

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(ast AST_SOURCE)
aux_source_directory(generator GEN_SOURCE)
aux_source_directory(vis VIS_SOURCE)

add_custom_command(
        OUTPUT pascal.l.cpp
        COMMAND lex -o pascal.l.cpp ${CMAKE_CURRENT_LIST_DIR}/lexer/pascal.l
        DEPENDS ${CMAKE_CURRENT_LIST_DIR}/lexer/pascal.l pascal.y.cpp
)

add_custom_command(
        OUTPUT pascal.y.hpp pascal.y.cpp
        COMMAND yacc -d -o pascal.y.cpp ${CMAKE_CURRENT_LIST_DIR}/parser/pascal.y
        DEPENDS ${CMAKE_CURRENT_LIST_DIR}/parser/pascal.y
)

llvm_map_components_to_libnames(LLVM_LINK_LIBRARIES core)

add_executable(
        opc
        main.cpp ${AST_SOURCE} ${GEN_SOURCE} ${VIS_SOURCE} pascal.l.cpp
        pascal.y.cpp pascal.y.hpp
        type/type.cpp)

set_target_properties(opc PROPERTIES LINK_LIBRARIES "${LLVM_LINK_LIBRARIES}")