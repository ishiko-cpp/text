/*
    Copyright (c) 2020-2023 Xavier Leclercq
    Released under the MIT License
    See https://github.com/ishiko-cpp/text/blob/main/LICENSE.txt
*/

#include "ASCIITests.hpp"
#include "CStringTests.hpp"
#include "InterpolatedStringTests.hpp"
#include "TruncatedStringTests.hpp"
#include "UTF8CharTests.hpp"
#include "UTF8StringTests.hpp"
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
    theTests.append<UTF8CharTests>();
    theTests.append<UTF8StringTests>();

    return theTestHarness.run();
}
