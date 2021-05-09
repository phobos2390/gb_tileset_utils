/// @file phobos2390/gb_tileset_utils/test/Args_interpret_test.cpp

#include <phobos2390/gb_tileset_utils/Args_interpret.h>
#include <catch2/catch.hpp>
#include <phobos2390/gb_tileset_utils/Args_interpret.h> // Testing include guard
#include <fstream>

using namespace gb_tileset_utils;

TEST_CASE( "Args_interpret_test", "stack" )
{
    Args_interpret c;
}

TEST_CASE( "Args_interpret_test.test_files.sample_file.txt", "Args_interpret_test.test_files.sample_file.txt" )
{
    Args_interpret c;
    c.set_filename_arg('i', "input_file");
    int32_t argc = 3;
    char* argv [3];
    argv[0] = const_cast<char*>("executable");
    argv[1] = const_cast<char*>("-i");
    argv[2] = const_cast<char*>("test_files/sample_file.txt");
    c.interpret_args(argc, argv);
    
    REQUIRE(dynamic_cast<std::fstream*>(&c.get_input()) != 0);
}
