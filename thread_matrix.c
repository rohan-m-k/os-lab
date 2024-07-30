
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#define MAT_SIZE 10
#define MAX_THREADS 100

int i,j,k,x,y,z,a;
//Parameters For Rows And Columns
int matrix1[MAT_SIZE][MAT_SIZE]; //First Matrix
int matrix2[MAT_SIZE][MAT_SIZE]; //Second Matrix
int result [MAT_SIZE][MAT_SIZE]; //Multiplied Matrix
void* mul(void*);
typedef struct parameters
    {
       int x,y;
    }args;
void* mul(void*arg)
 {
    args* p=arg;
    for(int a=0;a<j;a++)
     {
       result[p->x][p->y]+=matrix1[p->x][a]*matrix2[a][p->y];
     }
    sleep(3);
    pthread_exit(0);
  }

int main()
{
   for(int x=0;x<10;x++)
     {
      for(int y=0;y<10;y++)
        {
         // matrix1[x][y] = 0;
        //  matrix2[x][y] = 0;
          result[x][y] = 0;
        }
     }
   printf("Enter number of rows for matrix 1: ");
   scanf("%d",&i);
   printf("Enter number of columns for matrix 1: ");
   scanf("%d",&j);
   printf("\n --- reading  Matrix 1 ---\n\n");
   for(int x=0;x<i;x++)
    {
      for(int y=0;y<j;y++)
       {
         printf("Enter variable [%d,%d]: ",x+1,y+1);
         scanf("%d",&matrix1[x][y]);
       }
    }

   printf("enter Number of rows for matrix 2 \n");
   scanf("%d",&j);
   printf("Enter number of columns for matrix 2: ");
   scanf("%d",&k);
   printf("\n --- reading Matrix 2 ---\n\n");
   for(int x=0;x<j;x++)
     {
       for(int y=0;y<k;y++)
        {
          printf("Enter variable [%d,%d]: ",x+1,y+1);
          scanf("%d",&matrix2[x][y]);
        }
     }
   printf("\n --- Matrix 1 ---\n\n");
   for(int x=0;x<i;x++)
     { 
      for(int y=0;y<j;y++)
        {
          printf("%5d",matrix1[x][y]);
        }
      printf("\n\n");
     }
   printf(" --- Matrix 2 ---\n\n");
   for(int x=0;x<j;x++)
    {
      for(int y=0;y<k;y++)
       {
        printf("%5d",matrix2[x][y]);
       }
      printf("\n\n");
    }
pthread_t thread[MAX_THREADS];
int thread_number = 0;
args p[i*k];

   for(int x=0;x<i;x++)
     {
      for(int y=0;y<k;y++)
       {
         p[thread_number].x=x;
         p[thread_number].y=y;
         int status;
         status = pthread_create(&thread[thread_number], NULL, mul, (void *) &p[thread_number]);
         if(status!=0)
          {
            printf("Error In Threads");
            exit(0);
          }
        thread_number++;
       }
     }
for(int z=0;z<(i*k);z++)
 {
   pthread_join(thread[z],NULL );
 }
printf(" --- Multiplied Matrix ---\n\n");
  for(int x=0;x<i;x++)
   {
     for(int y=0;y<k;y++)
       {
        printf("%5d",result[x][y]);
       }
     printf("\n\n");
   }

printf(" ---> Used Threads : %d \n\n",thread_number);for(int z=0;z<thread_number;z++)
{
printf(" - Thread %d ID : %d\n",z+1,(int)thread[z]);
}
return 0;
}
