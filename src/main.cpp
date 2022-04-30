#include "shared_ptr.h"
#include "unique_ptr.h"
#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char** argv)
{
    if (false) // make false to run unit-tests
    {
        // debug section
        // std::cout << "everything is ok!" << std::endl;
        // UniquePtr<int> ptr { new int { 10 } };
        // std::cout << *ptr << std::endl; // output: 10
        UniquePtr<std::string> ptr { new std::string { "hello" } };
        ptr.reset(new std::string { "nice" });
        std::cout << *ptr << std::endl; // output: nice

    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret { RUN_ALL_TESTS() };
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}