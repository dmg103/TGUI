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
x86_64-w64-mingw32-cmake .. -DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ -DTGUI_BACKEND=GLFW_OPENGL3 -DTGUI_SHARED_LIBS=FALSE -DCMAKE_MAKE_PROGRAM=x86_64-w64-mingw32-make
make -j4
cd ..
mv ./build/lib/libtgui-s.a ./build/lib/libtgui-sWin.a
cp -r ./build/lib/libtgui-sWin.a ./bin/

#Build switch
#mkdir build
#cd build
#cmake .. -DCMAKE_CXX_COMPILER=/opt/devkitpro/devkitA64/bin/aarch64-none-elf-g++ -DTGUI_BACKEND=GLFW_OPENGL3 -DTGUI_SHARED_LIBS=FALSE -DCMAKE_MAKE_PROGRAM=/opt/devkitpro/devkitA64/bin/x86_64-w64-mingw32-make
#make -j4
#cd ..
#mv ./build/lib/libtgui-s.a ./build/lib/libtgui-sSwitch.a
#cp -r ./build/lib/libtgui-sSwitch.a ./bin/
