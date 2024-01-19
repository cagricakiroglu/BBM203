#include <iostream>
#include "Time.h"
#include "Cashier.h"
#include "Barista.h"
#include <fstream>
#include <algorithm>
#include <stdio.h>


using namespace std;


// here , to hold turnaround times i need to create a vector that holds double and double so defined 
// as <double,double>
typedef pair <double,double> double_double;

int main(int argc,char** argv){
    
    int cashiersayisi;
    int ordersayisi;

    //there are global Time class that holds the process according to their times
    // i sort them according to their time
    Time Model_1;
    Time Model_2;

    FILE *f = fopen(argv[2], "w");

    vector<Barista> busyBaristas;
    vector<double_double> turnaround;
    //these are two vector one of them holds the baristas in  it
    //second one holds the turnaround times
 

    fstream inputFile(argv[1]);
    //ofstream outputFile= ofstream("output.txt");

    inputFile >> cashiersayisi; 
    inputFile >> ordersayisi;
    

    busyBaristas.push_back(Barista(cashiersayisi/3));
    // i created n/3 barista and i append them into busyBarista vector

    for(int m = 0; m< ordersayisi ; m++){

        double first;
        inputFile>>first;
         double second;
        inputFile>>second;
         double third;
        inputFile>>third;
         double forth;
        inputFile>>forth;


        // The Event class seems like the process they have attributes 
        // I sort event by their first info (inside the function its sort info) 
        //here i append the events to the model1 and model2

        Model_1.AppendEvent(Event("comer",first,first,second,third,forth));

        Model_2.AppendEvent(Event("comer",first,first,second,third,forth));

    }
   
   
   
    
    

    Cashier CashierForFirst(cashiersayisi);
    Cashier CashierForSecond(cashiersayisi);
    //i created cashier for 2 models
  
    double total_time=0;
//its a total running time
    
  

    while(  !Model_1.isEmpty()  ){
     
        
        

        Event popped=Model_1.getNext();
        // i get the next process from queue
       
        
        
        total_time=popped.sort;
        

        string str_type=popped.eventtype;
       
        
        
        if(str_type=="comer"){
        //if customer comes
         
      
        CashierForFirst.appendQueue(popped);
     
        }

   
    if(str_type=="Finished"){
         //if customer process done by cashier
    
            CashierForFirst.finished( (int)popped.f_info);


            busyBaristas[0].appendQueue(Event("NULL",popped.t_info,popped.TimeForEvent,popped.f_info,popped.s_info,popped.t_info));

            // i send the price price as a sort value in barista PriorityQueue (expensive one gets first serve)
    }
    if(str_type=="CoffeeFinished"){
        
      //if customer coffee done by barista
        busyBaristas[0].finished( (int) popped.s_info);


        turnaround.push_back(double_double( popped.TimeForEvent , popped.sort));
    }
        
      
       
    while(!CashierForFirst.isEmpty() && CashierForFirst.avail()){

           
        // in here i take order
            Event new_Event=CashierForFirst.Order(popped.sort);
            Model_1.AppendEvent(new_Event);
        }
 


    while (!busyBaristas[0].isEmpty()&& busyBaristas[0].avail())
        
        {
             
         // in here i make coffee
            Event new_Event=busyBaristas[0].coffee(popped.sort);
            Model_1.AppendEvent(new_Event);
            
        }
 
           
          
        }


        fprintf(f,"%.2lf\n",total_time);
        fprintf(f,"%d\n",CashierForFirst.Max_len);
        fprintf(f,"%d\n",busyBaristas[0].Max_len);
        int i= 1;
        while(i<=cashiersayisi){
            fprintf(f,"%.2f\n",CashierForFirst.busytime[i]/total_time) ;
            i++;
    
        }
        i=1;
        while(i<=cashiersayisi/3){
            fprintf(f,"%.2f\n",busyBaristas[0].busytime[i]/total_time) ;
            i++;
        }

        sort(turnaround.begin(),turnaround.end());

        i=0;
        while(i<(int) turnaround.size()){
            fprintf(f,"%.2f\n",turnaround[i].second-turnaround[i].first) ;

            i++;
        }

        /*
        ********************************************************************************
        //MODEL 2 STARTS HERE
        ********************************************************************************
        */



        int m =1;
         turnaround.clear();
        

        //in here like if there is 6 cashier so we need 3 barista quque
        // so i create a 1 barista in each queue
        while(m<= cashiersayisi/3){
           
            busyBaristas.push_back(Barista(1));
            m++;
        }
    

        // again second_turnaorund is a vector that holds 2 variable as double and double
        vector<double_double> second_turnaround;
        
        //its a runtime 
        double runtime=0;


        while (!Model_2.isEmpty())
        {
            
            Event popped= Model_2.getNext();
              // i get the next process from queue


            runtime=popped.sort;
            string type= popped.eventtype;


            int x=(int)popped.f_info;
            // to decide which process will be appended to whom queue
            // every 3 cashier sends to 1 barista 
            // so there is like calculation (x+2)/3
            // to decide which barista will take it 
            

            if(type=="comer"){
                CashierForSecond.appendQueue(popped);
                //if customer comes

            }
            if(type=="Finished"){
                CashierForSecond.finished( (int) popped.f_info);
                //if customer process done by cashier
                
                busyBaristas[(x+2)/3].appendQueue( Event("NULL",popped.t_info,popped.TimeForEvent,popped.f_info,popped.s_info,popped.t_info));
            }
            if(type=="CoffeeFinished"){
                   //if customer coffee done by barista
                busyBaristas[(x+2)/3].finished(popped.s_info);
                second_turnaround.push_back(double_double(popped.TimeForEvent,popped.sort));

            }

            while(!CashierForSecond.isEmpty() && CashierForSecond.avail()){
                Event ordered_popped=CashierForSecond.Order(popped.sort);
                Model_2.AppendEvent(ordered_popped);
                // in here i take order
            }
             
             int m=1;

            
            while(m<=cashiersayisi/3){
                while( !busyBaristas[m].isEmpty() && busyBaristas[m].avail()){
                    // in here i make coffee
                    Event coffee_popped=busyBaristas[m].coffee(popped.sort);
                    Model_2.AppendEvent(coffee_popped);

                }

                m++;

            }

        }
        fprintf(f,"\n");
       fprintf(f,"%.2lf\n",runtime) ;
       
       fprintf(f,"%d\n",CashierForSecond.Max_len) ;
       int a=1;
       while(a<=cashiersayisi/3){
        fprintf(f,"%d\n",busyBaristas[a].Max_len) ;
        a++;
       }
       int b=1;
       while(b<=cashiersayisi){
        fprintf(f,"%.2lf\n",CashierForSecond.busytime[b]/runtime) ;
        b++;
       }
       int c=1;
        while(c<=cashiersayisi/3){
            fprintf(f,"%.2lf\n",busyBaristas[c].busytime[1]/runtime) ;
                c++;
        }

        sort(second_turnaround.begin(),second_turnaround.end());
        int d=0;
        while(d<(int) second_turnaround.size()){
            fprintf(f,"%.2lf\n",second_turnaround[d].second-second_turnaround[d].first) ;
            d++;
        }
    }   



    



