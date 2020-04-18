class Node{
  constructor(value){
    this.value = value;
    this.next = null;
  }
}

class Stacks{
  constructor(value){
    this.top = null;
    this.bottom = null;
    this.length = 0;
  }
  peek(){
    if(this.top == null) return null;
		else return this.top.value;
  }
  push(value){
    const newNode = new Node(value);
    if(this.length === 0){
      this.top = newNode;
      this.bottom = newNode;
    }else{
      const holdingPointer = this.top;
      this.top = newNode;
      this.top.next = holdingPointer;
    }
    this.length++;
  }
	pop(){

		if(this.top == null) {
			return null;
		}
		if(this.top == this.bottom){
			this.bottom = null;
		}
		this.top = this.top.next;
		this.length--;
	}
  printStack(){
		let temp = this.top;
		let arri=[];
		while(temp != null){
			arri.push(temp.value);
			temp = temp.next;
		}
		return arri;
	}
	isEmpty(){
		if(this.length == 0) return true;
		return false;
	}
}

const myStack = new Stacks();
myStack.push('google');
myStack.push('Udemy');
myStack.push('Bing');
myStack.push('finalfantasyxv.com');
myStack.push('FFXV');
myStack.push('youtube');

myStack.pop();
