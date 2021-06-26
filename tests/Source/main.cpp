/*
    Copyright (c) 2020-2021 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "ASCIITests.h"
#include "CStringTests.h"
#include <Ishiko/Tests/Core.h>

using namespace Ishiko::Tests;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoText");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<ASCIITests>();
    theTests.append<CStringTests>();

    return theTestHarness.run();
}
