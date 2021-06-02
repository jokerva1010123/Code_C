/*  Данная программа обрабатывает аргументы
    из командной строки и выполняет указанные
    команды в соответствии с условием задачи 3
    лабораторной работы 5.
    Выбранный тип данных для чисел: int.
    Выбранная сортировка: Сортировка вставками.
    Выбранное "направление": По возрастанию. */

#include "process.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);
    FILE *fsrc;
    int result = 0;

    if ((argc != 3) && (argc != 4))
    {
        printf("main.exe <command> [<number>] <source file>\n");

        result = -1;
    }
    else
    {
        if ((strcmp(argv[1], "c") == 0) && (argc == 4))
        {
            fsrc = fopen(argv[3], "wb");
            result = command_c(fsrc, argv[2]);
            fclose(fsrc);
        }
        else if (strcmp(argv[1], "p") == 0)
        {
            fsrc = fopen(argv[2], "rb");
            if (fsrc == NULL)
                result = -1;
            else
            {
                result = command_p(fsrc);
                fclose(fsrc);
            }
        }
        else if (strcmp(argv[1], "s") == 0)
        {
            fsrc = fopen(argv[2], "r+b");
            if (fsrc == NULL)
                result = -1;
            else
            {
                result = command_s(fsrc);
                fclose(fsrc);
            }
        }
        else
        {
            printf("Not enough arguments");
            result = -1;
        }
    }
    if (result == -1)
        printf("Write error");

    if (result == -1)
        printf("Open error");

    return result;
}