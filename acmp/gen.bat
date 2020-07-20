@echo off
set codegen=../code_gen/codegen.py
set num=%1
python %codegen% desc.txt %num% %num%.cpp %2 %3 %4 %5 %6 %7 %8 %9