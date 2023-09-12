#include <stdio.h>
struct tempNode {
    unsigned int key;
    unsigned int left_key;
    unsigned int right_key;
};

struct TreeNode {
    TreeNode(unsigned int data) { data = data; }
    TreeNode(tempNode* temp_node) { data = temp_node->key; left_data = temp_node->left_key; right_data = temp_node->right_key; }
    TreeNode(TreeNode* tree_node) { data = tree_node->data; left_data = tree_node->left_data; right_data = tree_node->right_data; left= tree_node->left; right = tree_node->right;}
    unsigned int data;
    unsigned int left_data;
    unsigned int right_data;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
};

template <class T>
class Node{
public:
    T data;
    Node* next;
    Node* previous;

    Node(T init_data) {
        data = init_data;
        next = NULL;
    }
};

template <class T>
class List{
private:
    Node<T>* head;

public:
    List() {
        head = NULL;
    }

    ~List(){
        Node<T>* current_node = head;    while( current_node != NULL ) {
            Node<T>* next_node = current_node->next;
            delete current_node;
            current_node = next_node;
        }
        head = NULL;
    }

    List(const List<T> &old_list){
        head=NULL;

        Node<T>* current_node = old_list.head;
        while( current_node != NULL ){
            this->push_back(current_node->data);
            current_node = current_node->next;
        }
    }

    void push_back(T data)
    {
        Node<T>* new_node = new Node<T>(data);
            
        if (head==NULL) {
            head = new_node;
            return;
        }

        head->previous = new_node;
        new_node->next = head;
        head = new_node;
    }

    Node<T>* begin(){
        return head;
    }
};

void fillNode(TreeNode* tree, List<tempNode>* list) {
    if(tree->left_data != 0) {
        Node<tempNode>* iter = list->begin();
        while(iter!=NULL) {
            if (iter->data.key == tree->left_data) {
                tree->left = new TreeNode(&(iter->data));
                fillNode(tree->left, list);
                break;
            }
            iter = iter->next;
        }
    }
    if (tree->right_data != 0) {
        Node<tempNode>* iter = list->begin();
        while(iter!=NULL) {
            if (iter->data.key == tree->right_data) {
                tree->right = new TreeNode(&(iter->data));
                fillNode(tree->right, list);
                break;
            }
            iter = iter->next;
        }
    }
}

int height(TreeNode* node)
{
    if (node == NULL)
        return 0;
    else {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
        /* use the larger one */
        if (lheight > rheight) {
            return (lheight + 1);
        }
        else {
            return (rheight + 1);
        }
    }
}

void printGivenLevel( TreeNode* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1) {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void printLevelOrder( TreeNode* root ) {
    int h = height(root);
    int i;
    for (i = h; i >= 1; i--) {
        printf("%d: ", i-1);
        printGivenLevel(root, i);
        printf("\n");
    }
}

void treeRoot(TreeNode* &tree, List<tempNode>* list) {
    Node<tempNode>* iter = list->begin();
    while(iter!=NULL) {
        if (iter->data.left_key == tree->data) {
            tree = new TreeNode(&(iter->data));
            treeRoot(tree, list);
            break;
        }
        if (iter->data.right_key == tree->data) {
            tree = new TreeNode(&(iter->data));
            treeRoot(tree, list);
            break;
        }
        iter = iter->next;
    }
}

int main() {
    List<tempNode> lines;
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);

    unsigned int data(0),left(0),right(0);
    scanf("%u%u%u", &data, &left, &right);
    tempNode temp {data,left,right};
    TreeNode* tree = new TreeNode(&temp); 
    lines.push_back(temp);
    bool running = true;
    while (running){
        scanf("%u%u%u", &data, &left, &right);
        temp = {data, left, right};
        if (data == 0) {
            running = false;
            break;
        }
        if (left == tree->data) {
            TreeNode* new_parent = new TreeNode(&temp); 
            tree = new_parent;
            lines.push_back(temp);
        } else if (right == tree->data) {
            TreeNode* new_parent = new TreeNode(&temp); 
            tree = new_parent;
            lines.push_back(temp);
        } else {
            lines.push_back(temp);
        }
    }
    treeRoot(tree, &lines);
    fillNode(tree, &lines);
    printLevelOrder(tree);
    return 0;
}