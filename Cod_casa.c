#include <stdio.h>
#include <stdlib.h>

typedef struct Node_t {
    int val;
    struct Node_t *left;
    struct Node_t *right;
} Node_t;

Node_t* Create( int val ) {
    Node_t* node = (Node_t*)malloc(sizeof(Node_t));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node_t* Insere( Node_t* node, int val ) {
    if ( node == NULL ) {
        return Create( val );
    }

    if ( val < node->val ){ 
        node->left = Insere(node->left, val);
    } else if ( val > node->val ) {
                node->right = Insere(node->right, val);
    }
    return node;
}

void freeTree( Node_t* node ) {
    if ( node != NULL ) {
        freeTree( node->left );
        freeTree( node->right );
        free( node );
    }
}

void Min_Value( Node_t* root, int min, int *sec_Min ) {
    if ( root == NULL ) {
        return;
    }

    if ( root->val > min && ( root->val < *sec_Min || *sec_Min == -1 ) ) {
        *sec_Min = root->val;
    }

    Min_Value( root->left, min, sec_Min );
    Min_Value( root->right, min, sec_Min );
}

int findSecondMinimumValue( Node_t* root ) {
    if ( root == NULL ) {
        return -1;
    }

    int sec_Min = -1;
    int min = root->val;

    Min_Value( root, min, &sec_Min );

    return sec_Min;
}

int main( int argc, char const *argv[] ) {

    Node_t* root = NULL;
    root = Insere( root, 1 );
    root = Insere( root, 8 );//Output = 8
    root = Insere( root, 23 );

    int sec_Min = findSecondMinimumValue( root );
    printf( "\nSecond Minimum: %d\n", sec_Min );
    freeTree( root );


    Node_t* root_1 = NULL;
    root_1 = Insere( root_1, 10 );//Output = 10
    root_1 = Insere( root_1, 8 );
    root_1 = Insere( root_1, 12 );
    root_1 = Insere( root_1, 8 );
    root_1 = Insere( root_1, 15 );
    root_1 = Insere( root_1, 13 );
    root_1 = Insere( root_1, 18 );

    int sec_Min_1 = findSecondMinimumValue( root_1 );
    printf( "\nSecond Minimum: %d\n", sec_Min_1 );
    freeTree( root_1 );

    Node_t* root_2 = NULL;
    root_2 = Insere( root_2, 2 );
    root_2 = Insere( root_2, 2 );
    root_2 = Insere( root_2, 2147483647 );//Output = 2147483647

    int sec_Min_2 = findSecondMinimumValue( root_2 );
    printf( "\nSecond Minimum: %d\n", sec_Min_2 );
    freeTree( root_2 );
    return 0;
}
