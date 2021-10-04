//
//  main.c
//  GNL
//
//  Created by Arnette Reggie on 12/11/20.
//  Copyright © 2020 Arnette Reggie. All rights reserved.
//

#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    char    *line;
    int    fd;
    int red;
    fd =open("/Users/areggie/Desktop/Get_Next_Line_Tester/test/normal.txt", O_RDONLY);
    while ((red = get_next_line(fd, &line)) > 0 )
    {
        printf("%s  red = %d\n", line, red);
        free(line);
    }
    printf("%s  red = %d\n", line, red);
    free(line);
}
