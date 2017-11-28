#include <bits/stdc++.h>
#include <string.h>

class Node{
public:
  // Construction
  Node() { }
  Node(int d,int n) : distance(d), nextHop(n) {}

  // Getters
  int getDistance() const {return distance;}
  int getNextHop() const {return nextHop;}

  // Setters
  void setDistance(int val) {distance = val;}
  void setNextHop(int val) {nextHop = val;}
private:
  int distance;
  int nextHop;
};

int main(int argc, char *argv[]){
    int inputnode;
    int edge;
    std::cin >> inputnode >> edge;
    Node matriks[inputnode+1][inputnode+1];
    int i,j;
    //Inisialisasi matriks
    for(i=0;i<inputnode;i++){
        for(j=0;j<inputnode;j++){
            if(i==j){
                matriks[i][j].setDistance(0);
                matriks[i][j].setNextHop(i+1);
            }else{
                matriks[i][j].setDistance(-1);
                matriks[i][j].setNextHop(-1);
            }
            
        }
    }
    //Input ketetanggaan
    for(i=0;i<edge;i++){
        int source;
        int dest;
        std::cin >> source >> dest;
        matriks[source-1][dest-1].setDistance(1);
        matriks[source-1][dest-1].setNextHop(dest);
        matriks[dest-1][source-1].setDistance(1);
        matriks[dest-1][source-1].setNextHop(source);
    }

    int inputinfo;
    std::cin >> inputinfo;
    
    //UPDATE TABEL
    for(i=0;i<inputinfo;i++){
        int source;
        int dest;
        std::cin >> source >> dest;
        if(matriks[source-1][dest-1].getDistance()==1){
            for(j=0;j<inputinfo;j++){
                if((matriks[source-1][j].getDistance()!=0)&&(matriks[source-1][j].getDistance()!=-1)&&(j!=source-1)){
                    if((matriks[dest-1][j].getDistance()==-1)||(matriks[source-1][j].getDistance()<matriks[dest-1][j].getDistance())){
                        matriks[dest-1][j].setDistance(matriks[source-1][j].getDistance()+1);
                        matriks[dest-1][j].setNextHop(source);
                    }
                }
            }
        }
    }

    for(i=0;i<inputnode;i++){
        for(j=0;j<inputnode;j++){
            std::cout << matriks[i][j].getDistance() << " " << matriks[i][j].getNextHop() << '\n';
        }
    }

    return 0;
}