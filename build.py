import os

NONE = 0
VALGRIND = 1
GDB = 2

runtime_tool = GDB

build_fail = os.system(
    'cd build && cmake .. -DUFO_ENGINE_STUDIO=OFF -DSDL_X11_XTEST=OFF -DSDL_VIDEO=ON -DSDL_X11=ON -DSDL_TESTS=OFF -DCMAKE_CXX_FLAGS="-O0 -ggdb" && make -j16'
)

if build_fail:
    print("Build failed")
else:
    runtime_fail = 1

    if runtime_tool == GDB:
        runtime_fail = os.system("cd build && gdb OUT")
    if runtime_tool == NONE:
        runtime_fail = os.system("cd build && ./OUT")
    if runtime_tool == VALGRIND:
        runtime_fail = os.system("cd build && valgrind --leak-check=yes ./OUT")

    if runtime_fail:
        print("Runtime fail")
