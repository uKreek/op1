#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
};

void AddBack(Node* sent, int data) {
    Node* p = new Node;
    p->data = data;
    p->left = sent->left;
    p->right = sent;
    sent->left->right = p;
    sent->left = p;
}

void Clear(Node* sent) {
    Node* p = sent->right;
    while(p != sent) {
        Node* tmp = p;
        p = p->right;
        delete tmp;
    }
}

void Print(Node* sent) {
    Node* p = sent->right;
    while(p != sent) {
        std::cout << p->data <<std::endl;
        p = p->right;
    }
}

bool isDigit(int num, int digit) {
    int n = num;
    while (n > 0) { 
        if (n % 10 == digit) 
            return true; 
        n /= 10;
    }
    return false;
}
void DeleteThrees(Node* sent) { // удаление по признаку
    Node* p = sent->right;
    while(p != sent) {
        if(isDigit(p->data, 3)) {
            Node* tmp = p;
            p->right->left = p->left;
            p->left->right = p->right;
            p = p->right;
            delete tmp;
        }
        else
            p = p->right;
    }
}

void DuplicateSevens(Node* sent) {
    Node* current = sent->right;
    Node* next;
    Node* seen_head = nullptr; // Временный список для отслеживания уже продублированных чисел

    while (current != sent) {
        next = current->right;
        bool already_seen = false;
        Node* seen_ptr = seen_head;
        while (seen_ptr != nullptr) {
            if (seen_ptr->data == current->data) {
                already_seen = true;
                break;
            }
            seen_ptr = seen_ptr->right;
        }

        if (isDigit(current->data, 7) && !isDigit(current->data, 3) && !already_seen) {
            AddBack(sent, current->data);

            // Добавляем текущее число во временный список 'seen_head'
            Node* new_seen = new Node;
            new_seen->data = current->data;
            new_seen->left = nullptr;
            new_seen->right = seen_head;
            if (seen_head != nullptr) {
                seen_head->left = new_seen;
            }
            seen_head = new_seen;
        }
        current = next;
    }

    // Очистка временного списка 'seen_head' (хотя это не критично, так как функция завершается)
    while (seen_head != nullptr) {
        Node* temp = seen_head;
        seen_head = seen_head->right;
        delete temp;
    }
}

bool hasDuplicates(Node* sent) {
    for (Node* outer = sent->right; outer != sent; outer = outer->right) {
        for (Node* inner = outer->right; inner != sent; inner = inner->right) {
            if (outer->data == inner->data) { // проверка на дубликаты
                return true; 
            }
        }
    }
    return false; 
}

void swap(Node* sent) {
    bool swapped;
    do {
        swapped = false;
        for (Node* current = sent->right; current != sent && current->right != sent; current = current->right) {
            if ((current->data % 10) < (current->right->data % 10)) { // сортировка по последней цифре
                // Меняем данные местами
                int temp = current->data;
                current->data = current->right->data;
                current->right->data = temp;

                swapped = true; // Установим флаг, что произошла замена
            }
        }
    } while (swapped);
}

int main() {
    Node* sent = new Node;
    sent->left = sent;
    sent->right = sent;
    int numberOfElements;

    std::cout << "How many numbers do you want? ";
    std::cin >> numberOfElements;
 
    for(int i=0; i<numberOfElements; i++){
        int num;
        std::cout << "Enter number: ";
        std::cin >> num;
        AddBack(sent, num);
    }
 
    if(hasDuplicates(sent)) { 
        swap(sent); 
    } else { 
        std::cout << "no double" << std::endl;
        DeleteThrees(sent); 
        DuplicateSevens(sent); 
    }
 
    std::cout << "Result:" << std::endl; 
    Print(sent);

    Clear(sent);
    delete sent;

    return 0;
}