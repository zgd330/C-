#include <fun.h>

void print()
{
    printf("i am print\n");
    pthread_exit(NULL);
}

void* threadFunc(void* p)//线程函数
{
    printf("i am child thread\n");
    print();
    printf("i am child after print\n");
    return NULL;
}
int main(int argc,char *argv[])
{
    pthread_t pthid;
    int ret;
    ret=pthread_create(&pthid,NULL,threadFunc,NULL);
    THREAD_ERROR_CHECK(ret,"pthread_create");//创建线程封装到THREAD_ERROR_CHECK
    pthread_join(pthid,NULL); 
    printf("i am main thread\n");
    return 0;
}

