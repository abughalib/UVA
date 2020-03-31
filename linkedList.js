 class Node{
     constructor(value){
         this.value = value
         this.next = null
     }
 }

class LinkedList{
    constructor(value){
        this.head = {
            value: value,
            next: null
        }
        this.tail = this.head;
        this.length = 1;
    }
    append(value){
        const newNode = new Node(value);
        this.tail.next = newNode;
        this.tail = newNode;
        this.length++
    }
    prepand(value){
        const newNode = new Node(value)
        newNode.next = this.head
        this.head = newNode
        this.length++
    }
    size(){ //Length is already given but wanted to feel like c++
        return this.length
    }
    printList(){
        const array = []
        let currentNode = this.head;
        while(currentNode!= null){
            array.push(currentNode.value)
            currentNode = currentNode.next;
        }
        return array;
    }
    insert(index, value){ //This can be make shorter using getNode but I'm lazy.
      let currentNode = this.head;
      let counter = 0;
      if(index > this.length){
          console.warn("Index out of range")}
        else{
      while(true){
          if(index == 0){this.prepand(value); break;}
          else if(index == this.length) {this.append(value); break;}
          if(counter == index-1){
            const tails = currentNode.next;
            const newNode = new Node(value);
            currentNode.next = newNode
            newNode.next = tails
            this.length++
            break;
          }
          currentNode = currentNode.next
          counter++
      }
    }
}
    getNode(index){
        let counter = 0;
        let currentNode = this.head;
        while(counter != index) currentNode = currentNode.next
        return currentNode
    }
    remove(index){
        const node = this.getNode(index-1);
        node.next = node.next.next;
        this.length--;
    }
}
