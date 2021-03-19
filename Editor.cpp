#include "Editor.h"
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <mutex>


void Editor::loop()
{
    while (true)
    {
        char c = getchar();

        switch (c)
        {
          case '1':
              document.row_number = 0;
              break;

          case '3':
              document.row_number = 2;
              break;

          case '+':
              document.plus();
              break;

          case '-':
              document.minus();
              break;

          case '$':
              document.row_number = document.document.size() - 1;
              break;

          case 'a':
              document.line_add_after();
              break;

          case 'i':
              document.line_add_before();
              break;

          case 'c':
              document.line_replace();
              break;

          case 'd':
              document.line_delete();
              break;

          case '/':
              document.search();
              break;

          case 's':
              document.change();
              break;

          case 'j':
              document.connect();
              break;

          case 'w':
              document.write();
              break;

          case 'q':
              exit(EXIT_FAILURE);

          default:
              if (c != '\n')
              {
                std::cout << "?" << std::endl;
              }
              break;
        }
    }
}
