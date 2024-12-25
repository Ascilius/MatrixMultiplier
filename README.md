# Matrix Multiplier
**2024-12-25**

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
The shell files also compile the program automatically before running.

### Usage
Multiplying m by n matrix A and o by p matrix B, input their dimensions and elements into ```inputs.txt``` the format below:
```
m n
A_11 A_12 A_13 ... A_1n
A_21 A_22 A_23 ... A_2n
A_31 A_32 A_33 ... A_3n
...  ...  ...  ... ...
A_m1 A_m2 A_m3 ... A_mn
o p
B_11 B_12 B_13 ... B_1p
B_21 B_22 B_23 ... B_2p
B_31 B_32 B_33 ... B_3p
...  ...  ...  ... ...
B_o1 B_o2 B_o3 ... B_op
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
IMPORTANT: When editing ```inputs.txt```, or any input file for the program, make sure to use **UNIX line endings**.

When finished, run ```bash run.sh```. You can run ```test.sh``` to run some pre-made test inputs for the program.

If you have another input file, you can use it with the program through the following usage:

```build/mm [input filename] [debug mode (0|1)]```

Enjoy!

### To Do
- implement external linear algebra library to check calculations 
- parallelism
- improve IO (GUI?)