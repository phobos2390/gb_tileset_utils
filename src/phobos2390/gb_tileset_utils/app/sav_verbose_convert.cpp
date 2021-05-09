#include <stdint.h>
#include <iostream>
#include <phobos2390/gb_tileset_utils/Args_interpret.h>

int32_t main(int32_t argc, char** argv)
{
    gb_tileset_utils::Args_interpret args;
    args.set_filename_arg('i', "sav_file");
    args.interpret_args(argc, argv);
    
    char tile_size_input [sizeof(uint16_t)];
    if(args.get_input().read(tile_size_input, sizeof(tile_size_input)))
    {
        uint16_t tileset_size = (tile_size_input[1] << 0x8) | tile_size_input[0];
        char tileset_binary [tileset_size];
        if(args.get_input().read(tileset_binary, tileset_size))
        {
            uint16_t character_number = 0;
            for(uint16_t i = 0; i < tileset_size; i++)
            {
                if(i % 16 == 0)
                {
                    std::cout << "; $" << std::hex << character_number++ << "\n";                    
                }
                if(i % 2 == 0)
                {
                    std::cout << "DB %";
                }
                if(i % 2 == 1)
                {
                    std::cout << ", %";
                }
                for(uint8_t j = 0; j < 8; j++)
                {
                    std::cout << ((tileset_binary[i] & (0x80 >> j)) >> (7 - j));
                }
                if(i % 2 == 1)
                {
                    std::cout << "\n";
                }
            }
        }
        else
        {
            std::cerr << "Failed to read rest of input \n";
        }
    }
    else
    {
        std::cerr << "Failed to read input file \n";
    }
    
    return 0;
}
