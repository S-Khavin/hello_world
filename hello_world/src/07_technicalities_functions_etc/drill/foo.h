#pragma once
extern int foo;
void print_foo();
void print(int);
void set_foo(int);
auto bar() -> decltype(random_int(10));