/**
 * @file dag.h
 *
 * @brief Directed Acyclic Graph
 * 
 * @author Mason Hart
 *
 * A DAG is a graph where each connection is directed
 * from one node to another, and there are no cycles.
 * 
 * Internally, this DAG implementation will use a list
 * of Nodes and a list of Vertices
 */

#ifndef DAG_H
#define DAG_H


/**
 *  Definition of a DAG node
 */
typedef struct {
    void *data;
} Node;

/**
 *  Edge between two nodes
 */
typedef struct {
    int startNode;
    int endNode;
} Edge;

/**
 *  Definition of a DAG
 */
typedef struct {
    Node *nodes;
    Edge *edges;
} DAG;

/**
 *  Adds a node to the DAG
 *  @param  dag reference dag
 *  @return  1 if adding a node failed
 */
int addToDAG(DAG *dag);

/**
 *  Removes the specified node from the DAG
 *  @param  index index of the node
 *  @return  the NODE removed at INDEX of the DAG, or NULL if removal failed
 */
Node * removeFromDAG(DAG *dag, unsigned int index);

/** 
 *  Adds a directed edge to the DAG
 *  @param  dag reference DAG
 *  @param  edge edge to be added
 *  @return  1 if adding the edge failed
 */
int addEdgeToDAG(DAG *dag, Edge *edge);

/**
 *  Removes a directed edge from the DAG
 *  @param  dag reference DAG
 *  @param  edge edge to be removed
 *  @return  removed edge, or NULL if removal failed
 */
int removeEdgeFromDAG(DAG *dag, Edge *edge);

/**
 *  Checks if the edge is contained in the DAG
 *  @param  dag reference DAG
 *  @param  edge to check
 *  @return  1 if the EDGE is in the DAG
 */
int edgeContainedInDAG(DAG *dag, Edge *edge);

/**
 *  Checks if the edge is contained in the DAG
 *  @param  dag reference DAG
 *  @param  node to check
 *  @return  1 if the NODE is in the DAG
 */
int nodeContainedInDAG(DAG *dag, Node *node);



#endif