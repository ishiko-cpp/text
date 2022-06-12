/*
    Copyright (c) 2020-2022 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "ASCIITests.hpp"
#include "CStringTests.hpp"
#include "InterpolatedStringTests.hpp"
#include "TruncatedStringTests.hpp"
#include <Ishiko/TestFramework/Core.hpp>
#include <Ishiko/Text/linkoptions.hpp>

using namespace Ishiko;

int main(int argc, char* argv[])
{
    TestHarness theTestHarness("IshikoText");

    TestSequence& theTests = theTestHarness.tests();
    theTests.append<ASCIITests>();
    theTests.append<CStringTests>();
    theTests.append<InterpolatedStringTests>();
    theTests.append<TruncatedStringTests>();

    return theTestHarness.run();
}
