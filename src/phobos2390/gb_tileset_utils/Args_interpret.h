/// @file phobos2390/gb_tileset_utils/Args_interpret.h

#ifndef GB_TILESET_UTILS_ARGS_INTERPRET_H
#define GB_TILESET_UTILS_ARGS_INTERPRET_H

#include <string>
#include <stdint.h>
#include <iostream>

namespace gb_tileset_utils
{

class Args_interpret
{
public:
    /// Creates class value
    Args_interpret();

    /// Removes class value
    virtual ~Args_interpret();
    
    void interpret_args(int32_t argc, char** argv);
    
    void set_filename_arg(char tagchar, std::string tagname);
    
    std::istream& get_input();
private:
    struct Impl;
    Impl* m_p_impl;
};

}

#endif /* GB_TILESET_UTILS_ARGS_INTERPRET_H */
