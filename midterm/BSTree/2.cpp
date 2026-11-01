void preorder(Node* root) {    //pre
    if (root == nullptr) return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {   //in
    if (root == nullptr) return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(Node* root) {    //post
    if (root == nullptr) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}


