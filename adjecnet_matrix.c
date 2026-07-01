#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

typedef struct {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

//Operations

void initGraph(Graph *g, int newVertices){
    g -> vertices = newVertices;
    for(int i = 0; i < newVertices; i++){
        for(int j = 0; j < newVertices; i++){
            g->adjacencyMatrix[i][j] = 0;
        }
    }
}

Graph createGraph(int vertices){ //el * es para, utilizando la direccion que da &, va a la dirrecion
    Graph g;

    if(vertices > MAX_VERTICES){
        puts("Cantidad de vertices superior a la permitida.\n");
        exit(EXIT_FAILURE);
    }

    initGraph(&g, vertices);// le manda la direccion y en la funcion va a la direccion

    return g; //& trae la dirreccion donde vive
}

void addEdge(Graph *g, int source, int destination){
    if (source == destination){
        puts("El origen y el destino no pueden ser iguales.\n");
        return;
    }

    if(source < g->vertices && destination < g->vertices){
        g->adjacencyMatrix[source][destination] = 1;
        g->adjacencyMatrix[destination][source] = 1; // removed in directed graph
    }else{
        puts("El origen o el destino no corresponden a los nodos definidos en el grafo.\n");
        return;
    }

}

bool hasEdge(Graph *g, int source, int destination){
    bool has = false;
    if(source < g->vertices && destination < g->vertices){
        if(g->adjacencyMatrix[source][destination] == 1){
            has = true;
        }
    }else{
        puts("El origen o el destino no corresponden a los nodos definidos en el grafo.\n");
        return;
    }

    return has;

}

void removeEdge(Graph *g, int source, int destination){
    if(hasEdge(g, source, destination)){
        g->adjacencyMatrix[source][destination] = 0;
        g->adjacencyMatrix[destination][source] = 0;
    }else{
        puts("No se puede eliminar la arista entre los nodos definidos.");
    }
}

int main(){
    int vertices;
    printf("Ingrese cantidad de vertices: ");
    scanf("%d", &vertices); //scanf guarda directamente en la posicion de memoria por eso se la pasa la direccion con & de vertices

    Graph graph = createGraph(vertices);



    return 0;
}