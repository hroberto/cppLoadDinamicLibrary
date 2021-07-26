/*
 * DynamicLinkingLoader.cpp
 *
 *  Created on: 24/10/2019
 *  Author: Henrique Martins Roberto
 */

#include "DynamicLinkingLoader.h"
#include <iostream>

#include <dlfcn.h>
#include <sstream>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>


#ifdef __cplusplus
    extern "C" {
#endif



////////////////////////////////////////////
DynamicLinkingLoader::DynamicLinkingLoader()
: _handleLibrary( NULL )
{
}

/**
 * \brief Construtor
 * \param pathLibrary  Caminho para o arquivo de Biblioteca.
 */
DynamicLinkingLoader::DynamicLinkingLoader(const std::string & pathLibrary)
: _handleLibrary( NULL )
{
    this->open( pathLibrary );
}


/**
 * \brief Destructor
 */
DynamicLinkingLoader::~DynamicLinkingLoader()
{
    if ( isOpen() ) {
        close();
    }
}

/**
 * \brief Faz o carregamento do arquivo de biblioteca informada para o sistema.
 * \param pathLibrary  Caminho para o arquivo de Biblioteca.
 */
void DynamicLinkingLoader::open( const std::string & pathLibrary ) throw(DynamicLinkingLoaderException)
{
    if ( isOpen() ) {
        close();
    }

    boost::filesystem::path __path = pathLibrary;
    if( boost::filesystem::is_symlink( __path ) )
    {
        //sempre retorna o nome completo do symbolic link
    	__path = boost::filesystem::canonical( __path );

    }

    _handleLibrary = dlopen(__path.c_str(), RTLD_LAZY);

    if (! _handleLibrary ) {
        std::stringstream ss;
        ss << "open | " << dlerror();

        throw DynamicLinkingLoaderException( ss.str() );
    }

    _pathLibrary = __path.c_str();
}


/**
 * \brief Fecha o arquivo no sistema.
 */
void DynamicLinkingLoader::close() throw(DynamicLinkingLoaderException)
{
    if ( isOpen() ) {
        return;
    }

    dlclose(_handleLibrary);

    char *error;
    if ((error = dlerror()) != NULL)
    {
        std::stringstream ss;
        ss << "close | " << error;

        throw DynamicLinkingLoaderException( ss.str() );
    }

    _handleLibrary = NULL;
    _pathLibrary.clear();
}



/**
 * \brief
 */
void* DynamicLinkingLoader::getAddressSymbol( const std::string & __nameSymbol )  throw(DynamicLinkingLoaderException)
{
    void* ptrFunc = dlsym(_handleLibrary, __nameSymbol.c_str() );

    char *error;
    if ((error = dlerror()) != NULL)
    {
        std::stringstream ss;
        ss << "getAddressSymbol | " << error;

        throw DynamicLinkingLoaderException( ss.str() );
    }

    return ( ptrFunc );
}


#ifdef __cplusplus
}
#endif
