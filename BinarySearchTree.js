class Node {
    constructor(value) {
        this.left = null;
        this.right = null;
        this.value = value;
    }
}

class BinarySearchTree {
    constructor() {
        this.root = null;
    }
    insert(value) {
        const newNode = new Node(value);
        if (this.root == null) this.root = newNode;
        else {
            let temp = this.root;
            while (true) {
                if (value > temp.value) {
                    if (!temp.right) { temp.right = newNode; return; }
                    temp = temp.right;
                } else {
                    if (!temp.left) { temp.left = newNode; return; }
                    temp = temp.left;
                }
            }
        }
        return;
    }
    lookup(val) {
        if (!this.root) return false;
        let temp = this.root;
        while (temp) {
            if (val < temp.value) temp = temp.left;
            else if (val > temp.value) temp = temp.right;
            else {
                return temp;
            }
        }
        return this;
    }
    remove(val) {
        if (!this.root) return null;
        let temp = this.root;
        let parentNode = null;
        while (temp) {
            if (val < temp.value) {
                parentNode = temp;
                temp = temp.left;
            } else if (val > temp.value) {
                parentNode = temp;
                temp = temp.right;
            } else {
                if (temp.right == null) {
                    if (parentNode == null)
                        this.root = temp.left;
                    else {
                        if (temp.value < parentNode.value) {
                            parentNode.left = temp.left;
                        } else if (temp.value > parentNode.value)
                            parentNode.right = temp.left;
                    }

                } else if (temp.right.left == null) {
                    temp.right.left = temp.left;
                    if (parentNode == null) {
                        this.root = temp.left;
                    } else {
                        if (temp.value < parentNode.value)
                            parentNode.left = temp.right;
                        else if (temp.value > parentNode.value) {
                            parentNode.right = temp.right;
                        }
                    }
                } else {
                    let leftmost = temp.right.left;
                    let leftmostParent = temp.right;
                    while (leftmost.left != null) {
                        leftmostParent = leftmost;
                        leftmost = leftmost.left;
                    }
                    leftmostParent.left = leftmost.right;
                    leftmost.left = temp.left;
                    leftmost.right = temp.right;
                    if (parentNode == null)
                        this.root = leftmost;
                    else {
                        if (temp.value < parentNode.value)
                            parentNode.left = leftmost;
                        else if (temp.value > parentNode.value) {
                            parentNode.right = leftmost;
                        }
                    }
                }
                return true;
            }
        }

    }

}

const bst = new BinarySearchTree();

bst.insert(9);
//bst.insert(0);
bst.insert(4);
bst.insert(3);
bst.insert(6);
bst.insert(10);
bst.insert(11);

bst.remove(9);

console.log(bst.lookup(9));
