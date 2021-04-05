#!/usr/bin/env bash

echo "Foo"
nm build/libfoo_lib.a | grep Foo
echo

echo "Foo in link_test"
nm build/link_test | grep Foo
echo

echo "Foo in link_test2"
nm build/link_test2 | grep Foo
echo
