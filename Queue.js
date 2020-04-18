class Node{
  constructor(value){
    this.value = value;
    this.next = null;
  }
}

class Queue{
	constructor(){
		this.first = null;
		this.last = null;
		this.length = 0;
	}
	peek(){
		return this.last;
	}
	enqueue(value){
		const newNode = new Node(value);
		if(this.length == 0){
			this.last = newNode;
			this.first = this.last;
		}else{
			this.first.next = newNode;
			this.first = newNode;
		}
		this.length++;
	}
	dequeue(){
		if(this.length == 0) return null;
		this.last = this.last.next;
		this.length--;
	}
	size(){
		return this.length;
	}
	printQueue(){
		let temp = this.last;
		const arri = [];
		while(temp != null){
			arri.push(temp.value);
			temp = temp.next;
		}
		return arri;
	}
}
