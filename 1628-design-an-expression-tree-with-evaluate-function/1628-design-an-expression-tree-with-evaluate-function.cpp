/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
    // define your fields here
};

class NumberNode : public Node {
private:
    int val;
    
public:
    NumberNode(int val) : val(val) {}
    int evaluate() const override {
        return val;
    }
};

template<class T>
class BinaryNode : public Node {
private:
    Node* left;
    Node* right;
    
public:
    BinaryNode(Node* left, Node* right) : left(left), right(right) {}
    virtual ~BinaryNode() {
        delete left;
        delete right;
    }
    
    int evaluate() const override {
        return T()(left->evaluate(), right->evaluate());
    }
};

using PlusNode = BinaryNode<plus<int>>;
using MinusNode = BinaryNode<minus<int>>;
using MultiplyNode = BinaryNode<multiplies<int>>;
using DivideNode = BinaryNode<divides<int>>;

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        stack<Node*> st;
        for(auto& s : postfix) {
            if(isdigit(s[0]))
                st.push(new NumberNode(stoi(s)));
            else {
                Node* right = st.top(); st.pop();
                Node* left = st.top(); st.pop();
                if(s == "+")
                    st.push(new PlusNode(left, right));
                else if(s == "-")
                    st.push(new MinusNode(left, right));
                else if(s == "*")
                    st.push(new MultiplyNode(left, right));
                else if(s == "/")
                    st.push(new DivideNode(left, right));
                else
                    assert(0);
            }
        }
        return st.top();
    }
};


/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */