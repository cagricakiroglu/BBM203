#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include "main.h"
using namespace std;
int directionDecider(int totalOfThisMatrix){
    int modulo= totalOfThisMatrix%5;
    int direction=0;
    // i'm checking is it at the end of the matrix by checker integer if its 1 thats mean we are at limit
    
 

    if(modulo==4){//this means is left
        
        direction=4;    
        
    
    }
     else if(modulo==2){ //this means is down
        
      
        direction=2;
        
     }
        
     
      else if(modulo==3){//this means is right
        
        direction=3;
        
      } 
       else if(modulo==1){//this means is up
        
        direction=1;
        
       }

       else{
        direction=9;
       }

       return direction; 
}
int* CoreChanger(int* CoreArray,int direction ,int numOfKeyRowAndColumnofMatrix ,int row,int column){
    // 1 up ,2 go down ,3 go right ,4 go left 

    int rowP= CoreArray[0];
    int colP= CoreArray[1];

   


    int inc_num = ((numOfKeyRowAndColumnofMatrix/2));
    int dec_num = -((numOfKeyRowAndColumnofMatrix/2));

    if(direction==1){ //up
        if(rowP-inc_num==0 || rowP-numOfKeyRowAndColumnofMatrix<0 ){
            CoreArray[0]=rowP+numOfKeyRowAndColumnofMatrix;
        }
        else{
        CoreArray[0]=rowP-numOfKeyRowAndColumnofMatrix;
        }
    }
    if(direction==2){ // down
        if(rowP+inc_num==0 || rowP+numOfKeyRowAndColumnofMatrix>row){
             CoreArray[0]=rowP-numOfKeyRowAndColumnofMatrix;
        }
        else{
        CoreArray[0]=rowP+numOfKeyRowAndColumnofMatrix;
        }

    }

    if(direction==3){ //right
       if(colP+inc_num==0 || colP+numOfKeyRowAndColumnofMatrix>column){
             CoreArray[1]=colP-numOfKeyRowAndColumnofMatrix;
        }
        else{
        CoreArray[1]=colP+numOfKeyRowAndColumnofMatrix;
        }

    }
    if(direction==4){//left
       if(colP-inc_num==0 || colP-numOfKeyRowAndColumnofMatrix<0){
             CoreArray[1]=colP+numOfKeyRowAndColumnofMatrix;
        }
        else{
        CoreArray[1]=colP-numOfKeyRowAndColumnofMatrix;
        }
    }

    return CoreArray;

}

    
void printerFunc(int rowP, int colP, int total,int printCounter,stringstream *outputstring,ofstream &myfile){
 
        myfile<< rowP<< ","<< colP <<":" << total<<  endl;

}

int** read_makeGrid(int row, int column,stringstream *mapsmatrix ){

    std::fstream map_file; // Starts to reading 
    
    map_file.open((*mapsmatrix).str().c_str());


int **dynamicArray = new int*[row];    // Creating 2D Array
for (int i=0 ; i < row ; i++){
    dynamicArray[i]= new int[column];

    for(int j = 0 ; j< column; j++){
        map_file >>  dynamicArray[i][j];  
    }

}
return dynamicArray;

 }

void deleteArray(int** dynamicArray,int row){
  
    for (int i=0 ; i < row ; i++){// For memory , i'm deleting arrays
    delete[] dynamicArray[i];
}
    delete[] dynamicArray;
}

int** getKeyMatrix(int num,stringstream *keysmatrix) {

    
    fstream key_map_file; // Starts to reading 
    key_map_file.open((*keysmatrix).str().c_str());
  

    int **key_dynamicArray = new int*[num]; // Here i'm creating second 2d array for keymatrix
    for (int i=0 ; i < num ; i++){
    key_dynamicArray[i]= new int[num];

    for(int j = 0 ; j< num; j++){

        key_map_file >>  key_dynamicArray[i][j];
        
    }
}

return key_dynamicArray;

}

void gameFunc(int** dynamicArray,int** key_dynamicArray,int* CoreArray,int num,int row , int column,int printCounter,stringstream *outputstring,ofstream &myfile){

    int rowP=CoreArray[0];        // in here , i'm getting core position 
    int colP=CoreArray[1];

    int inc_num = ((num/2));        // in here, i'm deciding how many square i will go up go down and left and rightside
    int dec_num = -((num/2));

    int totalOfThisMatrix=0;
    int checker;
    int onebyone;
    
    for(int i = dec_num  ; i < inc_num+1 ; i++ ){
        
        
        for(int j =dec_num ; j < inc_num+1 ; j++){

            onebyone = ((dynamicArray[rowP+i][colP+j])*(key_dynamicArray[inc_num+i][inc_num+j]));
            totalOfThisMatrix= onebyone+ totalOfThisMatrix;
        }
        
    }
    while(totalOfThisMatrix<0){
        totalOfThisMatrix=totalOfThisMatrix+5;
    }


     printerFunc(rowP,colP,totalOfThisMatrix,printCounter,outputstring,myfile);
    int direction = directionDecider(totalOfThisMatrix);
   
        printCounter++;
        int* Core2Array = CoreChanger(CoreArray,direction,num,row ,column);
        
        if(direction !=9){
        gameFunc(dynamicArray,key_dynamicArray,Core2Array,num,row,column,printCounter,outputstring,myfile);
        }
        if(direction==9){
            
        }
    
}

int main(int argc, char** argv){


ifstream map_file; // Starts to reading 
    map_file.open( argv[3]);

int num;

std:stringstream strToint;
strToint << argv[2];
 strToint >> num ;

std::string input ;
std::stringstream commandinput(argv[1]); // getting command line arguments in here
std::string token;

std::stringstream mapsmatrix(argv[3]);
std::stringstream keysmatrix(argv[4]);
std::stringstream outputstring(argv[5]);


std::ofstream myfile;
myfile.open((outputstring).str().c_str());

int inputarray[2];
int i;

while(std::getline(commandinput, token, 'x')) {
    stringstream temp;

    temp << token ;
    temp >> inputarray[i];
    i++;

}

 int  row= inputarray[0];
 int column= inputarray[1];

map_file.close();

int** dynamicArray =read_makeGrid(row,column,&mapsmatrix);

int** key_dynamicArray= getKeyMatrix(num,&keysmatrix);

int CoreArray[]={num/2,num/2};


int printCounter=0;

gameFunc(dynamicArray,key_dynamicArray,CoreArray,num,row,column,printCounter,&outputstring,myfile);

deleteArray(dynamicArray,row);
}













    