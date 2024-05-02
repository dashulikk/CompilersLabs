```bash
Lab1 is Tiger Language Introduction: https://compilation-course.github.io/introduction/lab1.html
To unzip compiler and build in codespaces:

cd /workspaces/CompilersLab1/Lab1/dragon-tiger/src/driver
unzip dtiger.zip
cd /workspaces/CompilersLab1/Lab1/dragon-tiger
dragon-tiger/src/driver/dtiger -o test.o test.tig
clang++ test.o dragon-tiger/src/runtime/posix/libruntime.a -o test
./test

Lab2 is Tiger Calculator: https://compilation-course.github.io/lexical-and-syntax-analysis/lab2.html
Build and run in codespaces:

cd /workspaces/CompilersLab1/Lab2/dragon-tiger
./configure
make
echo "a * b" | src/driver/dtiger --dump-ast - //check AST


Remember: you should never have to modify ast/nodes.hh during this lab.

```
