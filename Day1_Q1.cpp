#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main(){
    cout<<"hellow\n";

    //firstly we make a string so that whatever we read, we store it in the string
    string move;
    ifstream ReadFile("D1Q1_input.txt");

    int i=50; //(this is the counting variable)
    int code = 0; //store the time the needle points to 0

    while(getline(ReadFile,move)){

        //now in here, we have to read the string, compute the move.
        int size = move.size();
        int add=0;
        if(move[0]=='R'){
            //means we add
            if(size==2){
                add+=(move[1]-'0');
            }
            else if (size==4){
                add+=((move[1]-'0')*100 + (move[2]-'0')*10 + move[3]-'0');
            }
            else{
                add+= ((move[1]-'0')*10 + move[2]-'0');
            }

            //now we have add value.

            if(i+add>=100){
                if((i+add)%100==0){
                code++;}
            

                i = (add + i)%100;
            }

            else{
                //means its in bounds.
                i+=add;
            }

         
        
            
        }

        else{

            //means we are in the left side of things.
            if(size==2){
                add+=(move[1]-'0');
            }

            else if (size==4){
                add+=((move[1]-'0')*100 +(move[2]-'0')*10 + move[3]-'0');
            }

            else{
                add+= ((move[1]-'0')*10 + move[2]-'0');
            }
            

            //now we have subtract that value.
            if(i - add<=0){
                if((i-add)%100==0){
                code++;}

                i = (i-add)%100;
                if(i<100){
                    i+=100;}
            }

            else{
                //means in bounds
                i-=add;
            }         

              
        }

    }

    cout << code;

}
