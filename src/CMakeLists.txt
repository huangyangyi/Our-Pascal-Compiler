include_directories(.)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(CMAKE_CXX_STANDARD 14)

aux_source_directory(ast AST_SOURCE)

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

add_executable(
    mpc
    main.cpp ${AST_SOURCE} pascal.l.cpp 
    pascal.y.cpp pascal.y.hpp
)

