# cppLoadDinamicLibrary
Modelo de projeto para trabalhar com bibliotecas Dinamicas em LINUX, ou seja, bibliotecas informadas durante o processo de execução.

## Referencias complementares

- [C++ dlopen mini HOWTO](https://tldp.org/HOWTO/pdf/C++-dlopen.pdf)

## INFORMACOES DO AUTOR

> **Data Criacao:** 27/06/2021
> **Autor:** HENRIQUE MARTINS ROBERTO
> **E-mail:** henrique.roberto@gmail.com

# SOBRE O AMBIENTE DE DESENVOLVIMENTO

O desenvolvimento foi realizado na plataforma LINUX, com o compilador GNU. Portanto, para possibilitar a utilizacao e teste pelo avaliador, o ambiente a seguir foi documentado utilizando o DOCKER.

# CRIACAO DO AMBIENTE DOCKER PARA DESENVOLVIMENTO

> PS: Antes de iniciar os passos abaixo, verifique as configuracoes de DNS em /etc/docker/daemon.json, e caso necessario, inclua o IP "8.8.8.8" no mesmo.


```sh
    ## Construindo a nova imagem
    docker build -t  el8-hmartins:1.00 .

    ## Executando a imagem montada
    docker run --rm -it --name el8-hmartins  --cpus 1 -v ${PWD}:/opt/workspace  el8-hmartins:1.00  /bin/bash

    ## compilando a biblioteca especifica
    cd MyLib/ ; make -s

    ## compilando a aplicacao
    cd ../App/; make -s

    ## executando o programa
    ./bin/loaderLib  ../MyLib/lib/hello.so.1
 ```

> **OUTPUT ./bin/loaderLib**
```sh
Handler DLL  = 0x1e5e840
getlibname()  = myLibraryDinamic
getlibversion()  = X.X.X
getlibdesc()  = Minha  biblioteca.
```
