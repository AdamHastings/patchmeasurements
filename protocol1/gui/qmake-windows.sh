#!/bin/bash

if [[ $PATH_SET == "" ]]; then
    PATH_SET="set!"
    PATH=$PATH:/home/adam/mxe/usr/bin
    echo "PATH is $PATH"
fi

~/mxe/usr/bin/i686-w64-mingw32.static-qmake-qt5
