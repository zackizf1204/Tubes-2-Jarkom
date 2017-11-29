#include <bits/stdc++.h>

int main(int argc, char *argv[]){
    int inputnode;
    int edge;
    std::cin >> inputnode >> edge;
    int distance[inputnode][inputnode];
    int nextHop[inputnode][inputnode];
    int i,j;


    //INISIALISASI MATRIKS
    for (int i = 0; i < inputnode; i++){
        for (int j = 0; j < inputnode; j++){
            distance[i][j] = -1;
            nextHop[i][j] = -1;
        }      
    }
  
    //INPUT KETETANGGAAN (EDGE)
    if(inputnode>edge){
        for(i=0;i<inputnode;i++){
            distance[i][i]=0;
            nextHop[i][i]=i+1;
            if(i<edge){
                int source;
                int dest;
                std::cin >> source >> dest;
                distance[source-1][dest-1]=1;
                nextHop[source-1][dest-1]=dest;
                distance[dest-1][source-1]=1;
                nextHop[dest-1][source-1]=source;
            }
        }
    }
    else{
        for(i=0;i<edge;i++){
        int source;
        int dest;
        std::cin >> source >> dest;
        if(i<inputnode){
            distance[i][i]=0;
            nextHop[i][i]=i+1;
        }
        distance[source-1][dest-1]=1;
        nextHop[source-1][dest-1]=dest;
        distance[dest-1][source-1]=1;
        nextHop[dest-1][source-1]=source;
        }
    }

    int inputinfo;
    std::cin >> inputinfo;
    
    //UPDATE TABEL
    for(i=0;i<inputinfo;i++){
        int source;
        int dest;
        std::cin >> source >> dest;
        for(j=0;j<inputnode;j++){
            if((distance[source-1][j]>0)&&(distance[source-1][j]<distance[dest-1][j])){
                if((distance[source-1][j]<(distance[dest-1][j]-1))||(source<nextHop[dest-1][j])){
                    distance[dest-1][j]=distance[source-1][j]+1;
                    nextHop[dest-1][j]=source;
                }
            }
            else{
                if((distance[source-1][j]>0)&&(distance[dest-1][j]==-1)){
                    distance[dest-1][j]=distance[source-1][j]+1;
                    nextHop[dest-1][j]=source;
                }
            }
        }
    }

    //TAMPILKAN HASIL
    for(i=0;i<inputnode;i++){
        for(j=0;j<inputnode;j++){
            std::cout << distance[i][j] << " " << nextHop[i][j] << '\n';
        }
    }
    return 0;
}