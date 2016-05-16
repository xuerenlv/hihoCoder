//
//  graph_design.h
//  My_C++
//
//  Created by NLP (password:NLP) on 2/21/16.
//  Copyright (c) 2016 NLP (password:NLP). All rights reserved.
//

#ifndef __My_C____graph_design__
#define __My_C____graph_design__

struct graph_node{
    int val;
    graph_node *neighbour;
    
    graph_node(int v,graph_node *ne){
        val = v;
        neighbour = ne;
    }
};

typedef graph_node* Graph;


//****************** test_graph_main
void test_graph_main();


#endif /* defined(__My_C____graph_design__) */
