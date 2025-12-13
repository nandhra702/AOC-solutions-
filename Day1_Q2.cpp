#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
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
            //okay, now what we do is, firstly check how big the next number is.
            if(add/100>0){
                code += (add)/100;
                add = add%100;
            }

            if(i+add >=100){
                //means we cross 0
                if(i==100){
                    i=0;
                }
                if(i!=0){
                    code++;
                }

                //now we have to correct the position of i.
                i = (i+add)%100;
                if (i==100){
                    i=0;
                }
            }
            
            else{
                i+=add;
                //not crossing zero
            }


            cout<<"Current i after R move: "<<i<<"\n";
            cout<<"Current code after R move: "<<code<<"\n";
         
        
            
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

                if(add/100>0){
                    code+= (add)/100;
                    add=add%100; 
                }

                if( i - (add) <=0 ){
                    if(i==100){
                        i=0;    
                    }
                    if(i!=0){
                    code++;}

                    //now, correcting the position of i
                    i = 100 + (i - add);
                    if(i==100){
                        i=0;
                    }
                }

            }
            else{
                //means in bounds
                i-=add;
            }         

            cout<<"Current i after L move: "<<i<<"\n";
            cout<<"Current code after L move: "<<code<<"\n";
        }

    }

    cout << code;

}
