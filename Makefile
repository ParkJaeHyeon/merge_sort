all: merge_sort

merge_sort.o : merge_sort.cpp
	g++ -c -o merge_sort.o merge_sort.cpp
merge_sort: merge_sort.o
	g++ -o merge_sort merge_sort.o
clean:
	rm -f *.o
	rm -f merge_sort

