#include<stdio.h>
#define MAX 4
int adj[MAX][MAX];
int visited[MAX]= {0};
int stack[MAX];
int queue[MAX];
int top=-1;

void bfs();
void dfs();

void main()
{
    int i,j,option;

    printf("Enter value\n");
    for(i=0; i<MAX; i++)
    {
        for(j=0; j<MAX; j++)
        {   printf("adj[%d][%d]:",i,j);
            scanf("%d",&adj[i][j]);
        }
    }
    while(1){
        printf("\n");
        printf("\n---------MENU---------");
        printf("\n1.BFS");
        printf("\n2.DFS");
        printf("\n3.Exit");
        printf("\nEnter a option : ");
        scanf("%d",&option);

        switch(option){

        case 1:bfs();
        break;

        case 2:dfs();
        break;

        case 3:printf("Closing the program...");
        return;

        default:printf("INVALID INPUT!");
        break;
        }
    }
}

void bfs()
{
    int rear=-1,front=-1,i,v;//v is source node
    printf("\nEnter starting node for Breadth First Search:");
    scanf("%d",&v);//answer should be 012345
    //initial inertion source node
    printf("\n");
    rear++;
    front++;
    visited[v]=1;
    queue[rear]=v;
    //repete till queue is full
    while(front<=rear)
    {
        v=queue[front++];
        printf(" %d ",v);

        for(int i=0; i<MAX; i++)
        {
            if(adj[v][i]==1 && visited[i]==0)
            {
                rear++;
                queue[rear]=i;
                visited[i]=1;
            }
        }
    }
}

void dfs(){
int source,i,popnode;
    int visited[MAX]={0};
    printf("\nEnter the starting node for Depth First Search :");
    scanf("%d",&source);
    printf("\n");
    top++;
    stack[top]=source;
    while(top!= -1)
    {
        popnode=stack[top--];
        if(visited[popnode]==0)
        {
            printf(" %d ",popnode);
            visited[popnode]=1;
        }
        for(i=0;i<MAX;i++)
        {
            if(adj[popnode][i]==1 && visited[i]==0 )
            {
                top++;
                stack[top]=i;
            }
        }
    }
}


