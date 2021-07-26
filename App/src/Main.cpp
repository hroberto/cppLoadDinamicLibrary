
#include "DynamicLinkingLoader.h"

#include <iostream>
#include <pthread.h>

// #include <boost/filesystem.hpp>
// #include <boost/foreach.hpp>
// #include <boost/property_tree/json_parser.hpp>
// #include <boost/property_tree/xml_parser.hpp>



void * globalProperties = NULL;

//////////////////////////////////////////////////////////////////////////////
void load_aboutLibrary(const std::string & pathFile);

/**
 * \brief  
 */
int main(int argc, char** argv)
{
    if (argc != 2) {
        std::cout << "Parametros invalidos.  Necessario informar o caminha da Biblioteca." << std::endl;

	    return ( EXIT_FAILURE );
    }

    try {
        load_aboutLibrary( argv[1] );
    }
    catch( std::exception & e ) {
        std::cerr << e.what() << std::endl;
    }

	std::cout << std::endl;

	return ( EXIT_SUCCESS );
}



/**
 * \brief  Realiza o carregamento da biblioteca informada.
 * \param pathFile Caminho para o arquivo de biblioteca.
 */
void load_aboutLibrary(const std::string & pathFile)
{
     DynamicLinkingLoader dll( pathFile );

    std::cout << "Handler DLL  = " << dll.getHandler() << std::endl;


    // typedef const char* (*aboutCommit_t)();
    typedef const char* (*infoLibrary_t)();

    infoLibrary_t  ptr_getName = (infoLibrary_t) dll.getAddressSymbol( "getlibname" );
    infoLibrary_t  ptr_getVersion = (infoLibrary_t) dll.getAddressSymbol( "getlibversion" );
    infoLibrary_t  ptr_getDescription = (infoLibrary_t) dll.getAddressSymbol( "getlibdesc" );

    std::cout << "getlibname()  = " << ptr_getName() << std::endl;
    std::cout << "getlibversion()  = " << ptr_getVersion() << std::endl;
    std::cout << "getlibdesc()  = " << ptr_getDescription() << std::endl;
}
