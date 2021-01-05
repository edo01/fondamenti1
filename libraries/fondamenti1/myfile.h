#pragma once
/*
	Fondamenti di Informatica T1 - modulo di laboratorio
	Anno accademico 2020-2021

	Cognome nome: Carrà Edoardo
	Numero matricola: 0000970140
	numero esame:
*/
#ifndef MYFILE
#define MYFILE

#include <stdio.h>
#include "error.h"
#include "mystring.h"
#include "elementArray.h"

#define CR_C 1
#define EOF_C 2
#define SEP_C 3

/// <summary>
/// Save and read into the buffer until find sep, EOF or '\n'.
/// </summary>
/// <param name="buffer"></param>
/// <param name="dim"></param>
/// <param name="sep"></param>
/// <param name="f"></param>
/// <returns></returns>
int readField(char buffer[], int dim, char sep, FILE* f);

/// <summary>
/// Open the given file in mode "mode" and print an error message in case encounter an error.
/// </summary>
/// <param name="fileName"></param>
/// <param name="mode"></param>
/// <returns>
///		CR_C - if carriage return is the last char
///		EOF_C - if EOF is the last char
///		SEP_C  if the separating char is the last char
/// </returns>
FILE* openFile(char* fileName, char* mode);

/// <summary>
/// Open the given file in mode "mode" and print an error message in case encounter an error.
/// Also ignore all the chars into sep.
/// </summary>
/// <returns>
///		CR_C - if carriage return is the last char
///		EOF_C - if EOF is the last char
///		SEP_C  if the separating char is the last char
/// </returns>
int readField_ignoreChars(char buffer[], int dim, char ignoreChars[], int dimIgnore, char sep[], int dimSep, FILE* f);

#endif // !MYFILE


