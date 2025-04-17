#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int empty(struct queue_t * q) {
        if (q == NULL) return 1;
    return (q->size == 0);
}

void enqueue(struct queue_t * q, struct pcb_t * proc) {
        /* TODO: put a new process to queue [q] */
        if(q && q->size < MAX_QUEUE_SIZE){
                q->proc[q->size] = proc;
                q->size += 1;
        }
        return;
}

struct pcb_t * dequeue(struct queue_t * q) {
        /* TODO: return a pcb whose prioprity is the highest
         * in the queue [q] and remember to remove it from q
         * */
        if(!q || q->size == 0){
                return NULL;
        }
        int ret_idx = 0;
        // int prociprio, retprocprio;
// #ifdef MLQ_SCHED
        for(int i = 1; i < q->size; i++){
                if(q->proc[i]->prio < q->proc[ret_idx]->prio){ // smaller number = higher priority
                        ret_idx = i;
                }
        }
        struct pcb_t* ret_pcb = q->proc[ret_idx];
        for(int i = ret_idx; i < q->size - 1; i++){
                q->proc[i] = q->proc[i + 1];
        }
        q->size -= 1;
        return ret_pcb;
        // return (q->size == 0) ? NULL : q->proc[ret_idx];
    // return NULL;
}