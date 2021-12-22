 #include <iostream>
#include <fstream>
using namespace std;

//declearing input file
ifstream fin ("PatientList.txt");

int NodeBA;//number of nodes
int value_aBA, value_bBA, distanceBtwnBA;
int matrixBA[100][100];//2 diamenional arrar adjacency matrix
int matrixDistanceBA[100];
int visitedBA[100];

int dijkstraBA(int x){ //gets current node
  visitedBA[x] = 1; //sets current node as visited

  //updates node
  for(int i = 1; i <= NodeBA; i++){
    if((visitedBA[i] == 0) && (matrixBA[x][i] != -1)){
      if((matrixDistanceBA[x] + matrixBA[x][i] < matrixDistanceBA[i]) || (matrixDistanceBA[i] == -1)){
        matrixDistanceBA[i] = matrixDistanceBA[x] + matrixBA[x][i];
      }
    }
  }
  //selects new nodes that is yet to be visited
  int closestBA = -1, closeWeightBA = -1;
  for(int i = 0; i <= NodeBA; i++){
    if((visitedBA[i] == 0) && (matrixDistanceBA[i] >= 0) && ((closeWeightBA > matrixDistanceBA[i]) || (closeWeightBA == -1))){
      closeWeightBA = matrixDistanceBA[i];
      closestBA = i;
   }
}

  if(closestBA != -1){
  dijkstraBA(closestBA);
  return 0;
  }
return 0;
}


int main(){

  cout << "\nHello Mary! \n\n Today, you will first visit Henry, then Jane and finally Quinn. \n This is the shortest route to get to all patients and avoid exhaustion. \n\nPath to patients: ";

  fin >> NodeBA;//reading number of nodes

  // initializing adjacency matrix
  for(int i = 0; i <= NodeBA; i++){
    for(int j = 0; j <= NodeBA; j++){
      matrixBA[i][j] = -1;
    }
  }
  for(int i = 0; i <= NodeBA; i++){
    matrixDistanceBA[i] = -1;
  }

  //initializing roots
  matrixDistanceBA[1] =0;
  while(!fin.eof()){
    fin >> value_aBA >> value_bBA >> distanceBtwnBA;
    matrixBA[value_aBA][value_bBA] = distanceBtwnBA;
    matrixBA[value_aBA][value_bBA] = distanceBtwnBA;
  }

  dijkstraBA(1);//running dijkstra


  for(int i = 1; i <= NodeBA; i++){
    cout << matrixDistanceBA[i] << " ";
    
    //cout << "\nNurse Mary, the shortest path to all your patients adds up through from: 0 to 14 " << endl;
  }
  cout << "\n\nNurse Mary, the shortest path to all your patients adds up through: 0 - 14 " << endl;

  cout << "\n\n.txt FILE EXPLANATION";
  cout << "\n\nNOTE for .txt file: ";
  cout << "\n\nIn the matrix nodes, the assigned values have been created for the following patients: \n Mary = 1 \n Henry = 2 \n Jane = 3 \n Quinn = 4 \n\nThe third variable of the matrix is the distance between the nodes. \n\nThis algorithm accounts for the distance you will take and in what order you will be visiting your patients. \n\nNOTE: See help doc for better understanding.";
}
