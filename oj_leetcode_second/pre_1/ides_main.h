//
//  ides_main.h
//  My_C++
//
//  Created by NLP (password:NLP) on 2/19/16.
//  Copyright (c) 2016 NLP (password:NLP). All rights reserved.
//

#ifndef My_C___ides_main_h
#define My_C___ides_main_h

#include "some_my_util.h"
#include <iostream>
using namespace std;

void idea_test_main() {
    cout << "Hello world! ---- idea test main start" << endl;
    
    
    // 最小的负数 0x80000000 ,,,, 0xFFFFFFFF : -1
    int cur_max = 0xFFFFFFFF;
    cout<<cur_max<<endl;
    
    
//    int* p ;
//    int a=10;
//    p=&a;
//    cout<<" P points to : "<<(*p)<<endl;
//    
//    p=0; // 就是 NULL
//    cout<<" P points to : "<<(*p)<<endl;
    
    
    cout << "Hello world! ---- idea test main end" << endl;
}

//void idea_test_main() {
//    cout << "Hello world! ---- idea test main start" << endl;
//    
//    
//    throw new string("xhj");
//    
//    
//    
//    
//    cout << "Hello world! ---- idea test main end" << endl;
//}

//******************************************************************************* start 4
//#include <memory>
//
//class A{
//private:
//    int i;
//public:
//    A(int x):i(x){}
//    int get_val(){ return i;}
//    ~A(){
//        cout<<" xi_gou invoked !"<<endl;
//    }
//};
//
//
//void idea_test_main() {
//    cout << "Hello world! ---- idea test main start" << endl;
//    
//    auto_ptr<A> p1(new A(100)),p2(new A(200)); // memory 中的软指针 操作
//    
//    cout<<"p1 val : "<<p1->get_val()<<endl;
//    
//    p2=p1;
////    cout<<"p1 val : "<<p1->get_val()<<endl;
//    cout<<"p2 val : "<<p2->get_val()<<endl;
//    
//    
//    cout << "Hello world! ---- idea test main end" << endl;
//}
//******************************************************************************* end 4

//******************************************************************************* start 3
//#include <memory>
//void idea_test_main() {
//    cout << "Hello world! ---- idea test main start" << endl;
//    
//    auto_ptr<int> p1(new int),p2;
//    *p1 = 100;
//    cout<<"p1.get : "<<p1.get()<<" *p1 : "<<*p1<<endl;
//    cout<<(p2==NULL)<<endl; // 对象跟指针还是不一样的
//    cout<<"p1.get : "<<p2.get()<<" *p2 : "<<*p2<<endl; // 无法执行下去，因为 p2 为 NULL
//    
//    p2=p1;
//    *p2=200;
//    cout<<"p1.get : "<<p1.get()<<" *p1 : "<<*p1<<endl;
//    cout<<"p1.get : "<<p2.get()<<" *p2 : "<<*p2<<endl;
//    
//    auto_ptr<int> p3(p2);
//    *p3=300;
//    cout<<"p1.get : "<<p1.get()<<" *p1 : "<<*p1<<endl;
//    cout<<"p1.get : "<<p2.get()<<" *p2 : "<<*p2<<endl;
//    cout<<"p3.get : "<<p3.get()<<" *p1 : "<<*p3<<endl;
//    
//    cout << "Hello world! ---- idea test main end" << endl;
//}
//******************************************************************************* end 3
//******************************************************************************* start 2
//string sharp1(){
//    cout<<"sharp1 invoked"<<endl;
//    return "sharp1";
//}
//
//string sharp2(){
//    cout<<"sharp2 invoked"<<endl;
//    return "sharp2";
//}
//
//void idea_test_main() {
//    cout << "Hello world! ---- idea test main start" << endl;
//    
//    string (*fun)(void); // function pointer
//    fun = sharp1;
//    string one = (*fun)();
//    cout<<one<<endl;
//    
//    fun = sharp2;
//    string two = (*fun)();
//    cout<<two<<endl;
//    
//    cout << "Hello world! ---- idea test main end" << endl;
//}
//******************************************************************************* end 2
//******************************************************************************* start 1

// this pointer test
//class Account{
//private:
//    char name[20];
//    float bal;
//    
//public:
//    void setup(char na[],float b){
//        strcpy(name, na);
//        this->bal = b;
//    }
//    
//    void show(){
//        cout<<"this object stored at : "<<this<<" sizeof(this) : "<<sizeof(this)<<endl;
//        cout<<"this name is : "<<name<<endl;
//        cout<<"this name is : "<<this->name<<endl;
//        cout<<"this name is : "<<(*this).name<<endl;
//    }
//    
//};
//
//
//void idea_test_main() {
//    cout << "Hello world! ---- idea test main start" << endl;
//    
//    Account acc,bcc;
//    acc.setup("xhj_a", 100.09);
//    acc.show();
//    
//    bcc.setup("xhj_b", 200.09);
//    bcc.show();
//    
//    cout << "Hello world! ---- idea test main end" << endl;
//}

//************************************************************************************ end 1

/* 数组传入的是指针，可以在函数内部进行改变，外部也会改变
void test_arr_chan_inside(int* arr){
    
    *arr=100;
    *(arr+2)=100;
    
}

void idea_test_main() {
    cout << "Hello world! ---- idea test main start" << endl;
    
    int arr[8]={1,2,3};
    Arrays::to_console(arr, 8);
    
    test_arr_chan_inside(arr);
    Arrays::to_console(arr, 8);
    
    cout << "Hello world! ---- idea test main end" << endl;
}
*/

//******************************************************************************* old generation start
/* 传入的是一个指针
void test_arr_tran_size(int a[]){
    cout<<"inside fun  "<<sizeof(a)<<endl;
}
*/

void idea_test_main_1() {
    cout << "Hello world! ---- idea test main start" << endl;

    /* 64 位操作系统，一个指针变量为 8 个字节； 1 个 int 为 4 个字节。
     int a[8];
     cout<<sizeof(a)<<endl;
    
     int p_i;
     cout<<sizeof(p_i)<<endl;
     test_arr_tran_size(a);
    */
    
    /* 这样也是可以的，其后的值默认为0
     int a[8] = {1,2,3};
     Arrays::to_console(a, 8);
     */
    
    /* 数组这样赋值，是可以的
     int a[] = {1,2,3};
     Arrays::to_console(a, 8);
    */
    
    /*
     int arr[10] = {0};
     //memset(arr, 1, sizeof(arr)); // only string
     Arrays::to_console(arr, 10);
    */
    cout << "Hello world! ---- idea test main end" << endl;
}

//****************************************************************************** old generation end

#endif
