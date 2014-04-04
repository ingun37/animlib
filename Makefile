all : animlib.so

animlib.so : animlib.o
	g++ -shared -m64 -O3 -pthread -pipe -D_BOOL -DLINUX -DREQUIRE_IOSTREAM -mtune=pentium4 -Wno-deprecated -fno-gnu-keywords -Wl -Bsymbolic -shared -o animlib.so animlib.o -L/Applications/Autodesk/maya2014/Maya.app/Contents/MacOS -lOpenMaya -lFoundation

animlib.o : animlib.cpp
	g++ -c -I mayadep -I -I/usr/X11R6/include -I /Applications/Autodesk/maya2014/devkit/include -D_BOOL -DLINUX_64 -DREQUIRE_IOSTREAM -m64 -O3 -pthread -pipe -fPIC -mtune=pentium4 -Wno-deprecated -fno-gnu-keywords animlib.cpp


