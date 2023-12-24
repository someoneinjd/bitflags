#!/usr/bin/env python3

import sys


def generate_macros(n: int):
    assert n > 0
    print(
        """
#define SC_BITFLAGS_DETAIL_CONCATENATE(arg1, arg2)   SC_BITFLAGS_DETAIL_CONCATENATE1(arg1, arg2)
#define SC_BITFLAGS_DETAIL_CONCATENATE1(arg1, arg2)  SC_BITFLAGS_DETAIL_CONCATENATE2(arg1, arg2)
#define SC_BITFLAGS_DETAIL_CONCATENATE2(arg1, arg2)  arg1##arg2"""
    )
    print(
        """
#define SC_BITFLAGS_DETAIL_MAP_MEMBER_0(...)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_1(macro_func, type, bit_offset, name) \\
    macro_func(type, bit_offset, name);"""
    )
    for i in range(1, n):
        print(
            """
#define SC_BITFLAGS_DETAIL_MAP_MEMBER_{}(macro_func, type, bit_offset, name, ...) \\
    macro_func(type, bit_offset, name); \\
    SC_BITFLAGS_DETAIL_MAP_MEMBER_{}(macro_func, type, bit_offset + 1, __VA_ARGS__)""".format(
                i + 1, i
            )
        )
    print(
        """
#define SC_BITFLAGS_DETAIL_SELECT_N("""
        + ", ".join(f"_{i}" for i in range(1, n + 1))
        + ", N, ...) N"
    )
    print(
        """
#define SC_BITFLAGS_DETAIL_SEQ_N() """
        + ", ".join(f"{i}" for i in range(n, -1, -1))
    )
    print(
        """
#define SC_BITFLAGS_DETAIL_COUNT_(...) SC_BITFLAGS_DETAIL_SELECT_N(__VA_ARGS__)"""
    )
    print(
        """
#define SC_BITFLAGS_DETAIL_COUNT(...) SC_BITFLAGS_DETAIL_COUNT_(__VA_ARGS__ __VA_OPT__(,) SC_BITFLAGS_DETAIL_SEQ_N())"""
    )
    print(
        """
#define SC_BITFLAGS_DETAIL_MAP_MEMBERS_(N, macro_func, type, ...) \\
        SC_BITFLAGS_DETAIL_CONCATENATE(SC_BITFLAGS_DETAIL_MAP_MEMBER_, N)(macro_func, type, 0 __VA_OPT__(, ) __VA_ARGS__)"""
    )
    print(
        """
#define SC_BITFLAGS_DETAIL_MAP_MEMBERS(macro_func, type, ...) \\
        SC_BITFLAGS_DETAIL_MAP_MEMBERS_(SC_BITFLAGS_DETAIL_COUNT(__VA_ARGS__), macro_func, type __VA_OPT__(, ) __VA_ARGS__)"""
    )


if __name__ == "__main__":
    generate_macros(int(sys.argv[1]))
