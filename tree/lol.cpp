#include<iostream>
#define SPACE 10

using namespace std;

class TreeNode {
  public:
    int value;
  TreeNode * left;
  TreeNode * right;

  TreeNode(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
};

class BST {
  public:
    TreeNode * root;
  BST(int v) {
    root = new TreeNode(v);
  }

  void insertNode(int v) {
    TreeNode * new_node = new TreeNode(v);
    TreeNode * temp = root;
    while (temp != NULL) {
    if (new_node -> value == temp -> value) {
        cout << "Value Already exist," <<
        "Insert another value!" << endl;
        return;
    } else if ((new_node -> value < temp -> value) && (temp -> left == NULL)) {
        temp -> left = new_node;
        cout << "Value Inserted!" << endl;
        break;
    } else if (new_node -> value < temp -> value) {
        temp = temp -> left;
    } else if ((new_node -> value > temp -> value) && (temp -> right == NULL)) {
        temp -> right = new_node;
        cout << "Value Inserted!" << endl;
        break;
    } else {
        temp = temp -> right;
    }
    }
  }

  void print2D(TreeNode * r, int space) {
    if (r == NULL) 
      return;
    space += SPACE; 
    print2D(r -> right, space); 
    cout << endl;
    for (int i = SPACE; i < space; i++) 
      cout << " "; 
    cout << r -> value << "\n"; 
    print2D(r -> left, space); 
  }

  TreeNode * minValueNode(TreeNode * node) {
    TreeNode * current = node;
    while (current -> left != NULL) {
      current = current -> left;
    }
    return current;
  }

  TreeNode * maxValueNode(TreeNode * node) {
    TreeNode * current = node;
    while (current -> right != NULL) {
      current = current -> right;
    }
    return current;
  }

  TreeNode * deleteNode(TreeNode * r,int v) {
    if (r == NULL) {
      return NULL;
    }
    else if (v < r -> value) {
      r -> left = deleteNode(r -> left, v);
    }
    else if (v > r -> value) {
      r -> right = deleteNode(r -> right, v);
    }
    else {
      if (r -> left == NULL) {
        TreeNode * temp = r -> right;
        delete r;
        return temp;
      } else if (r -> right == NULL) {
        TreeNode * temp = r -> left;
        delete r;
        return temp;
      } else {
        TreeNode * temp = minValueNode(r -> right);
        r -> value = temp -> value;
        r -> right = deleteNode(r -> right, temp -> value);
      }
    }
    return r;
  }

};

int main() {
  
  int option, val,root;
  cout << "Enter value for Root Node : ";
  cin>>root;
  cout<<endl;
  BST obj(root);
  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node\t\t" ;
    cout << "2. Delete Node\t\t" ;
    cout << "3. Find Max Node value\t\t" << endl;
    cout << "4. Print Tree\t\t" ;
    cout << "5. Clear Screen\t\t" ;
    cout << "0. Exit Program" << endl;

    cin >> option;
    //Node n1;
    TreeNode * new_node = new TreeNode(0);

    switch (option) {
    case 0:
      break;
    case 1:
      	cout <<"INSERT"<<endl;
	      cout <<"Enter VALUE of TREE NODE to INSERT in BST: ";
	      cin >> val;
	      new_node->value = val;
	      obj.insertNode(val);
	      cout<<endl;
    		break;
      
    case 2:
      cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
      cin >> val;
      obj.deleteNode(obj.root, val);
      cout << "Value Deleted" << endl;
      break;

    case 3:
      {TreeNode* maxNode = obj.maxValueNode(obj.root);
      cout << "MAX NODE value : "<< maxNode->value << endl;}
      break;
    
    case 4:
      cout << "PRINT 2D: " << endl;
      obj.print2D(obj.root, 5);
      cout << endl;
      break;
    case 5:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}