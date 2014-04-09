import os
import sys

def build(dir, **d):
    env = Environment(**d)
    SConscript('src/SConscript', variant_dir=dir, exports='env')

for version in ['long', 'short']:
    cppdefines=[]
    if version == 'long':
        cppdefines.append('ELEMENT_LONG')
    build('build-gcc-' + version,
        CXX='g++-4.8',
        CXXFLAGS='-std=c++11 -O3 -Werror -Wall -Wextra -Wold-style-cast -Woverloaded-virtual -Wsign-promo -Wdouble-promotion -Wconversion -Wsign-conversion -Wmissing-declarations -Wredundant-decls -Wno-unused-parameter -Wno-unused-function -Wno-unused-variable',
        CPPDEFINES=cppdefines,
    )
    build('build-clang-' + version,
        CXX='xcrun clang++',
        CXXFLAGS='-std=c++11 -march=native -O3 -Weverything -Werror -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-unused-parameter -Wno-unused-function -Wno-unused-variable',
        CPPDEFINES=cppdefines,
    )
