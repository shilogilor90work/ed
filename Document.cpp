#include "Document.h"
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <iterator>

void Document::plus()
{
    std::string line;
    std::getline(std::cin, line);
    if (!line.empty())
    {
        row_number += stoi(line);
    }
}

void Document::minus()
{
    std::string line;
    std::getline(std::cin, line);
    if (!line.empty())
    {
        row_number -= stoi(line);
    }
}

void Document::line_add_after()
{
    for (std::string line; std::getline(std::cin, line);)
    {
        if (!line.empty())
        {
            if (line == ".")
            {
              return;
            }
            document.emplace(document.begin() + (row_number + 1), line);
            row_number++;
        }
    }
}

void Document::line_add_before()
{
    for (std::string line; std::getline(std::cin, line);)
    {
        if (!line.empty())
        {
            if (line == ".")
            {
                row_number--;
                return;
            }
            document.emplace(document.begin() + row_number, line);
            row_number++;
        }
    }
}

void Document::line_replace()
{
    document.erase(document.begin() + row_number);
    for (std::string line; std::getline(std::cin, line);)
    {
        if (!line.empty())
        {
            if (line == ".")
            {
              return;
            }
            document.emplace(document.begin() + row_number, line);
        }
    }
}

void Document::line_delete()
{
    document.erase(document.begin() + row_number);
}

void Document::search()
{
    std::string line;
    std::getline(std::cin, line);
    if (!line.empty())
    {
        line = line.substr(0, line.size() - 1);
        size_t found = document.at(row_number + 1).find(line);
        if (found != std::string::npos)
        {
          row_number++;
        }
        else
        {
            int i = -1;
            while (found == std::string::npos)
            {
                i++;
                found = document.at(i).find(line);
            }
            row_number = i;
        }
    }
}

void Document::change()
{
    std::string line;
    std::getline(std::cin, line);

    if (!line.empty())
    {
        if (line.at(0) != '/' || line.at(line.length() - 1) != '/')
        {
            std::cout << "?" << std::endl;
            return;
        }
        line = line.substr(1, line.size() - 2);
        try
        {
            std::string old = line.substr(0, line.find("/"));
            std::string neword = line.substr(line.find("/") + 1, line.size() - 1);
            document.at(row_number).replace(document.at(row_number).find(old), old.size(), neword);
        }
        catch (std::out_of_range)
        {
            std::cout << "?" << std::endl;
        }
    }
}

void Document::connect()
{
    document.at(row_number) += document.at(row_number + 1);
    document.erase(document.begin() + (row_number + 1));
}

void Document::write()
{
    std::string line;
    std::getline(std::cin, line);
    if (!line.empty())
    {
        line = line.substr(1, line.size());
        std::ofstream output_file(line);
        std::ostream_iterator<std::string> output_iterator(output_file, "\n");
        std::copy(document.begin(), document.end(), output_iterator);
    }
}
