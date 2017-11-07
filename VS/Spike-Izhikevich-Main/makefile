#filename Spike\Spike-Izhikevich-Main\makefile
# *** MACROS

CC = icpc
#CC = icpc
GCC = g++

INCPATH = -I/home/henk/sc/ScHJ/CWS -I/usr/lib/boost_1_58_0
OBJPATH = -L/home/henk/sc/ScHJ/CWS/Tools
#REPORT = -qopt-report=5 -qopt-report-phase=vec
REPORT =

CFLAGS_GCC 		= -O3 -Wall -Wunused-variable -std=c++14 -msse4.1 -fdiagnostics-color=always -fopenmp $(INCPATH)
LFLAGS_GCC 		= $(OBJPATH) -std=c++14 -fopenmp

CFLAGS_INTEL	= -fast -Wall -std=c++11 -openmp $(INCPATH) $(REPORT)
#CFLAGS_INTEL 	= -O3 -Wall -std=c++11 -openmp $(INCPATH) $(REPORT)
LFLAGS_INTEL 	= $(OBJPATH) -openmp

OBJS = /home/henk/sc/ScHJ/CWS/matio-1.5.2/libmatio.a

all: gcc
gcc: compile_gcc link_gcc
intel: compile_intel link_intel


compile_gcc:
	$(GCC) $(CFLAGS_GCC) -c Main-Spike-Izhikevich.cpp -o Main-Spike-Izhikevich.o

link_gcc:
	$(GCC) $(LFLAGS_GCC) Main-Spike-Izhikevich.o $(OBJS) -o Main-Spike-Izhikevich.out
	
	
compile_intel:
	$(CC) $(CFLAGS_INTEL) -c Main-Spike-Izhikevich.cpp -o Main-Spike-Izhikevich.o

link_intel: 
	$(CC) $(LFLAGS_INTEL) Main-Spike-Izhikevich.o -o Main-Spike-Izhikevich.out

#copy: 
#	sudo scp dpflops.out mic0:
#	sudo scp /opt/intel/composerxe/lib/mic/libiomp5.so mic0:/tmp

#run: 
#	@echo "do manually:"
#	@echo "export LD_LIBRARY_PATH=/tmp"
#	@echo "export KNP_AFFINITY=compact"
#	@echo "export OMP_NUM_THREADS=228"
#	@echo "./dpflops.out"
#	@echo "exit"
#	sudo ssh mic0


clean: 
	@-rm -f Main-Spike-Izhikevich.out Main-Spike-Izhikevich.o
	@-rm -f *.optrpt
