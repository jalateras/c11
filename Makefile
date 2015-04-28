SOURCES_DIR      = ./src
TARGET           = ./target
CHAPTER1_EXEC    = $(TARGET)/chapeter1
SORT_EXEC        = $(TARGET)/sort
VOPTION_EXEC 		 = $(TARGET)/voption
SMATRIX_EXEC 		 = $(TARGET)/smatrix
FPTR_EXEC   		 = $(TARGET)/fptr
FCTOR_EXEC   		 = $(TARGET)/fcotr
PRICE_EXEC			 = $(TARGET)/pricing
AFOPT_EXEC			 = $(TARGET)/afoptions
EXAMPLE_EXEC		 = $(TARGET)/example
FFT_EXEC				 = $(TARGET)/fft

COMPILER         = -c++
OPTIMIZATION_OPT = -O2 -O3
INCLUDE_DIR      = -I $(SOURCES_DIR)
BASE_OPTIONS     = -std=c++11
OPTIONS          = $(BASE_OPTIONS) $(OPTIMIZATION_OPT) $(INCLUDE_DIR)
LINKER_OPT       = -L/usr/lib -L/usr/local/lib -lstdc++ -lafcuda


all: chapter1 afexample

chapter1: $(CHAPTER1_EXEC)
	$<

$(CHAPTER1_EXEC): $(SOURCES_DIR)/chapter1.cpp
	$(COMPILER) $(OPTIONS) $(LINKER_OPT) -o $@ $<

sort: $(SORT_EXEC)
	$<

$(SORT_EXEC): $(SOURCES_DIR)/sort.cpp
	$(COMPILER) $(OPTIONS) $(LINKER_OPT) -o $@ $<

voption: $(VOPTION_EXEC)
	$<

$(VOPTION_EXEC): $(SOURCES_DIR)/voption.cpp $(SOURCES_DIR)/voption.hpp
	$(COMPILER) $(OPTIONS) $(LINKER_OPT) -o $@ $<

smatrix: $(SMATRIX_EXEC)
	$<

$(SMATRIX_EXEC): $(SOURCES_DIR)/smatrix.cpp $(SOURCES_DIR)/smatrix.hpp
	$(COMPILER) $(OPTIONS) $(LINKER_OPT) -o $@ $<

fptr: $(FPTR_EXEC)
	$<

$(FPTR_EXEC): $(SOURCES_DIR)/fptr.cpp
	$(COMPILER) $(OPTIONS) $(LINKER_OPT) -o $@ $<

fctor: $(FCTOR_EXEC)
	$<

$(FCTOR_EXEC): $(SOURCES_DIR)/functor.cpp
	$(COMPILER) $(OPTIONS) $(LINKER_OPT) -o $@ $<

pricing: $(PRICE_EXEC)
	$<

$(PRICE_EXEC): $(SOURCES_DIR)/pricing.cpp
	$(COMPILER) $(OPTIONS) $(LINKER_OPT) -o $@ $<

afoptions: $(AFOPT_EXEC)
	$<

$(AFOPT_EXEC): $(SOURCES_DIR)/afoptions.cpp
	$(COMPILER) $(OPTIONS) $(LINKER_OPT) -o $@ $<

example: $(EXAMPLE_EXEC)
	$<

$(EXAMPLE_EXEC): $(SOURCES_DIR)/example.cpp
	$(COMPILER) $(OPTIONS) $(LINKER_OPT) -o $@ $<

fft: $(FFT_EXEC)
	$<

$(FFT_EXEC): $(SOURCES_DIR)/fft.cpp
	$(COMPILER) $(OPTIONS) $(LINKER_OPT) -o $@ $<

clean:
	rm -f target/*

.PHONY: clean all