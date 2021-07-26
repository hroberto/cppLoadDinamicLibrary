/*
 * DynamicLinkingLoader.h
 *
 *  Created on: 24/10/2019
 *  Author: Henrique Martins Roberto
 */

#ifndef _DYNAMICLINKINGLOADER_H_
#define _DYNAMICLINKINGLOADER_H_

#include <string>
#include <stdexcept>

#ifdef __cplusplus
extern "C" {
#endif


typedef std::logic_error					DynamicLinkingLoaderException;

class DynamicLinkingLoader {
public:
    DynamicLinkingLoader();
    DynamicLinkingLoader(const std::string & __pathLibrary);
    virtual ~DynamicLinkingLoader();

    void open( const std::string & __pathLibrary )  throw(DynamicLinkingLoaderException);
    void close() throw(DynamicLinkingLoaderException);
    

    bool isOpen() const { return ( ! _handleLibrary ); }

    void* getHandler() const { return ( _handleLibrary ); }
    const std::string & getPath() const { return ( _pathLibrary ); }
    void* getAddressSymbol( const std::string & __nameSymbol ) throw(DynamicLinkingLoaderException);

private:
    void *_handleLibrary;
    std::string _pathLibrary;
};

#ifdef __cplusplus
}
#endif

#endif // _DYNAMICLINKINGLOADER_H_
