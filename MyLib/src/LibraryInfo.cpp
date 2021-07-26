/*
 * LibraryInfo.cpp
 *
 *  Created on: 24/10/2019
 *  Author: Henrique Martins Roberto
 */

#include "LibraryInfo.h"

/**
 * \brief Retorna a descricao de ajuda com resumo sobre a biblioteca.
 * \return texto
 * \info Nome especifico do metodo (Handler) a ser carregado dinamicamente.
 **/
extern "C"
void helpLibrary(std::ostream& __ostream, const std::string & __ident)
{
    __ostream << __ident
    << "Biblioteca [" << getlibname() << "]"
    << "Version [" << getlibversion() << "]"
    << "Description [" << getlibdesc() << "]"
    << std::endl;
}


/**
 * \brief Retorna a versao sobre a biblioteca.
 * \return texto
 * \info Nome especifico do metodo (Handler) a ser carregado dinamicamente.
 **/
extern "C"
const char* getlibversion()
{
    return ( "X.X.X" );
}


/**
 * \brief Retorna a descricao sobre a biblioteca.
 * \return texto
 * \info Nome especifico do metodo (Handler) a ser carregado dinamicamente.
 **/
extern "C"
const char* getlibname()
{
    return ( "myLibraryDinamic" );
}

/**
 * \brief Retorna a descricao sobre a biblioteca.
 * \return Descricao da biblioteca.
 * \info Nome especifico do metodo (Handler) a ser carregado dinamicamente.
 **/
extern "C"
const char* getlibdesc()
{
    return ( "Minha  biblioteca." );
}
