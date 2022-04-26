# Guidelines

My personal C coding guidelines for maintaining consistency across projects.
Code style guide is built on top of the norminette style rules.

## Project

### Project structure

```txt
build/                              - Temporary build files
    obj/                            - Object files
lib/                                - Libraries
    %library_name%/
include/%project_name%/             - Public header files
include-internal/%project_name%/    - Private (internal) header files
src/                                - Source files
Makefile
%project_name%.a
%project_name%
```

## Code style

### Header files

Header files should be placed in a separate directory called `include`.
In library projects, internal headers should be placed in a separate `include-internal` directory, so they won't get into default include path.

It's also recommended to create a diectory with the name of your project inside `include` and put all your headers in it. This will clearly indicate which headers belong to the project.

Example: `include/project-name/my_header.h`

### Source files

Each source file should contain only 1 function or
several closely related functions and/or helpers (preferably declared as static).
The name of the file should be the same as that of the function it declares.

### Includes

Formatting:

Includes should use angle brackets `<>` instead of double quotes.
A proper include path (`-I`) should be configured to make this possible.

Ordering:

```cpp
// 1. Definition includes
#include <myFuncDefinition.h> // If this is myFunc.c

// 2. System includes
#include <stdlib.h>
#include <unistd.h>

// 3. Library includes
#include <mlx.h>

// 4. Project includes
#include <myproject/myheader.h>
```

### Naming convention

1. Defines, compile-time constants, enum members: `UPPER_CASE`  
  Everything else: `snake_case`  

1. Public API:  
    `[namespace_][entity_]function`  
    Private API:  
    `_[namespace_][entity_]function`  
    Static functions:  
    `_[entity_]function`

   `[something]` means that `something` is optional.  
    An `entity` is the main type the function operates on, like `list_add` or `mutex_lock`.  

    The `namespace` is mandatory for library projects.

1. Function names should be verbs:

    ❌Wrong            | ✔️Right
    --------           | --------
    `initialization()` | `initialize()`
    `new_something()`  | `create_something()`

1. Entity constructor naming:  

    ```c
    // Create an entity and return by value
    t_entity entity_create(...);
    // Allocate an entity and return by pointer 
    t_entity *entity_alloc(...);
    // Initialize an existing entity
    void entity_init(t_entity *instance, ...);
    ```

1. Entity destructor naming:

    ```c
    // Deinitialize (free, etc.) entity's resources, but not the entity itself
    void entity_destroy(t_entity *instance);
    // Deinitialize entity's resources and the entity itself
    void *entity_free(t_entity *instance);
    ```

1. Function definition formatting:

    ```c
    void
    do_something(int a, int b);

    char
    *do_something_else(int a, char *b);
    ```

    Function declaration formatting:

    ```c
    void
        do_something(int a, int b)
    {
    }

    char
        *do_something_else(
            int a,
            char *b
        )
    {
    }
    ```

    > This formatting style works well with the norm and generally looks nice.
