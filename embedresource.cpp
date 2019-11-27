#include <fstream>
#include <iostream>
#include <filesystem>

int main(int argc, char** argv)
{
    if (argc < 3) {
        fprintf(stderr, "USAGE: %s {sym} {rsrc}\n\n"
                        "  Creates {sym}.h from the contents of {rsrc}\n",
                argv[0]);
        return EXIT_FAILURE;
    }

    std::filesystem::path dst{argv[1]};

    std::ofstream ofs{ dst };
    ofs << "#pragma once" << std::endl;
    ofs << "#include <stdlib.h>" << std::endl;
    ofs << "#include <algorithm>" << std::endl;

    for (auto i = 2; i < argc; i++)
    {
        std::filesystem::path src{ argv[i] };

        std::string sym = src.filename().string();
        replace(sym.begin(), sym.end(), '.', '_');
        replace(sym.begin(), sym.end(), '-', '_');

        create_directories(dst.parent_path());

        std::ifstream ifs{ src };

        ofs << "const char " << sym << "[] = {" << std::endl;

        size_t lineCount = 0;
        while (ifs.good() && !ifs.eof())
        {
            char c;
            ifs.get(c);
            ofs << "0x" << std::hex << (c & 0xff) << ", ";
            if (++lineCount == 10) {
                ofs << std::endl;
                lineCount = 0;
            }
        }

        ofs << "};" << std::endl << std::endl;
    }

    return EXIT_SUCCESS;
}
