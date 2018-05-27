# VariadicTable

Used for "pretty-printing" a formatted table of data to the console.

It uses "variadic templates" to allow you to specify the types of data in each column.

## Example Usage

```C++
VariadicTable<std::string, double, int, std::string> vt({"Name", "Weight", "Age", "Brother"});

vt.addRow({"Cody", 180.2, 40, "John"});
vt.addRow({"David", 175.3, 38, "Andrew"});
vt.addRow({"Robert", 140.3, 27, "Fande"});

vt.print();
```

Outputs:

```
--------------------------------------
|Name  |Weight    |Age       |Brother|
--------------------------------------
|Cody  |     180.2|        40|John   |
|David |     175.3|        38|Andrew |
|Robert|     140.3|        27|Fande  |
--------------------------------------
```

## Installation

Just put `VariadicTable.h` somewhere and `#include "VariadicTable.h"`