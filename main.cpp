#include <bits/stdc++.h>

class Node{
public:
  // Construction
  Node() { }
  Node(float d,float n) : distance(d), nextHop(n) {}

  // Getters
  float getDistance() const {return distance;}
  float getNextHop() const {return nextHop;}

  // Setters
  void setDistance(int val) {distance = val;}
  void setNextHop(int val) {nextHop = val;}
private:
  int distance;
  int nextHop;
};

std::vector<std::string> split(const std::string& s, char delimiter)
{
   std::vector<std::string> tokens;
   std::string token;
   std::istringstream tokenStream(s);
   while (std::getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

int main(int argc, char *argv[]){
    int inputnode;
    int edge;
    std::cin >> inputnode >> edge;
    Node matriks[inputnode+1][inputnode+1];
    int i,j;
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
    for(i=0;i<inputnode;i++){
        std::string input;
        std::cin >> input;
        std::vector<std::string> result = split(input,' ');
        for(std::string n : result) {
            int num = atoi(n.c_str());
            matriks[i][num-1].setDistance(1);
            matriks[i][num-1].setNextHop(num);
        }
    }
    /*
    for(i=0;i<inputnode;i++){
        for(j=0;j<inputnode;j++){
            std::cout << matriks[i][j].getDistance() << ' ';
        }
        std::cout <<'\n';
    }
    */

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

    std::cout <<'\n';
    for(i=0;i<inputnode;i++){
        for(j=0;j<inputnode;j++){
            std::cout << matriks[i][j].getDistance() << " " << matriks[i][j].getNextHop() << '\n';
        }
    }

    return 0;
}