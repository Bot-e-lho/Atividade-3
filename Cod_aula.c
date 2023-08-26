#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left;
    struct Node *right;
}Node;


//int* count_node(struct Node* root, int* ind){
//    if ( root == NULL ){
//        return 0;
//    }


//}
int min_value( Node* root, int* aux ){
    if ( root == NULL || root->left->val == root->right->val ) {
        return -1;
    }
    int i = 0;
    while( root->left != NULL && root->right != NULL ){
        int left = root->left->val;
        int right = root->right->val; 
        aux[i] = (left > right) ? right : left;
        i++;
    }
    int min = 0;
    int sec_min = 0;
    for ( int i = 0; i <= 15; i++ ) {
        //if( aux[i] == -1 ) {
        //    aux[i] == 0;
        // }
        if( min >= aux[i] && sec_min <= min) {
            sec_min = min;
            min = aux[i];
        }

    }
    for (int i = 0; i <= 15; i++ ){
        free(aux[i]);
    }
    return sec_min;

}


int findSecondMinimumValue( Node* root){
    if ( root == NULL || root->left->val == root->right->val ) {
        return -1;
    }
    int* aux = (int*)malloc(sizeof(int) * 15);
    int sec_min = min_value(root, &aux);
    
    return sec_min;

}



int main(int argc, char const *argv[]) {


    return 0;
}
