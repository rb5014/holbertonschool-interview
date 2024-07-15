# Double Circular Linked List

## Project Overview

This project involves creating and manipulating a double circular linked list in C. Specifically, it focuses on adding new nodes to either the beginning or the end of the list.

## Tasks

### 0. Add Nodes

Create the source file `0-add_node.c` that contains the following functions:

#### Add a New Node to the End of a Double Circular Linked List

- **Prototype:** `List *add_node_end(List **list, char *str);`
- **Parameters:**
  - `List **list`: The list to modify.
  - `char *str`: The string to copy into the new node.
- **Returns:** The address of the new node, or `NULL` on failure.

#### Add a New Node to the Beginning of a Double Circular Linked List

- **Prototype:** `List *add_node_begin(List **list, char *str);`
- **Parameters:**
  - `List **list`: The list to modify.
  - `char *str`: The string to copy into the new node.
- **Returns:** The address of the new node, or `NULL` on failure.

## Usage

To use these functions, include the header file and compile the `0-add_node.c` source file. Here's an example of how you might use these functions:

```c
#include <stdio.h>
#include "0-add_node.h"

int main(void)
{
    List *list = NULL;
    List *node;

    node = add_node_end(&list, "Hello");
    if (node == NULL)
    {
        fprintf(stderr, "Failed to add node to end\n");
        return (1);
    }

    node = add_node_begin(&list, "World");
    if (node == NULL)
    {
        fprintf(stderr, "Failed to add node to beginning\n");
        return (1);
    }

    // Additional code to print and manipulate the list

    return (0);
}
