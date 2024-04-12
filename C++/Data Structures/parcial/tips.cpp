#include <iostream>
#include <vector>

// Definición de la estructura del nodo del árbol
struct TreeNode {
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Algoritmo DFS para recorrer el árbol y almacenar la ruta en el vector path
void dfs(TreeNode *root, std::vector<TreeNode*> &path) {
    if (root == nullptr) {
        return;
    } else {
        path.push_back(root);
        dfs(root->left, path);
        dfs(root->right, path);
        path.pop_back();
    }
}

// Algoritmo DFS para buscar todas las rutas hacia el target en el árbol
void lookDfs(TreeNode *root, std::vector<int> &path, int target) {
    if (root == nullptr) {
        return;
    } else {
        path.push_back(root->value);
        if (root->value == target) {
            return path;    
        }
        lookDfs(root->left, path, target, result);
        lookDfs(root->right, path, target, result);
        path.pop_back();
    }
}

// Algoritmo DFS para buscar todas las rutas hacia el target en el árbol
void lookAllDfs(TreeNode *root, std::vector<TreeNode*> &path, int target, std::vector<std::vector<TreeNode*>> &result) {
    if (root == nullptr) {
        return;
    } else {
        path.push_back(root-);
        if (root->value == target) {
            result.push_back(path);
        }
        lookAllDfs(root->left, path, target, result);
        looAllkDfs(root->right, path, target, result);
        path.pop_back();
    }
}

// Algoritmo DFS para buscar todos los valores hacia el target en el árbol
void lookAllDfs(TreeNode *root, std::vector<int> &path, int target, std::vector<std::vector<int>> &result) {
    if (root == nullptr) {
        return;
    } else {
        path.push_back(root->value);
        if (root->value == target) {
            result.push_back(path);
        }
        lookAllDfs(root->left, path, target, result);
        looAllkDfs(root->right, path, target, result);
        path.pop_back();
    }
}




/*
To implement DFS traversal, you need to take the following stages.

Step 1: Create a stack with the total number of vertices in the graph as the size.

Step 2: Choose any vertex as the traversal's beginning point. Push a visit to that vertex and add it to the stack.

Step 3 - Push any non-visited adjacent vertices of a vertex at the top of the stack to the top of the stack.

Step 4 - Repeat steps 3 and 4 until there are no more vertices to visit from the vertex at the top of the stack.

Step 5 - If there are no new vertices to visit, go back and pop one from the stack using backtracking.

Step 6 - Continue using steps 3, 4, and 5 until the stack is empty.

Step 7 - When the stack is entirely unoccupied, create the final spanning tree by deleting the graph's unused edges.
*/
