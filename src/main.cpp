#include <iostream>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "pascal.y.h"
#include "ast/graph_generator.h"
using namespace std;
string input_fname;

int main(int argc, char *argv[]) {
    parse_arg(argc - 1, argv + 1);
    if (!input_fname.substr(input_fname.length() - 4, 4).equal(".pas")) {
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
        cerr << "cannot dup file into stdin "<<input_fname << endl; 
    }
    struct stat file_stat;
    stat(input_fname.c_str(), &file_stat);
    if (!S_ISREG(file_stat.st_mode)) {
        std::cerr << filename << " is not a regular file" << std::endl;
        return 1;
    }

    if (yyparse() != 0) {
        return 1;
    }

    GraphGenerator *g = new GraphGenerator();
    ast_root->Print(g);
    g->Save(input_fname + ".dot");
    delete g;

    return 0;
}