CODE: 

#include <stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=5,item=0;
void produce();
void consume();
void producer();
void consumer();
int signal(int);
int wait(int);
int main()
{
    do{
        producer();
        sleep(1);
        consumer();
        sleep(1);
    }while(item<10);
    return 0;
}
int wait(int s){
    return(--s);
}
int signal(int s){
    return(++s);
}
void producer(){
    if(empty!=0 && mutex==1){
        produce();
    }
    else{
        printf("OVERFLOW!Buffer is full\n");
    }
}
void consumer(){
    if(full!=0 && mutex==1){
        consume();
    }
    else{
        printf("UNDERFLOW!Buffer is Empty\n");
    }
}
void produce(){
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    ++item;
    printf("Produced item:%d\n",item);
    mutex=signal(mutex);
}
void consume(){
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("Consumed item:%d\n",item);
    mutex=signal(mutex);
}