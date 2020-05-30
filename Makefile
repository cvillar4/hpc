CXX=icpc
CXXFLAGS=-xMIC-AVX512 -qopenmp -mkl -std=c++11
OPTRPT=-qopt-report=5

TARGET=main.cc

default: app

app : ${TARGET}
	${CXX} ${CXXFLAGS} ${OPTRPT} -o "$@" "$<"

clean:
	rm app *.o* *.e* 

