# Detailed Routing for Photonic Integrated Circuits (PICs)

**Algorithm**：Dijkstra (modified ver.)
**Programming Language**： C++
**Compiler**：　Linux GNU g++

**File compression**：

```bash
tar zcvf pa2_picRouting.tar.gz pa2_picRouting
```

**File description**：

1. pa2_picRouting/header：　A directory saving all header files which are imported by `pa2_picRouting/main.cpp`.

2. pa2_picRouting/lib：　Ａ directory saving all necessary .cpp files which define functions used in `pa2_picRouting/main.cpp`.
    - pa2_picRouting/lib/Dijkstra.cpp：Include functions related to modified Dijkstra's algorithm.
    - pa2_picRouting/lib/utils.cpp：Include some tools to help achieve the algorithm.

3. pa2_picRouting/doc：It saves all related document about this project.  
    - pa2_picRouting/doc/Discription.docx：This document shows the idea about handling this project including how did I solve this project, the data structure I use, the problems needed to conquer in future.

4. pa2_picRouting/main.cpp：The main function of this algorithm.

5. pa2_picRouting/Makefile：The file shows how commmand, *make*, work.

**Compile**：
    Stay at`pa2_picRouting` and execute bellow command to compile files：

```bash
make  
```

**Execution**：
After compilation, there is a executable, `main`, in `pa2_picRouting`. Stay at `pa2_picRouting` and execute the executable with below format：

```bash
./main [input_file] [output_file]
```

e.g.  

```bash
./main ./Data_in/pic5x5.in ./Data_out/pic5x5.out
```
