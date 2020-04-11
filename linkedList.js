class Node{
    constructor(value){
        this.value = value;
        this.next = null;
    }
}
class LinkedList{
    constructor(value){
        this.head={
            value: value,
            next: null
        }
        this.tail = this.head;
        this.length = 1;
    }
    append(value){
        const newNode = new Node(value);
        this.tail.next = newNode;
        this.length++;
    }
    prepand(value){
        const newNode = new Node(value);
        const NodeHead = this.head;
        this.head = newNode;
        newNode.next = NodeHead;
        this.length++;
    }
    insert(index, value){
        let headNode = this.head;
        if(index > this.length) console.log("Out of Range");
        else{
            if(index == 0) {this.prepand(value); this.length++;}
            else if(index == this.length) {this.append(value); this.length++;}
            else{
                for(let i = 1; i < index; i++){
                headNode = headNode.next;
            }
            const newNode = new Node(value);
            const headNodeCopy = headNode.next;
            headNode.next = newNode;
            newNode.next = headNodeCopy;
            this.length++;
        }
    }
    }
    remove(index){
        let leader = this.traverseToIndex(index-1);
        const unwantedNode = leader.next;
        leader.next = unwantedNode.next;

        this.length--;
    }
    traverseToIndex(index){
        let currentNode = this.head;
        while(index--){
            currentNode = currentNode.next;
        }
        return currentNode;
    }
    printList(){
        const arry = [];
        let currentNode = this.head;
        while(currentNode != null){
            arry.push(currentNode.value);
            currentNode = currentNode.next;
        }
        return arry;
    }
}
const myLinkedList = new LinkedList(3);
myLinkedList.append(3);
myLinkedList.prepand(1);
myLinkedList.insert(1, 2);
myLinkedList.insert(1, 5);
myLinkedList.insert(0, 0);
myLinkedList.insert(6, 6);
myLinkedList.insert(3, 99);
myLinkedList.remove(3);
console.log(myLinkedList.printList())
