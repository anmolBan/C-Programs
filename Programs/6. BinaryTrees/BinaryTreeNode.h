template<typename T>
class BinaryTreeNode{
    public:
    T data;
    BinaryTreeNode<T> * left;
    BinaryTreeNode<T> * right;

    BinaryTreeNode(T data){
        this -> data = data;
        left = nullptr;
        right = nullptr;
    }
    ~BinaryTreeNode(){
        if(left){
            delete left;
        }
        if(right){
            delete right;
        }
    }
};