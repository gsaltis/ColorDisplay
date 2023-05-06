@echo off
title Color Display
doskey m=make --quiet release
doskey mr=make --quiet release
doskey md=make --quiet debug
doskey mc=make cleanall
doskey co=release\colordisplay.exe
doskey db=gdb debug\colordisplay.exe
