#include <iostream>

using namespace std;

int number = 10;

struct node {
    int data;
    node *leftChild, *rightChild;
};

void preorder(node* ptr) {
    if (ptr) {
        cout << ptr->data << " ";
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

void inorder(node* ptr) {
    if (ptr) {
        inorder(ptr->leftChild);
        cout << ptr->data << " ";
        inorder(ptr->rightChild);
    }
}

void postorder(node* ptr) {
    if (ptr) {
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        cout << ptr->data << " ";
    }
}


int main() {
    node nodes[number + 1];  // 1부터 15까지 사용 (0번 인덱스 사용 X)

    // 노드 초기화
    for (int i = 1; i <= number; i++) {
        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;
    }

    // 노드 연결 (1번 인덱스를 루트로 설정)
    for (int i = 2; i <= number; i++) {
        if (i % 2 == 0)
            nodes[i / 2].leftChild = &nodes[i];  // 부모의 왼쪽 자식 연결
        else
            nodes[i / 2].rightChild = &nodes[i]; // 부모의 오른쪽 자식 연결
    }
    preorder(&nodes[1]);
    cout << endl;
    inorder(&nodes[1]);
    cout << endl;
    postorder(&nodes[1]);
    return 0;
}