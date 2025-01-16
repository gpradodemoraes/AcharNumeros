#!/bin/bash

test ! -d BUILD && mkdir BUILD

cd BUILD

cmake .. && cmake --build .

