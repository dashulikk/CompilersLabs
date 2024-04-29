```bash
cd /workspaces/CompilersLab1/Lab1/dragon-tiger/src/driver
unzip dtiger.zip
cd ..
cd ..
cd ..
dragon-tiger/src/driver/dtiger -o test.o test.tig
clang++ test.o dragon-tiger/src/runtime/posix/libruntime.a -o test
./test
```