/*
 ============================================================================
 Name        : GPClientSample.c
 Author      : Jorge Freitas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "Console/Console.h"

int main(int argc, char *argv[])
{
    Console console;

    if(argc > 1)
    {
    	std::string cmd(argv[1]);
    	for(int i = 2; i < argc; i++)
    	{
    		cmd += " " ;
    		cmd.append(argv[i]);
    	}

    	console.ProcessCommand(cmd);
    }
    else
    {
    	console.Execute();
    }
    return 0;
}

