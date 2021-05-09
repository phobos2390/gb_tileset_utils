/// @file phobos2390/gb_tileset_utils/Args_interpret.cpp

#include <phobos2390/gb_tileset_utils/Args_interpret.h>
#include <fstream>

namespace gb_tileset_utils
{

struct Args_interpret::Impl
{
public:
    std::fstream* m_p_fstream;
    char m_tagchar;
    std::string m_tagname;
    
    Impl()
        : m_p_fstream(0)
    {
    }
    virtual ~Impl()
    {
        if(m_p_fstream)
        {
            m_p_fstream->close();
        }
        delete m_p_fstream;
        m_p_fstream = 0;
    }
};

Args_interpret::Args_interpret()
    :m_p_impl(new Impl)
{
}

Args_interpret::~Args_interpret()
{
    delete m_p_impl;
    m_p_impl = 0;
}

void Args_interpret::interpret_args(int32_t argc, char** argv)
{
    std::string tagchar = "-";
    tagchar.append(1, m_p_impl->m_tagchar);
    std::string tagname = "--";
    tagname.append(m_p_impl->m_tagname);
    for(int32_t i = 0; i < argc; i++)
    {
        if( (tagchar.compare(argv[i]) == 0)
         || (tagname.compare(argv[i]) == 0))
        {
            if(m_p_impl->m_p_fstream)
            {
                m_p_impl->m_p_fstream->close();
                delete m_p_impl->m_p_fstream;
                m_p_impl->m_p_fstream = 0;
            }
            std::fstream* p_file = new std::fstream;
            p_file->open(argv[i+1], std::ios_base::binary | std::ios_base::in);
            m_p_impl->m_p_fstream = p_file;
        }
    }
}
    
void Args_interpret::set_filename_arg(char tagchar, std::string tagname)
{
    m_p_impl->m_tagchar = tagchar;
    m_p_impl->m_tagname = tagname;
}

std::istream& Args_interpret::get_input()
{
    std::istream* p_return_stream = &std::cin;
    if(m_p_impl->m_p_fstream)
    {
        p_return_stream = m_p_impl->m_p_fstream;
    }
    return *p_return_stream;
}

}
