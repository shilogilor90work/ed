#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include "Document.h"

class Editor
{
public:
    Document document;
    Editor()
    {
        document.row_number = -1;
    }

    Editor(std::string _file)
    {
        std::ifstream file(_file);

        if (!file)
        {
          std::cout << "File Not Found" << std::endl;
        }
        for (std::string line; getline(file, line);)
        {
            document.document.push_back(line);
        }
        file.close();
    }
    void loop();
};
