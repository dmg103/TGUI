#!/bin/bash
git checkout 0.10

rm -r build/
rm -r bin/

#Build linux
mkdir build
mkdir bin
cd build
cmake .. -DTGUI_BACKEND=GLFW_OPENGL3 -DTGUI_SHARED_LIBS=FALSE
make -j4
cd ..
mv ./build/lib/libtgui-s.a ./build/lib/libtgui-sLinux.a
cp -r ./build/lib/libtgui-sLinux.a ./bin/

rm -r build/

#Build windows
mkdir build
cd build
cmake CMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ .. -DTGUI_BACKEND=GLFW_OPENGL3 -DTGUI_SHARED_LIBS=FALSE
make -j4
cd ..
mv ./build/lib/libtgui-s.a ./build/lib/libtgui-sWin.a
cp -r ./build/lib/libtgui-sWin.a ./bin/