#include <stdio.h>
#include <mpi.h>
//#include <iostream>

#include <vector>

using namespace std;

int main(int argc, char ** argv) {
    int rank, size;
    char name[80];
    int length;

    MPI_Init(&argc, &argv); // note that argc and argv are passed
                            // by address




    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Get_processor_name(name,&length);

    if(rank == 0) {
    	cin >> x;
    	cout << x << endl;
    }

    printf("Hello MPI: processor %d of %d on %s\n", rank,size,name);
    MPI_Finalize();
}