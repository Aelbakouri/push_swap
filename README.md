<div align="center" id="top">
  <img src="./.github/app.gif" alt="1337_cursus" />

  &#xa0;

  <!-- <a href="https://1337_cursus.netlify.app">Demo</a> -->
</div>

<h1 align="center">
	1337_cursus' push_swap
</h1>

<p align="center">
	<b><i>Development repo for 1337_cursus' push_swap project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/Aelbakouri/1337_cursus"><b>42cursus repo</b></a>.
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/Aelbakouri/push_swap?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/Aelbakouri/push_swap?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/Aelbakouri/push_swap?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/Aelbakouri/push_swap?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/Aelbakouri/push_swap?color=brightgreen" />
</p>


<br>

## Introduction

This project comprises an interesting case study regarding sorting algorithms and its performances, being part of the core curriculum of all 42 schools worldwide. The task is simple: given a sequence of random numbers disposed in a stack data structure (**stack A**), sort them with the help of an empty auxiliary stack (**stack B**) and a set of specific stack operations. The operations allowed are described as follows, as written in our task:

- **`sa`** : **swap a** - Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements).
- **`sb`** : **swap b** - Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements).
- **`ss`** : **`sa`** and **`sb`** at the same time.
- **`pa`** : **push a** - take the first element at the top of b and put it at the top of a. Do nothing if B is empty.
- **`pb`** : **push b** - take the first element at the top of a and put it at the top of b. Do nothing if A is empty.
- **`ra`** : **rotate a** - shift up all elements of stack A by 1. The first element becomes the last one.
- **`rb`** : **rotate b** - shift up all elements of stack B by 1. The first element becomes the last one.
- **`rr`** : **`ra`** and **`rb`** at the same time.
- **`rra`** : **reverse rotate a** - shift down all elements of stack A by 1. The last element becomes the first one.
- **`rrb`** : **reverse rotate b** - shift down all elements of stack B by 1. The last element becomes the first one.
- **`rrr`** : **`rra`** and **`rrb`** at the same time.

### The Push Swap Program

The main objective of the `push_swap` is to print to `STDOUT` the instructions required to sort the **stack A**, which must be given as the program's argument. Each instruction must be followed by a line break (`\n`). The **stack A** must be sorted with its lowest element at the top, while **stack B** must be empty.

```bash
$ ARG='4 0 1 3 2'; ./push_swap $ARG

pb
pb
sa
ra
pa
pa
ra
```


### The Checker Program

To help identify if a set of instructions is valid or not, you can run the `checker` program with the same stack as the `push_swap` program. The `checker` program will then accept the sorting instructions on `STDIN`, giving us the result `OK`, if the stack was indeed sorted, or `KO` otherwise.


```bash
$ ARG='4 0 1 3 2'; ./push_swap $ARG | ./checker $ARG

OK
```

Both the `checker` or `push_swap` executables will result in an error if a stack has non-numerical arguments, a number is repeated or if a number is out of the 8-bit integer range.

---

## Compilation

You must have installed `make` and `clang` to compile this project. The execution of the `make` command will generate the binaries for both `checker` and `push_swap` and the libraries needed to the compilation.

---

## Directory Hierarchy
```shell
|—— Makefile
|—— bonus
|    |—— check_input.c
|    |—— checker_bonus.c
|    |—— operations.c
|    |—— operations2.c
|    |—— stack.c
|    |—— string_utils.c
|    |—— string_utils2.c
|    |—— utils.c
|—— inc
|    |—— push_swap.h
|    |—— push_swap_bonus.h
|—— src
|    |—— check_input.c
|    |—— main.c
|    |—— move.c
|    |—— operations.c
|    |—— operations2.c
|    |—— position.c
|    |—— sort.c
|    |—— stack.c
|    |—— string_utils.c
|    |—— utils.c
|    |—— utils2.c
```
>### Status:
     Finished 05/01/2023 grade: 125%

>### Usage: Git clone the repository and cd into it. Then use make to compile
    $ git clone git@github.com:Aelbakouri/push_swap.git ; cd push_swap
    $ make ; make bonus



## Starting ##

```bash
# Clone this project
$ git clone git@github.com:Aelbakouri/push_swap.git

# Access
$ cd push_swap

# Compilation
$ make

# Run the project
$ $ ARG='4 0 1 3 2'; ./push_swap $ARG
pb
pb
sa
ra
pa
pa
ra
```



Made with :heart: by <a href="https://github.com/Aelbakouri" target="_blank">Aelbakouri</a>

&#xa0;
<a href="#top">Back to top</a>
