.SUFFIXES:
.SUFFIXES: .o .ec .cpp

pathprj=${PWD}
dirAplicacao=$(pathprj)/bin
dirBiblioteca=$(pathprj)/lib

LIB_NAME=hello
VERSION_MAJOR=1
pathBiblioteca=$(dirBiblioteca)/$(nomeBiblioteca).so



GCC_VERSION_C11 := $(shell expr `g++ -dumpversion | cut -f1-2  -d.` \>= 4.8 )

ifeq ($(GCC_VERSION_C11),1)
   CC = g++ -std=c++11 -Wall -Werror -rdynamic
else
	CC = g++ -std=c++98 ${GCC_VERSION} -Wall -Werror -rdynamic
endif

SO_KERNEL_NAME	= $(shell uname)
SO_PLATAFORM	= $(shell uname -i)

AR = ar

DIR_SRC= ./src/

#-----------------------------------------------------
#Diretorios dos arquivos header (.h) do ESPECIFICO
#-----------------------------------------------------
INCLUDE_DIR	  =  -I$(DIR_SRC)


#-----------------------------------------------------
#Especifico
#-----------------------------------------------------
SRCS_CPP    = $(shell ls $(DIR_SRC)/*.cpp 2> /dev/null)
OBJS 		= $(SRCS_CPP:.cpp=.o)

ifeq ($(SO_KERNEL_NAME),Linux)
	LIB_SYS 		= -lpthread -ldl -lcrypt -lc
else
	LIB_SYS			= <<especificar para o SO>>
endif


ifdef LIB_NAME
	nomeBibliotecaMajor=$(dirBiblioteca)/$(LIB_NAME).so.$(VERSION_MAJOR)
	nomeBiblioteca=$(dirBiblioteca)/$(LIB_NAME).so
	nomeAplicacao=$(nomeBiblioteca)

	FLAGS = -fPIC  -shared -Wl,-soname,$(LIB_NAME).so.$(VERSION_MAJOR)

	#Link das Bibliotecas
	LINK   = $(LIB_SYS) \
			-L${BASE_BOOST_LIBS} -lboost_filesystem -lboost_system -lboost_date_time -lboost_regex -lboost_thread -lboost_program_options -lboost_locale -lboost_chrono \
			$(FLAGS) 


else
#Link das Bibliotecas
LINK	= $(LIB_SYS) \
		-L${BASE_BOOST_LIBS} -lboost_filesystem -lboost_system -lboost_date_time -lboost_regex -lboost_thread -lboost_program_options -lboost_locale -lboost_chrono
endif

.cpp.o:
	@echo "Compilando >>> $<"
	$(CC) $(FLAGS)  -Wno-deprecated  $(INCLUDE_DIR) -c $< -o $@

all: $(OBJS)
	@echo "------------------------------------------------------------------------------"
	@[ -d $(nomeAplicacao) ] || mkdir $(nomeAplicacao)

	@echo "Criando biblioteca <$(dirBiblioteca)>"
	@rm -fr $(nomeAplicacao)
	$(CC)  $(LINK) -o $(nomeBibliotecaMajor) $?

	@ln -sf $(nomeBibliotecaMajor) $(nomeBiblioteca)

	@chmod 770 $(nomeBibliotecaMajor)
	@echo "<<<<<< Feito >>>>>>"
	@echo "------------------------------------------------------------------------------"

local: $(OBJS)
	@echo "----------------------------------------"
	@echo "Criando autorizador <$(nomeAplicacao)>"
	@rm -f $(nomeAplicacao)
	@$(CC) $?  $(LINK) -o $(nomeAplicacao)
	@chmod 770 $(nomeAplicacao)
	@echo "<<<<<< Feito >>>>>>"
	@echo "----------------------------------------"

clean:
	@echo "-------------------------------------------------"
	@echo "Apagando Objs/dependencias de <$(nomeAplicacao)>"
	rm -f $(OBJS:.o=.d) $(OBJS) core* $(nomeAplicacao) $(nomeBibliotecaMajor)
	@echo "<<<<<< Feito >>>>>>"
	@echo "-------------------------------------------------"

-include $(OBJS:.o=.d)
