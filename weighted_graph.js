class Node{
  constructor(val, weight, head){
    this.val= val;
    this.weight = weight;
    this.next = head;
  }
}
class Edge{
  constructor(src, dest, weight){
    this.src = src;
    this.dest = dest;
    this.weight = weight;
  }
}
class Graph{
  getAdjListNode(val, weight, head){
    let newNode = new Node(val, weight, head);
    return newNode;
  }
  constructor(edges, size){
    this.head = []
    for(let i = 0; i < size; i++){
      this.head[i] = null;
    }
    for(let i = 0; i < size; i++){
      let src = edges[i].src;
      let dest = edges[i].dest;
      let weight = edges[i].weight;
      let newNode = this.getAdjListNode(dest, weight, this.head[src]);
      this.head[src] = newNode;

      // Below code is for undirected graph;
      // newNode = this.getAdjListNode(src, weight, this.head[dest]);
      // this.head[dest] = newNode;
    }
  }
}

function printList(ptr, i){
  while(ptr != null){
    console.log(`(${i}, ${ptr.val}, ${ptr.weight})`);
    ptr = ptr.next;
  }
  console.log("\n");
}
function main(){
  let edges = [
    {"src": 0, "dest": 1, "weight":6}, {"src": 1, "dest": 2, "weight":7}, 
    {"src": 2, "dest": 0, "weight":5}, {"src": 2, "dest": 1, "weight":4},
    {"src": 3, "dest": 2, "weight":10}, {"src": 4, "dest": 5, "weight":3}, 
    {"src": 5, "dest": 4, "weight":3}
  ]
  let size = 6;

  let graph = new Graph(edges, size);

  for(let i = 0; i < size; i++){
    printList(graph.head[i], i);
  }
}

main();