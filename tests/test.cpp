#include <cstdint>

#include "boost/ut.hpp"
#include "sc/bitflags.hpp"

BITFLAGS(Test, A, B, C);

int main() {
    using namespace boost::ut;
    "type"_test = [] {
        expect(std::same_as<Test::value_type, std::uint8_t> == "is uint8_t type"_b);
    };
    "value"_test = [] {
        expect(Test::all().value == 255_u);
        expect(Test::empty().value == 0_u);
        expect(Test::A.value == 1_u);
        expect(Test::B.value == 2_u);
        expect(Test::C.value == 4_u);
    };
    "action"_test = [] {
        "contains"_test = [] {
            auto flag = Test::all();
            expect(flag.contains(Test::A) == "contains Test::A"_b);
            expect(flag.contains(Test::B) == "contains Test::B"_b);
            expect(flag.contains(Test::C) == "contains Test::C"_b);
            expect(flag.contains(Test::A, Test::B, Test::C) ==
                   "contains Test::A and Test::B and Test::C"_b);
            flag = Test::empty();
            expect(flag.contains(Test::A) == not "contains Test::A"_b);
            expect(flag.contains(Test::B) == not "contains Test::B"_b);
            expect(flag.contains(Test::C) == not "contains Test::C"_b);
            expect(flag.contains(Test::A, Test::B, Test::C) ==
                   not "contains Test::A and Test::B and Test::C"_b);
        };
        "set"_test = [] {
            auto flag = Test::empty();
            expect(flag.contains(Test::A) == not "contains Test::A"_b);
            expect(flag.contains(Test::B) == not "contains Test::B"_b);
            flag.set(Test::A);
            expect(flag.contains(Test::A) == "contains Test::A"_b);
            expect(flag.contains(Test::B) == not "contains Test::B"_b);
            flag.set(Test::B);
            expect(flag.contains(Test::A) == "contains Test::A"_b);
            expect(flag.contains(Test::B) == "contains Test::B"_b);
        };
        "remove"_test = [] {
            auto flag = Test::all();
            expect(flag.contains(Test::A) == "contains Test::A"_b);
            expect(flag.contains(Test::B) == "contains Test::B"_b);
            flag.remove(Test::A);
            expect(flag.contains(Test::A) == not "contains Test::A"_b);
            expect(flag.contains(Test::B) == "contains Test::B"_b);
            flag.remove(Test::B);
            expect(flag.contains(Test::A) == not "contains Test::A"_b);
            expect(flag.contains(Test::B) == not "contains Test::B"_b);
        };
        "toggle"_test = [] {
            auto flag = Test::all();
            flag.toggle(Test::A);
            expect(flag.contains(Test::A) == not "contains Test::A"_b);
            expect(flag.contains(Test::B) == "contains Test::B"_b);
            flag.toggle(Test::A);
            flag.toggle(Test::B);
            expect(flag.contains(Test::A) == "contains Test::A"_b);
            expect(flag.contains(Test::B) == not "contains Test::B"_b);
        };
        "clear"_test = []{
            auto flag = Test::all();
            expect(flag.is_empty() == not "empty"_b);
            flag.clear();
            expect(flag.is_empty() == "is empty"_b);
        };
    };
    "operator"_test = [] {
        "not"_test = [] {
            auto flag = ~Test::empty();
            expect((flag == Test::all()) == "~empty == all"_b);
            flag = ~Test::all();
            expect((flag == Test::empty()) == "~all == empty"_b);
        };
        "and"_test = [] {
            auto flag = Test::A | Test::B;
            expect(flag.contains(Test::A) == "contains Test::A"_b);
            expect(flag.contains(Test::B) == "contains Test::B"_b);
            expect(flag.contains(Test::C) == not "contains Test::C"_b);
        };
        "or"_test = [] {
            expect((Test::A | Test::B).value == 3_u);
            expect((Test::A | Test::B | Test::C).value == 7_u);
        };
        "xor"_test = [] {
            expect((Test::A ^ Test::A).value == 0_u);
            expect((Test::A ^ Test::A ^ Test::A).value == 1_u);
        };
    };
    "to_string"_test = [] {
        expect((Test::A.to_string() == "Test::A") == "string is Test::A"_b);
        expect((Test::B.to_string() == "Test::B") == "string is Test::B"_b);
        expect((Test::C.to_string() == "Test::C") == "string is Test::C"_b);
        auto flag = Test::A | Test::B | Test::C;
        expect((flag.to_string() == "Test::A | Test::B | Test::C") ==
               "string is Test::A | Test::B | Test::C"_b);
        expect((Test::empty().to_string() == "<empty>") == "empty"_b);
    };
}
