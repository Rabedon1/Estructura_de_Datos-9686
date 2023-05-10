#include"fraccion.cpp"
#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
	float num1, den1, num2, den2;
    cout <<"Escriba la fraccion 1 "<<endl;
    cin >>num1 >>den1;
    cout <<"Escriba la fraccion 2"<<endl;
    cin >>num2 >>den2;
    
    fraccion obj1(num1, den1);
    fraccion obj2(num2, den2);
    proceso(obj2, obj2);
    
    return 0;
    
}