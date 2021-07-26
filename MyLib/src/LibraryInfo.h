/*
 * LibraryInfo.h
 *
 *  Created on: 26/11/2019
 *  Author: Henrique Martins Roberto
 */

#ifndef LIBRARYUTILS_H_
#define LIBRARYUTILS_H_

#include <iostream>


extern "C"  void helpLibrary(std::ostream& __ostream, const std::string & __ident = "");

extern "C"  const char* getlibversion();
extern "C"  const char* getlibname();
extern "C"  const char* getlibdesc();


#endif /* LIBRARYUTILS_H_ */
