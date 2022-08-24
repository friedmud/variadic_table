# VariadicTable

Used for "pretty-printing" a formatted table of data to the console.

It uses "variadic templates" to allow you to specify the types of data in each column.

## Example Usage

```C++
#include "VariadicTable.h"

VariadicTable<std::string, double, int, std::string> vt({"Name", "Weight", "Age", "Brother"},
                                                            10);

vt.addRow("Cody", 180.2, 40, "John");
vt.addRow("David", 175.3, 38, "Andrew");
vt.addRow("Robert", 140.3, 27, "Fande");

vt.print(std::cout);
```

Outputs:

```
------------------------------------------------
|  Name  |   Weight   |     Age    |  Brother  |
------------------------------------------------
| Cody   |      180.2 |         40 | John      |
| David  |      175.3 |         38 | Andrew    |
| Robert |      140.3 |         27 | Fande     |
------------------------------------------------
```

For more usage examples see [main.C](https://github.com/friedmud/variadic_table/blob/master/src/main.C).

## Installation

Just put `VariadicTable.h` somewhere and `#include "VariadicTable.h"`

## Compilation

You don't _need_ to compile this - but a simple `make` should work to build the `main.C` provided here so you can see the example usage.
