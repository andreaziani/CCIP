/*Write an algorithm that if an element of an MxN matrix is 0, its entire row and col are set to 0*/
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void printMatrix(vector<vector<int> > & matrix, int M, int N){
    for (int i = 0; i < M; i++)
    {
        cout << endl;
        for (int j = 0; j < N; j++)
            cout << matrix[i][j] << " ";
    }
}

/* We use two arrays to keep track of all the rows and cols with zeros, then nullify rows and cols based on these arrays*/
void zeroMatrix(vector<vector<int> > & matrix, int M, int N){
    int cols[N];
    int rows[M];

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++)
            if(matrix[i][j] == 0){
                cols[j] = 1;
                rows[i] = 1;
            }
    }

    for(int j = 0; j < N; j++)
        if(cols[j] != 0)   
            for(int i = 0; i < M; i++) // modify rows
                matrix[i][j] = 0;
    for(int i = 0; i < M; i++)
        if(rows[i] != 0)           
        for(int j = 0; j < N; j++) // modify rows
            matrix[i][j] = 0;      

}

int main(){
    int M = 4;
    int N = 5;
    vector<vector<int> > matrix(M, vector<int> (N));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            matrix[i][j] = i;
    }
    printMatrix(matrix, M, N);
    zeroMatrix(matrix, M, N);
    printMatrix(matrix, M, N);
}