#include <stdio.h>
#include <pthread.h>

// Function executed by each thread
void *printGoodMorning(void *threadId) {
    long tid = (long)threadId;    
    printf("Good morning from thread %ld\n", tid); 
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[4];   
    int i;    

    for (i = 0; i < 4; i++) {    
        int rc = pthread_create(&threads[i], NULL, printGoodMorning, (void *) i);     
        if (rc) { 
            printf("Error creating thread %d\n", i);     
            return -1;     
        }   
    }

    // Wait for all threads to finish 
    for (i = 0; i < 4; i++) {  
        pthread_join(threads[i], NULL);  
    }   

    return 0;
}
