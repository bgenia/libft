# libft

LibFT (Forty-Two) is a C library made as a school project at 42.
It started as a simple reimplementation of some basic libc functions,
but I kept expanding it after the evaluation.
This project was my main playground for exploring the C language for over a year,
and helped me greatly in writing my other projects.

In total, there are over 250 functions split into 30+ header files.
Also a log of bugs, bad decisions and unfinished ideas.

## Contents

1. [Contents](#contents)
1. [Style guide](#style-guide)
1. [Library structure](#library-structure)
1. [Installation](#installation)
1. [Compilation options](#compilation-options)
1. [Design decisions](#design-decisions)
1. [TODO](#todo)

## Style guide

LibFT fully conforms to the Norm standard of school 42.
Additional code style decisions are listed in [[Guidelines.md](Guidelines.md)].

[[Back to Top](#libft)]

## Library structure

Libft is split into different header files for different pieces of functionality.
You can include the entire library using the `ft/ft.h` header.

`ft/`

* `debug` - Debug utilities
    * `assert.h` - Assert function
* `io` - Input/Output management
    * `stream` - Generic I/O abstraction, similar to libc's FILEs
        * `stream.h` - Stream structure and stream manipulation functions
        * `stream_buffer.h` - Stream buffer management
        * `stream_utils.h` - Additional stream I/O utilities
    * `fdstream.h` - File-descriptor-based stream implementation for working with files and standard I/O
    * `input.h` - Basic input functions (`get_char`, `get_line`, ...)
    * `output.h` - Basic output functions (`put_int`, `put_float`, ...)
    * `printf.h` - Modified stream-based ft_printf project (Every version of `printf` from libc is implemented)
* `memory` - Memory management tools
    * `memory.h` - Memory allocation/deallocation functions and utils
    * `memstream.h` - Memory-based stream implementation
    * `gc.h` - Vector-based "Garbade Collector" for semi-automatic deallocation of a large number of pointers
* `string` - C string management
    * `string.h` - Functions from libc's `string.h` + some extra utils
    * `strstream.h` - String-based stream implementation
    * `format.h` - Printf for strings, libc calls it `sprintf`
    * `wstring.h` - Wide character string management (there is like 1 function because I didn't really use wstrings in 42 projects)
* `process` - Process-related utils
    * `env.h` - Env management (`getenv`, `putenv`, `setenv`, etc...)
* `terminal` - Terminal management
    * `termdefs.h` - Definitions for various terminal control sequences
    * `termutils.h` - Implementations of complex terminal control sequences
* `vector` - Dynamic array management
    * `vector.h` - A dynamic array, some kind of std::vector from c++, can be used as a list/stack/queue if needed
    * `vecstream.h` - Vector-based stream implementation
* `x` - Experimental features, these are made more as a proof of concept rather than for actual use
    * `functional.h` - Generic function pointer interface
    * `algorithm.h` - Generic fp-based algorithms
* `array.h` - Generic array utils
* `convert.h` - Type conversion, stuff like `atoi` and `itoa`
* `ctype.h` - Libc's `ctype.h` implementation
* `math.h` - Some useful math functions (from libc or not)
* `tuples.h` - Numeric tuple structures, very useful in CG projects
* `utils.h` - General-purpose utilities
* `ft.h` - Proxy header to include the entire library

[[Back to Top](#libft)]

## Installation

1. Clone this repository into your project

    ```bash
    git clone --recurse-submodules https://github.com/bgenia/libft libft
    ```

    > The `--recurse-submodules` argument is important, it is used to clone `maketools` module

1. Use make to build the library

    > It's recommended to use GNU Make v4.2.1+ to build the project. Make version is important, school macs tend to have very old make installations, which results in build failure.

    ```bash
    make -C libft
    ```

    or

    ```bash
    cd libft
    make
    ```

    > You can use `make help` to get info about possible make options, see also [[Compilation options](#compilation-options)]

1. Link to your project

    ```make
    CPPFLAGS += -Ilibft/include
    LDLIBS += libft/libft.a
    ```

[[Back to Top](#libft)]

## Compilation options

Configurable make/env variables:

* `FT_OPTIONS`

    Used to declare configuration macros (see below).

    ```make
    export FT_OPTIONS = FT_INITIAL_INPUT_CAPACITY=16 FT_MALLOC_MODE_EXIT
    ```

* `FT_OPTIMIZE`

    Used to set custom optimization settings if needed (Default is -O2).

    ```make
    export FT_OPTIMIZE = -Ofast
    ```

    > This will work even in debug build mode (`make debug`).

Configurable macros:

* `ft/vector/vector.h`

    `FT_VECTOR_DEFAULT_CAPACITY=<integer>` (Default: `8`)  

    Default vector capacity if not specified.

    `FT_VECTOR_GROWTH_FACTOR=<float>` (Default: `1.5`)  

    Capacity multiplier when vector grows.

    `FT_VECTOR_SHRINK_FACTOR=<float>` (Default: `1.5`)  

    Unused space threshold after which vector shrinks to fit (if enabled).
    Computed as `1 / FT_VECTOR_SHRINK_FACTOR`.

* `ft/io/input.h`

    `FT_INITIAL_INPUT_CAPACITY=<integer>` (Default: `8`)  

    Initial string capacity for reading functions (`get_line`, `get_all`, ...).

* `ft/io/printf.h`

    `FT_PRINTF_BUFFER_SIZE=<integer>` (Default: `1024`)  

    Heap buffer size for `ft_*printf` functions (except `xprintf`).

    `FT_XPRINTF_BUFFER_SIZE=<integer>` (Default: `512`)  

    Stack buffer size for `ft_*xprintf` functions.

* `ft/memory/memory.h`

    `FT_MALLOC_MODE*` (Default: undefined):

    Configures the behavior of `ft_malloc`. If none of these is defined works just like lib'c `malloc`.

    * `FT_MALLOC_MODE_ABORT`

        If failed, prints error message to STDERR, then calls `abort()`.

    * `FT_MALLOC_MODE_EXIT`

        If failed, prints error message to STDERR, then calls `exit(1)`.

    * `FT_MALLOC_MODE_DISABLED`

        Always returns `NULL`, intended for debugging purposes.

    `FT_MALLOC_ERROR_MESSAGE=<string>` (Default: `"Error"`)  

    Error message printed to STDERR when `ft_malloc` fails and malloc mode is set to `EXIT` or `ABORT`.

* `ft/process/env.h`

    `FT_CLEARENV_EXIT_HOOK` (Default: undefined)  

    If defined, hooks `ft_clearenv()` to `atexit()`, so you don't
    need to call it manually at the end of the program. Disabled by default
    since `atexit` is not allowed in most school 42 projects.

* `ft/debug/assert`

    `FT_ASSERT*` (Default: undefined):

    Configures the behavior of `ft_assert`. If none of the following is defined,
    prints an error message and calls `abort()` on assertion fail.

    * `FT_ASSERT_EXIT`

        Prints an error message and calls `exit(1)` on assertion fail.

    * `FT_ASSERT_WARN`

        Prints a warning message on assertion fail.

    * `FT_ASSERT_IGNORE`

        Does nothing.

[[Back to Top](#libft)]

## Design decisions

* Why not modular / split into multiple libraries?

    I don't see any reason in making this modular, libc isn't modular too after all.
    All parts are closely interconnected and depend on each other, separating them
    will require a major API change in an unfavorable way.

[[Back to Top](#libft)]

## TODO

* ~~A proper README~~
* Documentation (at least basic comments)
* Tests (given the scale of the project probably never happening)

[[Back to Top](#libft)]
