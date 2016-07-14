CC = g++
CFLAGS += -std=c++11

main : main.o quote.o bulk_quote.o
	$(CC) -o main main.o quote.o bulk_quote.o

main.o : main.cc quote.h bulk_quote.h
	$(CC) -c $(CFLAGS) main.cc
quote.o : quote.cc quote.h
	$(CC) -c $(CFLAGS) quote.cc
bulk_quote.o: bulk_quote.cc quote.h bulk_quote.h
	$(CC) -c $(CFLAGS) bulk_quote.cc

clean :
	rm main main.o quote.o bulk_quote.o
