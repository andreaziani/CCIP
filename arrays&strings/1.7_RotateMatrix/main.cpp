/*Write an algorithm to rotate by 90° a given NxN matrix */
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;
/* 
A smarter way to rotate a matrix is by implementing the rotation of layers 
(e.g. moving top edge to right edge, right edge to bottom edge and so on) 
Time complexity => O(N^2)
Space complexity => O(1)
*/
void rotate_layers(vector<vector<int> > &img, int N){
    for(int layer = 0; layer < N/2; layer++){ // there'll be N/2 layers 
        int first = layer; 
        int last = N - layer - 1;
        for(int i = first; i < last; i++){
            int offset = i - first; 
            int top = img[first][i]; // save top
            //left -> top
            img[first][i] = img[last - offset][first];
            // bottom -> left
            img[last-offset][first] = img[last][last - offset];
            //right -> bottom
            img[last][last - offset] = img[i][last];
            //top -> right
            img[i][last] = top;
        }
    }
    for(int i = 0 ; i < N; i++){
        cout << endl;
        for (int j = 0; j < N; j++)
            cout << img[i][j] << " ";
    }
}

/* A simple way to rotate a matrix is create a new one and copy the rotated values. 
This is a lot unefficient because takes O(N^2) memory and O(N^2) time */
void rotate_cpy(vector<vector<int> > &img, int N) 
{
    int tmp[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tmp[j][N - i - 1] = img[i][j];

    for (int i = 0; i < N; i++)
    {
        cout << endl;
        for (int j = 0; j < N; j++)
            cout << tmp[i][j] << " ";
    }
}

int main()
{
    vector<vector<int> > matrix(4, vector<int> (4));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            matrix[i][j] = i;
    }
    rotate_layers(matrix, 4);
}