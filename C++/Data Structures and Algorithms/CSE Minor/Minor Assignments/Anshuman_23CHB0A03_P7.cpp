#include<iostream>
using namespace std;

class AVLNode {
public:
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
        height = 1;  // Height of a new node is 1
    }
};

int getHeight(AVLNode* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int getBalanceFactor(AVLNode* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;  // New root
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;  // New root
}

AVLNode* insert(AVLNode* node, int value) {
    if (node == nullptr)
        return new AVLNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);
    else
        return node;  // No duplicates allowed

    // Update height
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    // Check balance factor and balance the tree
    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && value < node->left->data)
        return rotateRight(node);

    // Right Right Case
    if (balance < -1 && value > node->right->data)
        return rotateLeft(node);

    // Left Right Case
    if (balance > 1 && value > node->left->data) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right Left Case
    if (balance < -1 && value < node->right->data) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;  // Return the unchanged node
}

AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

AVLNode* deleteNode(AVLNode* root, int value) {
    if (root == nullptr)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node to be deleted
        if ((root->left == nullptr) || (root->right == nullptr)) {
            AVLNode* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;  // Copy the non-empty child
            delete temp;
        } else {
            AVLNode* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rotateRight(root);

    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return rotateLeft(root);

    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inOrderTraversal(AVLNode* root) {
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

void preOrderTraversal(AVLNode* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(AVLNode* root) {
    if (root != nullptr) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
}

AVLNode* search(AVLNode* root, int value) {
    if (root == nullptr || root->data == value)
        return root;
    if (value < root->data)
        return search(root->left, value);
    return search(root->right, value);
}

int getMinValue(AVLNode* root) {
    AVLNode* current = root;
    while (current->left != nullptr)
        current = current->left;
    return current->data;
}

int getMaxValue(AVLNode* root) {
    AVLNode* current = root;
    while (current->right != nullptr)
        current = current->right;
    return current->data;
}

void printMenu() {
    cout << "\nMENU:\n";
    cout << "1. Insert\n";
    cout << "2. Delete\n";
    cout << "3. InOrder Traversal\n";
    cout << "4. PreOrder Traversal\n";
    cout << "5. PostOrder Traversal\n";
    cout << "6. Find Min\n";
    cout << "7. Find Max\n";
    cout << "8. Search\n";
    cout << "9. Exit\n";
}

int main() {
    AVLNode* root = nullptr;
    int choice, value;

    while (true) {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            root = insert(root, value);
            break;
        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            root = deleteNode(root, value);
            break;
        case 3:
            cout << "InOrder Traversal: ";
            inOrderTraversal(root);
            cout << endl;
            break;
        case 4:
            cout << "PreOrder Traversal: ";
            preOrderTraversal(root);
            cout << endl;
            break;
        case 5:
            cout << "PostOrder Traversal: ";
            postOrderTraversal(root);
            cout << endl;
            break;
        case 6:
            cout << "Minimum value: " << getMinValue(root) << endl;
            break;
        case 7:
            cout << "Maximum value: " << getMaxValue(root) << endl;
            break;
        case 8:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(root, value) != nullptr)
                cout << value << " found in the tree." << endl;
            else
                cout << value << " not found in the tree." << endl;
            break;
        case 9:
            exit(0);
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
