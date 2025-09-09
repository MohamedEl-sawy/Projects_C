#include<iostream>

using namespace std;
int main(){
    int x;
    cin>>x;
    int counter=1;
   for(int i=0; i<x ; i++){
        
        for(int j=0 ; j<=i ; j++){
                if(i==x-1 || i<=1){
                cout<<"*";
                }else{
                    if(j==0 || j==i){
                        cout<<"&";
                    }
                    else{
                        cout<<" ";
                    }
                 }

            }
         cout <<endl;
   }
}

