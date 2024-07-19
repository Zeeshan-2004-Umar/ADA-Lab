// #include<stdio.h>

// void main()
// {
//  int n, a[30][30],i,j,sum,in[30],s[30],t[30],k=0;
//  printf("Enter no of vertices: ");
//  scanf("%d",&n);
//  printf("Enter adjacency matrix:\n");
//  for(i=0;i<n;i++)
//  {
//      for(j=0;j<n;j++)
//      {
//          scanf("%d",&a[i][j]);
//      }
//  }
//  for(j=0;j<n;j++)
//  {
//      sum=0;
//      for(i=0;i<n;i++)
//      {
//          sum+=a[i][j];
//      }
//      in[j]=sum;
//  }
//  int top=-1;
//  for(i=0;i<n;i++)
//  {
//      if(in[i]==0)
//      {
//          top++;
//          s[top]=i;
//      }

//  }
//  while(top!=-1)
//  {
//     int u=s[top];
//     top--;
//     t[k++]=u;
//     for(int i=0;i<n;i++)
//     {
//         if(a[u][i]==1)
//         {
//             in[i]--;
//             if(in[i]==0)
//             {
//                 top++;
//                 s[top]=i;
//             }
//         }
//     }
//  }
//     printf("Sequence: ");
//     for(i=0;i<n;i++)
//     {
//         printf("%d ",t[i]);
//     }
// }




#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int arr[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;

void push(int node) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = node;
}

int pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

void topologicalSortUtil(int node, int num) {
    visited[node] = 1;
    for (int j = 0; j < num; j++) {
        if (arr[node][j] != 0 && !visited[j]) {
            topologicalSortUtil(j, num);
        }
    }
    push(node);
}

void topologicalSort(int num) {
    for (int i = 0; i < num; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, num);
        }
    }

    printf("Topological Sort: ");
    while (top != -1) {
        printf("%d ", pop());
    }
    printf("\n");
}

void main() {
    int num;

    printf("Enter the number of nodes: ");
    scanf("%d", &num);
   
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
   
    // Initialize visited array to 0
    for (int i = 0; i < num; i++) {
        visited[i] = 0;
    }
   
    topologicalSort(num);
}


// #include <stdio.h>
// #include <stdlib.h>

// #define MAX 50

// int arr[MAX][MAX]; // Adjacency matrix
// int inDegree[MAX]; // Array to store in-degrees of nodes
// int queue[MAX];    // Queue to process nodes
// int front = -1, rear = -1; // Queue front and rear

// // Function to add node to the queue
// void enqueue(int node) {
//     if (rear == MAX - 1) {
//         printf("Queue overflow\n");
//         return;
//     }
//     if (front == -1) front = 0;
//     queue[++rear] = node;
// }

// // Function to remove node from the queue
// int dequeue() {
//     if (front == -1 || front > rear) {
//         printf("Queue underflow\n");
//         return -1;
//     }
//     return queue[front++];
// }

// // Function to perform topological sort using source removal technique (Kahn's Algorithm)
// void topologicalSort(int num) {
//     int topologicalOrder[MAX];
//     int index = 0;

//     // Calculate in-degrees of all nodes
//     for (int i = 0; i < num; i++) {
//         inDegree[i] = 0;
//         for (int j = 0; j < num; j++) {
//             if (arr[j][i] != 0) {
//                 inDegree[i]++;
//             }
//         }
//     }

//     // Enqueue all nodes with in-degree 0
//     for (int i = 0; i < num; i++) {
//         if (inDegree[i] == 0) {
//             enqueue(i);
//         }
//     }

//     // Process nodes from the queue
//     while (front != -1 && front <= rear) {
//         int node = dequeue();
//         topologicalOrder[index++] = node;

//         // Decrease in-degree of adjacent nodes and enqueue if in-degree becomes 0
//         for (int j = 0; j < num; j++) {
//             if (arr[node][j] != 0) {
//                 inDegree[j]--;
//                 if (inDegree[j] == 0) {
//                     enqueue(j);
//                 }
//             }
//         }
//     }

//     // Check if topological sort was possible (if there was a cycle)
//     if (index != num) {
//         printf("Graph contains a cycle. Topological sort not possible.\n");
//         return;
//     }

//     // Print topological order
//     printf("Topological Sort: ");
//     for (int i = 0; i < index; i++) {
//         printf("%d ", topologicalOrder[i]);
//     }
//     printf("\n");
// }

// int main() {
//     int num;

//     printf("Enter the number of nodes: ");
//     scanf("%d", &num);
   
//     printf("Enter adjacency matrix:\n");
//     for (int i = 0; i < num; i++) {
//         for (int j = 0; j < num; j++) {
//             scanf("%d", &arr[i][j]);
//         }
//     }
   
//     // Initialize in-degree array to 0
//     for (int i = 0; i < num; i++) {
//         inDegree[i] = 0;
//     }
   
//     topologicalSort(num);

//     return 0;
// }
