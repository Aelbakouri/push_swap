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

<p align="center">
  <a href="#dart-about">About</a> &#xa0; | &#xa0;
  <a href="#directory-hierarchy">Directory Hierarchy</a> &#xa0; | &#xa0;
  <a href="#rocket-technologies">Technologies</a> &#xa0; | &#xa0;
  <a href="#white_check_mark-requirements">Requirements</a> &#xa0; | &#xa0;
  <a href="#checkered_flag-starting">Starting</a> &#xa0; | &#xa0;
  <a href="#memo-license">License</a> &#xa0; | &#xa0;
  <a href="https://github.com/{{YOUR_GITHUB_USERNAME}}" target="_blank">Author</a>
</p>

<br>

## About ##

>### Status:
     Finished 05/01/2023 grade: 125%

>### Usage:
    Git clone the repository and cd into it. Then use make to compile
    $ git clone git@github.com:Aelbakouri/push_swap.git ; cd push_swap
    $ make ; make bonus


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

```shell
$ ARG='4 0 1 3 2'; ./push_swap $ARG

pb
pb
sa
ra
pa
pa
ra
```

## Directory Hierarchy
```
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

## :sparkles: Features ##

:heavy_check_mark: Feature 1;\
:heavy_check_mark: Feature 2;\
:heavy_check_mark: Feature 3;

## :rocket: Technologies ##

The following tools were used in this project:

- [Expo](https://expo.io/)
- [Node.js](https://nodejs.org/en/)
- [React](https://pt-br.reactjs.org/)
- [React Native](https://reactnative.dev/)
- [TypeScript](https://www.typescriptlang.org/)

## :white_check_mark: Requirements ##

Before starting :checkered_flag:, you need to have [Git](https://git-scm.com) and [Node](https://nodejs.org/en/) installed.

## :checkered_flag: Starting ##

```bash
# Clone this project
$ git clone https://github.com/{{YOUR_GITHUB_USERNAME}}/1337_cursus

# Access
$ cd 1337_cursus

# Install dependencies
$ yarn

# Run the project
$ yarn start

# The server will initialize in the <http://localhost:3000>
```

## :memo: License ##

This project is under license from MIT. For more details, see the [LICENSE](LICENSE.md) file.


Made with :heart: by <a href="https://github.com/{{YOUR_GITHUB_USERNAME}}" target="_blank">{{YOUR_NAME}}</a>

&#xa0;

<a href="#top">Back to top</a>
