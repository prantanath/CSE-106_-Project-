//CSE-106(Discrete Math)
//Pranta Nath Nayan
//EWU_Summer19
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int adj[6000][6000];
int main()
{
    int n;
    clock_t start,stop;
    printf("Enter Number of Vertices: ");
    scanf("%d",&n);
    srand(2);
    double time, nano=pow(10,9);
    start=clock();
    //generating random matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj[i][j]=rand()%2;
        }
    }
    //generating undirected graph
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                if(adj[i][j]==1){
                        if(i==j){    //ignoring loops
                            adj[i][j]=0;
                        }
                        else
                    adj[j][i]=adj[i][j];
                }
                else if(adj[i][j]==0){
                    adj[j][i]=adj[i][j];
                }
        }
    }
    //Printing The adjacency matrix
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
                printf("%3d ",adj[i][j]);
        }
        printf("\n");
    }
    int edge=0,sum=0;
    //Calculating Degree and Edges
     for(int i=0;i<n;i++){
           int deg=0;
        for(int j=0;j<n;j++){
            if(adj[i][j]==1)
            {
                deg++;

                if(i>j)
                edge++;
            }

     }
     sum+=deg;
     }
     stop=clock();
     printf ("\n Total Degree is %d \n",sum);
     printf ("\n Total Edge is %d \n",edge);
     if(edge*2==sum)
     {
         printf("\n Total Degree/2 = %d/2 = Total edge = %d \n",sum,edge);
         printf("\n So,Handshaking Theorem Is Working\n");
     }
     else
        printf("\n  Handshaking Theorem Is Not Working\n");
     time=((double)(stop-start)/CLOCKS_PER_SEC*nano);
     printf("\n Total Time taken to execute is %lf\n",time);


}
