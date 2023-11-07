//c++ program to solve fractional knapsack problem
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//structure for an item which stoores weight and corrosponding value of an item
struct item{
    int value,weight;
    //constructor
    item(int value,int weight){
        this->value=value;
        this->weight=weight;
    }
};
//comparison function to sort item according to val/weight ratio
bool cmp(struct item a,struct item b){
    double r1=(double)a.value/(double)a.weight;
    double r2=(double)b.value/(double)b.weight;
    return r1>r2;
}
double fractionalKnapsack(int W,struct item arr[],int N){
    sort(arr,arr+N,cmp);
        double finalvalue=0.0; //Result(value in knapsack)
        for(int i=0;i<N;i++){
            //if adding item wont overflow add it completely
            if(arr[i].weight<=W){
                W -=arr[i].weight;
                finalvalue+=arr[i].value;
            }
            else
            {
                finalvalue+=arr[i].value*((double)W/(double)arr[i].weight);
                break;
            }
        }
return finalvalue;

}
//friver code
int main(){
    int W=50;
    item arr[]={{60,10},{100,20},{120,20}};
    int N=sizeof(arr)/sizeof(arr[0]);
    //function call
    cout<<"maximum value can obtain=";
    cout<<fractionalKnapsack(W,arr,N);
    return 0;
}


