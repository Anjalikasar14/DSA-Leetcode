class Node{
    public:
    int data;
    int minvalue;
    Node* next;

    Node(int x,int minval){
        data = x;
        minvalue = min(data,minval);
        next = NULL;
    }
};


class MinStack {
    Node* topval;
public:
    MinStack() {
        topval = NULL;
    }
    
    void push(int value) {
        int currentmin;

        if(topval ==NULL){
            currentmin = value;
        }else{
            currentmin = min(value,topval->minvalue);
        }
        Node* newnode = new Node(value,currentmin);
        newnode->next =topval;
        topval =newnode;
    }
    
    void pop() {
        if(topval==NULL){
            return;
        }
        Node* temp = topval;
        topval=topval->next;
        delete temp;
        
    }
    
    int top() {
        if(topval==NULL){
            return -1;
        }
        return topval->data;
        
    }
    
    int getMin() {
       return topval->minvalue;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */