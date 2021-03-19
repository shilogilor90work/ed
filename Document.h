#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <iostream>

// Document will be the file to be read
class Document
{
  public:
      std::vector<std::string> document;
      int row_number = 0;

      void plus(); // the plus function '+'
      void minus(); // the minus function '-'
      void line_add_after(); // the add after the line function 'a'
      void line_add_before(); // the add a line before function 'i'
      void line_replace(); // the replace current line function 'c'
      void line_delete(); // the delete current line function 'd'
      void search(); // the search words within the text '/{{patturn}}/'
      void change(); // the replace text within the line 's/{{old}}/{{new}}/'
      void connect(); // connect the curent line with the next 'j'
      void write(); // write the page to the file 'w'
};
