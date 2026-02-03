CC=g++
FLAGS= -O3 -c
SRC=tests

include makefrag.mk

${SRC}: ${SRC}.o 
	${CC} $< -D${MODE} -DCONFIG=${CONFIG} ${VERILATED_O} ${MESH_MODULE} -o bin/${CONFIG}
	rm *.o

${SRC}.o: ${SRC}.cpp headers/MxM.cpp headers/Gemmini.h headers/MxM.h
	echo "Compiling config " ${CONFIG}
	${CC} ${FLAGS} -D${MODE} -D${FI_LEVEL} -DCONFIG=${CONFIG} -I${VERILATOR_INC_PATH} $< -o $@

clean:
	rm bin/${CONFIG}

