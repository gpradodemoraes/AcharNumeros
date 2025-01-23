#!/bin/bash

test ! -d mybuild && mkdir mybuild

cd mybuild

cmake -DCMAKE_BUILD_TYPE=Debug .. && cmake --build .

