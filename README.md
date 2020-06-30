# Our-Pascal-Compiler
A course project of ZJU Compile Principle.

## Developer
* (C) Shibiao Jiang 
* (C) Yangyi Huang  
* (C) Yuhan Wang    

## Timeline
* 2020/05/19: Finish Lex
* 2020/05/20: Finish Infrastructure of Yacc and AST
* 2020/05/23: Finish AST, Successfully use graphviz to generate the AST
* 2020/05/30: Finish coding of Backend using LLVM
* 2020/05/30: Finish Compile and Make, with a lot of bugs
* 2020/05/31: Have ALMOST NO BUGS and achieve all features included by the grammar, but not limited to it.

## Dependencies

+   **gcc**
+   **llvm** >= 6.0
+   Please use **cmake** to build this project.

## Usage 

+   `./opc <filename>.pas `: Generate IR code from `<filename>.pas` to `<filename>.pas.ll`.
+   `lli <filename>`: Generate an executable file from IR code `<filename>`.

## Report

[Click here](https://github.com/huangyangyi/Our-Pascal-Compiler/blob/master/src/Our_Pascal_Compiler_Report.pdf)