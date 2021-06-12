#include <iostream>
#include "Library.cpp"
#include "Test\\Test.cpp"

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"

int main()
{
    doctest::Context().run();
    //Library l;
    //l.run();
    return 0;
}
