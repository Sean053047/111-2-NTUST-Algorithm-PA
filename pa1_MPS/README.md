# Finding Maximum Planar Subset of chords a set of Νets in a channel  

## Introduction  

This repository is about the project assignment of NTUST EE Algorithm taught by Shao-Yun Fang. Aim to impliment the algorithm shown below.

**Algorithm**：_Finding a maximum planar subset of a set of nets in a channel, IEEE TCAD, 1987_
**Programming Language**： C++
**Compiler**：　Linux GNU g++
**File compression**：

```bash
tar zcvf pa1_MPS.tar.gz pa1_MPS
```

**File description**：

1. ./header：　A directory saving all header files which are imported by `pa1_MPS/main.cpp`.

2. ./lib：　Ａ directory saving all necessary .cpp files which define functions used in `pa1_MPS/main.cpp`.
    - pa1_MPS/lib/MIPS.cpp：Include functions related to MIPS algorithm.
    - pa1_MPS/lib/utils.cpp：Include functions such as, writing file, loading data, printing value of vector, creating 2D vector.

3. ./main.cpp：The main function of this algorithm.

4. ./main：The executable of this algorithm.

**Compile**：
    Stay at `pa1` and execute bellow command to compile files：

```bash
g++ -o ./main ./lib/*.cpp ./main.cpp  
```

**Execution**：
After compilation, there is a executable, `main`, in `pa1`. Stay at `pa1_MPS` and execute the executable with below format：

```bash
./main [input_file] [output_file]
```

e.g. `./main ./Data_in/12.in ./Data_out/12.out`
