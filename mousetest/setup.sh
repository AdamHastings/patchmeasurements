#!/bin/bash

if [[ $PATH_SET == "" ]]; then
    PATH_SET="set!"
    PATH=$PATH:/home/adam/mxe/usr/bin
    echo "PATH is $PATH"
fi

