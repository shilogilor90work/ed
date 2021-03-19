#include "Editor.h"
#include <string>

int main(int argc, char *argv[])
{
    if (argc == 2) //a.out file_name
    {
        Editor editor(argv[1]);
        editor.loop();
    }
    else
    {
        Editor editor;
        editor.loop();
    }
    return 0;
}
