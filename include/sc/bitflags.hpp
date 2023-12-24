#pragma once

#include <concepts>
#include <cstddef>
#include <cstdint>
#include <string>
#include <string_view>

namespace sc::bitflags {
namespace detail {
template <std::size_t N>
consteval auto flag_type() {
    if constexpr (N <= 8)
        return std::uint8_t{};
    else if constexpr (N <= 16)
        return std::uint16_t{};
    else if constexpr (N <= 32)
        return std::uint32_t{};
    else
        return std::uint64_t{};
}

template <std::size_t N>
    requires(N <= 64)
using flag_type_t = decltype(flag_type<N>());

}  // namespace detail
}  // namespace sc::bitflags

#define SC_BITFLAGS_DETAIL_CONCATENATE(arg1, arg2) SC_BITFLAGS_DETAIL_CONCATENATE1(arg1, arg2)
#define SC_BITFLAGS_DETAIL_CONCATENATE1(arg1, arg2) SC_BITFLAGS_DETAIL_CONCATENATE2(arg1, arg2)
#define SC_BITFLAGS_DETAIL_CONCATENATE2(arg1, arg2) arg1##arg2

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_0(...)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_1(macro_func, type, bit_offset, name) \
    macro_func(type, bit_offset, name);

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_2(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                          \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_1(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_3(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                          \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_2(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_4(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                          \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_3(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_5(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                          \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_4(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_6(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                          \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_5(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_7(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                          \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_6(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_8(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                          \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_7(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_9(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                          \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_8(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_10(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_9(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_11(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_10(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_12(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_11(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_13(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_12(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_14(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_13(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_15(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_14(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_16(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_15(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_17(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_16(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_18(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_17(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_19(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_18(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_20(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_19(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_21(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_20(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_22(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_21(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_23(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_22(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_24(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_23(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_25(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_24(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_26(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_25(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_27(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_26(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_28(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_27(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_29(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_28(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_30(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_29(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_31(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_30(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_32(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_31(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_33(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_32(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_34(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_33(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_35(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_34(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_36(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_35(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_37(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_36(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_38(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_37(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_39(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_38(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_40(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_39(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_41(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_40(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_42(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_41(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_43(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_42(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_44(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_43(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_45(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_44(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_46(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_45(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_47(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_46(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_48(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_47(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_49(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_48(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_50(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_49(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_51(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_50(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_52(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_51(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_53(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_52(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_54(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_53(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_55(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_54(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_56(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_55(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_57(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_56(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_58(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_57(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_59(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_58(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_60(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_59(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_61(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_60(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_62(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_61(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_63(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_62(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBER_64(macro_func, type, bit_offset, name, ...) \
    macro_func(type, bit_offset, name);                                           \
    SC_BITFLAGS_DETAIL_MAP_MEMBER_63(macro_func, type, bit_offset + 1, __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_SELECT_N(                                                               \
    _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20,     \
    _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _36, _37, _38, _39, \
    _40, _41, _42, _43, _44, _45, _46, _47, _48, _49, _50, _51, _52, _53, _54, _55, _56, _57, _58, \
    _59, _60, _61, _62, _63, _64, N, ...)                                                          \
    N

#define SC_BITFLAGS_DETAIL_SEQ_N()                                                              \
    64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, \
        41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
        19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0

#define SC_BITFLAGS_DETAIL_COUNT_(...) SC_BITFLAGS_DETAIL_SELECT_N(__VA_ARGS__)

#define SC_BITFLAGS_DETAIL_COUNT(...) \
    SC_BITFLAGS_DETAIL_COUNT_(__VA_ARGS__ __VA_OPT__(, ) SC_BITFLAGS_DETAIL_SEQ_N())

#define SC_BITFLAGS_DETAIL_MAP_MEMBERS_(N, macro_func, type, ...)     \
    SC_BITFLAGS_DETAIL_CONCATENATE(SC_BITFLAGS_DETAIL_MAP_MEMBER_, N) \
    (macro_func, type, 0 __VA_OPT__(, ) __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_MAP_MEMBERS(macro_func, type, ...)                          \
    SC_BITFLAGS_DETAIL_MAP_MEMBERS_(SC_BITFLAGS_DETAIL_COUNT(__VA_ARGS__), macro_func, \
                                    type __VA_OPT__(, ) __VA_ARGS__)

#define SC_BITFLAGS_DETAIL_DEFINE_STATIC_MEMBER(type, bit_offset, name) \
    constexpr static type name { 1ull << (bit_offset) }

#define SC_BITFLAGS_DETAIL_CASE(type, bit_offset, name) \
    case 1ull << (bit_offset): return #type "::" #name

#define BITFLAGS(TypeName, ...)                                                                    \
    struct TypeName {                                                                              \
        constexpr static std::size_t flag_size = SC_BITFLAGS_DETAIL_COUNT(__VA_ARGS__);            \
        using value_type = sc::bitflags::detail::flag_type_t<flag_size>;                           \
        struct SC_BITFLAGS_DETAIL_CONCATENATE(TypeName, Flag) {                                    \
            operator TypeName() const& { return {value}; }                                         \
            constexpr std::string_view to_string() const& {                                        \
                switch (value) {                                                                   \
                    SC_BITFLAGS_DETAIL_MAP_MEMBERS(SC_BITFLAGS_DETAIL_CASE, TypeName, __VA_ARGS__) \
                    default: return #TypeName "::<unknown flag>";                                  \
                }                                                                                  \
            }                                                                                      \
            value_type value;                                                                      \
        };                                                                                         \
        using flag_type = SC_BITFLAGS_DETAIL_CONCATENATE(TypeName, Flag);                          \
        value_type value;                                                                          \
        constexpr std::string to_string() const& {                                                 \
            std::string ret{};                                                                     \
            ret.reserve(16);                                                                       \
            std::uint32_t i = 0;                                                                   \
            if (contains({static_cast<value_type>(1ull << i)}))                                    \
                ret += flag_type{static_cast<value_type>(1ull << i)}.to_string().data();           \
            for (value_type i = 1; i < flag_size; i++) {                                           \
                if (contains({static_cast<value_type>(1ull << i)})) {                              \
                    ret += " | ";                                                                  \
                    ret += flag_type{static_cast<value_type>(1ull << i)}.to_string().data();       \
                }                                                                                  \
            }                                                                                      \
            if (ret.empty()) return "<empty>";                                                     \
            return ret;                                                                            \
        }                                                                                          \
        constexpr bool is_empty() const& { return value == value_type{}; }                         \
        constexpr bool is_all() const& { return value == all().value; }                            \
        constexpr bool contains(const flag_type a) const& { return (value & a.value) != 0; }       \
        constexpr bool contains(const flag_type a,                                                 \
                                const std::same_as<flag_type> auto... args) const& {               \
            return contains(a) && (contains(args) && ...);                                         \
        }                                                                                          \
        constexpr void set(const flag_type a) & { value |= a.value; }                              \
        constexpr void remove(const flag_type a) & { value &= ~a.value; }                          \
        constexpr void toggle(const flag_type a) & { value ^= a.value; }                           \
        constexpr void clear() & { value = value_type{}; }                                         \
        constexpr TypeName& operator|=(const flag_type a) & {                                      \
            value |= a.value;                                                                      \
            return *this;                                                                          \
        }                                                                                          \
        constexpr TypeName& operator&=(const flag_type a) & {                                      \
            value &= a.value;                                                                      \
            return *this;                                                                          \
        }                                                                                          \
        constexpr TypeName& operator^=(const flag_type a) & {                                      \
            value ^= a.value;                                                                      \
            return *this;                                                                          \
        }                                                                                          \
        constexpr static TypeName empty() { return {}; }                                           \
        constexpr static TypeName all() { return {static_cast<value_type>(~value_type{})}; }       \
        SC_BITFLAGS_DETAIL_MAP_MEMBERS(SC_BITFLAGS_DETAIL_DEFINE_STATIC_MEMBER, flag_type,         \
                                       __VA_ARGS__)                                                \
    };                                                                                             \
    constexpr bool operator==(const TypeName a, const TypeName b) { return a.value == b.value; }   \
    constexpr TypeName operator|(const TypeName a, const typename TypeName::flag_type b) {         \
        return {static_cast<typename TypeName::value_type>(a.value | b.value)};                    \
    }                                                                                              \
    constexpr TypeName operator|(const typename TypeName::flag_type a, const TypeName b) {         \
        return {static_cast<typename TypeName::value_type>(a.value | b.value)};                    \
    }                                                                                              \
    constexpr TypeName operator|(const typename TypeName::flag_type a,                             \
                                 const typename TypeName::flag_type b) {                           \
        return {static_cast<typename TypeName::value_type>(a.value | b.value)};                    \
    }                                                                                              \
    constexpr TypeName operator&(const TypeName a, const typename TypeName::flag_type b) {         \
        return {static_cast<typename TypeName::value_type>(a.value & b.value)};                    \
    }                                                                                              \
    constexpr TypeName operator&(const typename TypeName::flag_type a, const TypeName b) {         \
        return {static_cast<typename TypeName::value_type>(a.value & b.value)};                    \
    }                                                                                              \
    constexpr TypeName operator&(const typename TypeName::flag_type a,                             \
                                 const typename TypeName::flag_type b) {                           \
        return {static_cast<typename TypeName::value_type>(a.value & b.value)};                    \
    }                                                                                              \
    constexpr TypeName operator^(const TypeName a, const typename TypeName::flag_type b) {         \
        return {static_cast<typename TypeName::value_type>(a.value ^ b.value)};                    \
    }                                                                                              \
    constexpr TypeName operator^(const typename TypeName::flag_type a, const TypeName b) {         \
        return {static_cast<typename TypeName::value_type>(a.value ^ b.value)};                    \
    }                                                                                              \
    constexpr TypeName operator^(const typename TypeName::flag_type a,                             \
                                 const typename TypeName::flag_type b) {                           \
        return {static_cast<typename TypeName::value_type>(a.value ^ b.value)};                    \
    }                                                                                              \
    constexpr TypeName operator~(const TypeName a) {                                               \
        return {static_cast<typename TypeName::value_type>(~a.value)};                             \
    }                                                                                              \
    constexpr TypeName operator~(const typename TypeName::flag_type a) {                           \
        return {static_cast<typename TypeName::value_type>(~a.value)};                             \
    }
