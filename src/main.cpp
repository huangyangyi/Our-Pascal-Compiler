#include <iostream>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <getopt.h>
#include <sys/stat.h>
#include "pascal.y.hpp"
#include "ast/graph_generator.h"
#include "generator/generator.h"

using namespace std;
string input_fname = "";
string output_dot_fname = "";
string output_ll_fname = "";
bool gen_graph = false;
bool gen_ir = true;

void parse_arg(int argc, char *argv[]) {
    for (int i=0;i < argc;i++) {
        string arg = argv[i];
        if (arg == "--ir") {
            gen_ir = true;
            if (i < argc - 1) {
                string nxt_arg = argv[i + 1];
                if (nxt_arg[0] != '-') {
                    output_ll_fname = nxt_arg;
                    i++;
                }
            }
        } else
        if (arg == "--noir") {
            gen_ir = false;
        } else
        if (arg == "--graph") {
            gen_graph = true;
            if (i < argc - 1) {
                string nxt_arg = argv[i + 1];
                if (nxt_arg[0] != '-') {
                    output_dot_fname = nxt_arg;
                    i++;
                }
            }
        }
        else if (input_fname == "") {
            input_fname = arg;
        }
    }
    if (argc == 0) {
        printf("Usage: opc input_file [--ir [ir_fname]] [--noir] [--graph [graph_fname]] \n");
    }
}

int main(int argc, char *argv[]) {
    parse_arg(argc - 1, argv + 1);
    //input_fname = "array_assign.pas";
    //input_fname = "func.pas";
    if (input_fname.substr(input_fname.length() - 4, 4).compare(".pas") != 0) {
        cerr << "invalid input file name: " << input_fname << std::endl
             << "please use .pas file!" << std::endl;
        return 1;
    }
    int fd = open(input_fname.c_str(), O_RDONLY);
    if (fd < 0) {
        cerr << "cannot open file " << input_fname << endl;
        return 1;
    }
    if (dup2(fd, 0) < 0) {
        cerr << "cannot dup file into stdin " << input_fname << endl;
    }
    struct stat file_stat;
    stat(input_fname.c_str(), &file_stat);
    if (!S_ISREG(file_stat.st_mode)) {
        std::cerr << input_fname << " is not a regular file" << std::endl;
        return 1;
    }
    std::cout << "parsing..." << endl;

    if (yyparse() != 0) {
        std:
        cerr << "failed to parse this code!" << std::endl;
        return 1;
    }
    std::cout << "parsed!" << endl;
    if (gen_graph) {
        GraphGenerator *g = new GraphGenerator();

        ast_root->Print(g);
        if (output_dot_fname == "") output_dot_fname = input_fname + ".dot";
        g->Save(output_dot_fname);
    }
    if (gen_ir) {
        Generator *gen = new Generator();
        std::cout << "new!" << std::endl;
        ast_root->Accept(gen);
        std::cout << "accept!" << std::endl;
        if (output_ll_fname == "") output_ll_fname = input_fname + ".ll";
        system(("rm "+output_ll_fname).c_str());
        gen->Save(output_ll_fname);
        delete gen;
    }
    return 0;
}