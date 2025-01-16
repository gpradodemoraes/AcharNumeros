#!/bin/bash

test -f BUILD && mkdir BUILD

cd BUILD

cmake .. && cmake --build .

