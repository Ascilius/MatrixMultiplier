# Matrix Multiplier
2024-12-25

A basic tool written in C for multiplying matrices. Intended for use on WSL/Ubuntu/Linux consoles.

### Installation
From here:
```
git clone https://github.com/Ascilius/MatrixMultiplier.git
```
or download and unzip from releases.

### Compilation
Make sure your system has ```gcc``` installed. A makefile is included, so all you have to do is
```
make all
```
or
```
gcc -g -Wall -Wextra src/matrix_multiplier.c -o build/mm
```

### Usage
Multiplying matrices A and B, input their dimensions and elements into ```inputs.txt``` the format below:
```
(rows) (columns)
a11 a12 a13 ... a1n
a21 a22 a23 ... a2n
a31 a32 a33 ... a3n
... ... ... ... ...
am1 am2 am3 ... amn
(rows) (columns)
b11 b12 b13 ... b1n
b21 b22 b23 ... b2n
b31 b32 b33 ... b3n
... ... ... ... ...
bm1 bm2 bm3 ... bmn
```
For example,
```
3 3
1 2 3
4 5 6
7 8 9
3 3
1 2 3
4 5 6
7 8 9
```
IMPORTANT: When editing ```inputs.txt```, or any input file for the program, make sure to use UNIX line endings.

When finished, run ```bash run.sh```. You can run ```test.sh``` to run some pre-made test inputs for the program.

If you have another input file, you can use it with the program through the following usage:
```build/mm [input filename] [debug mode (0|1)]```

Enjoy!

### To Do
- implement external linear algebra library to check calculations 
- parallelism
- improve IO (GUI?)