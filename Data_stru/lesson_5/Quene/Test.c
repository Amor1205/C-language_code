#include "queue.h"

void TestQueue1()
{
    Queue q;
    QueueInit(&q);

    QueueDestroy(&q);
}
int main()
{
    TestQueue1();

    return 0;
}