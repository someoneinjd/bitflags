# bitflags

A single-header C++20 library for generating type-safe bitflags automatically:

* Automatically infer underlying type.
* Automatically generate flag values.

test fix

## Quick start

```cpp
#include <sc/bitflags.h>

BITFLAGS(Test, A, B, C);

int main() {
    Test flag = Test::A | Test::B;

    std::cout << flag.to_string(); // "Test::A | Test::B"

    flag.contains(Test::A); // true
    flag.contains(Test::C); // false

    flag.set(Test::C); 
    flag.contains(Test::C); // true

    flag.remove(Test::A);
    flag.contains(Test::A); // false

    std::cout << flag.to_string(); // "Test::B | Test::C"
}
```

## Getting Started

### Define Flags

```cpp
BITFLAGS(TypeName, Flag0, Flag1, ...);
```

which will generate a flag type named `TypeName` and flag values `TypeName::Flag0`, `TypeName::Flag1` and so on.

> [!NOTE]
> The type of the flag value is not `TypeName`, but an internal type. This ensures that the user can only set/remove these defined flags for better type safety.

The above example will generate the following type:

```cpp
struct TypeName {
    constexpr static std::size_t flag_size = the number of flags.
    using value_type = the smallest unsigned integer type that can hold all the flags. 
    // internal type for Flag0, Flag1.
    struct TypeNameFlag {
        // can be convert to TypeName.
        operator TypeName() cosnt & {
            return {value};
        }
        value_type value;
    };
    value_type value;

    constexpr static TypeNameFlag Flag0{static_cast<value_type>(1ull << 0)};
    constexpr static TypeNameFlag Flag1{static_cast<value_type>(1ull << 1)};
    ...
};
```

> [!IMPORTANT]
> Always use the specific flag type `TypeName` instead of `auto`. As for `auto f = Flag0`, `f` will be deduced to the internal type `TypeNameFlag`, not `TypeName`.

### Overloaded Operators 

The following operators are overloaded for the generated flags:

* `operator==`
* `operator&`
* `operator|`
* `operator^`
* `operator~`

> [!NOTE]
> All of the flag operations described in the rest of README can be implemented using these operators, they will be omitted for brevity.

### Check if a specific flag is set

Use `contains` member funcion.

```cpp
BITFLAGS(Test, A, B, C);

Test flag = Test::A | Test::B;

flag.contains(Test::A);          // true
flag.contains(Test::C);          // false
flag.contains(Test::A, Test::B); // true
```

### Set / Remove a specific flag

Use member funcions `set` and `remove`.

```cpp
BITFLAGS(Test, A, B, C);

Test flag = Test::A | Test::B;

flag.contains(Test::C); // false

flag.set(Test::C);
flag.contains(Test::C); // true

flag.remove(Test::A);
flag.contains(Test::A); // false
```

### Toggle a specific flag

Use member funcion `toggle`. If the flag is not already set, it will be set. On the other hand, if the flag is already set, it will be unset.

```cpp
BITFLAGS(Test, A, B, C);

Test flag = Test::A | Test::B;

flag.contains(Test::A); // true
flag.contains(Test::C); // false

flag.toggle(Test::A);
flag.toggle(Test::C);

flag.contains(Test::A); // false
flag.contains(Test::C); // true
```

### Clear all set flags

Use member funcion `clear`.

```cpp
BITFLAGS(Test, A, B, C);

Test flag = Test::A | Test::B;

flag.contains(Test::A); // true
flag.contains(Test::B); // true

flag.clear();

flag.contains(Test::A); // false
flag.contains(Test::B); // false
```

### All and Empty

There are also static function `all` and `empty` for generating a value for which all flags are set / not set.

> [!IMPORTANT]
> The `all` function sets all the bits, whether it makes sense or not.

```cpp
BITFLAGS(Test, A, B, C);

Test flag = Test::all();
flag.is_all();          // true
flag.contains(Test::A); // true
flag.contains(Test::B); // true
flag.contains(Test::C); // true
flag.value;             // 255

flag = Test::empty();
flag.is_empty();        // true
flag.contains(Test::A); // false
flag.contains(Test::B); // false
flag.contains(Test::C); // false
flag.value;             // 0
```

### Pretty Print

Use member funcion `to_string`. It returns the names of all the flags that are set, concatenated with `" | "`. If no flags are set, it returns `<empty>`.

```cpp
BITFLAGS(Test, A, B, C);

Test flag = Test::A | Test::B | Test::C;
flag.to_string();          // "Test::A | Test::B | Test::C"
Test::B.to_string();       // "Test::B"
Test::empty().to_string(); // "<empty>"
```

## Limitations

* Since the largest unsigned integer type defined in the standard is `std::uint64_t`, only up to 64 flags are supported.
