#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
struct Node {
    int data;          // Dữ liệu của node
    struct Node* next;  // Con trỏ đến node tiếp theo
};

// Hàm tạo một node mới
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Không đủ bộ nhớ\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void addToHead(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head->next;
    head->next = newNode;
}

void addToTail(struct Node* head, int value){
    struct Node* newNode = createNode(value);
    struct Node* head_tmp = head;
    while(head_tmp->next != NULL){
        head_tmp = head_tmp->next;
    }
    head_tmp->next = newNode;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current->next != NULL) {
        printf("%d -> ", current->next->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    // Khởi tạo danh sách liên kết rỗng
    struct Node* myList = createNode(0);

    // Thêm một số node vào đầu danh sách liên kết
    addToTail(myList, 20);
    addToHead(myList, 3);
    addToHead(myList, 2);
    addToHead(myList, 1);
    // In ra danh sách liên kết
    printf("Danh sach lien ket: ");
    printList(myList);

    // Giải phóng bộ nhớ
    struct Node* current = myList;
    struct Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}