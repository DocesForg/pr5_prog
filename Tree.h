#include <iostream>
using namespace std;

// Структура для хранения информации о заявке на авиабилет
struct Ticket {
    string destination;
    int flightNumber;
    string passengerName;
    string departureDate;
};

// Класс, представляющий узел бинарного дерева
class BinaryTreeNode {
public:
    Ticket data; // Информация о заявке
    BinaryTreeNode* left; // Указатель на левое поддерево
    BinaryTreeNode* right; // Указатель на правое поддерево

    // Конструктор для узла бинарного дерева
    BinaryTreeNode(Ticket ticket) {
        data = ticket;
        left = nullptr;
        right = nullptr;
    }
};

// Класс, представляющий бинарное дерево для хранения заявок на авиабилеты
class BinaryTree {
private:
    BinaryTreeNode* root; // Указатель на корень дерева

    // Вспомогательная функция для удаления узла по ключу (номеру рейса и дате вылета)
    BinaryTreeNode* deleteNode(BinaryTreeNode* root, int flightNumberToDelete, const string& departureDateToDelete) {
        if (root == nullptr) return root;

        if (flightNumberToDelete < root->data.flightNumber) {
            root->left = deleteNode(root->left, flightNumberToDelete, departureDateToDelete);
        }
        else if (flightNumberToDelete > root->data.flightNumber) {
            root->right = deleteNode(root->right, flightNumberToDelete, departureDateToDelete);
        }
        else {
            if (departureDateToDelete != root->data.departureDate) {
                root->right = deleteNode(root->right, flightNumberToDelete, departureDateToDelete);
            }
            else {
                if (root->left == nullptr) {
                    BinaryTreeNode* temp = root->right;
                    delete root;
                    return temp;
                }
                else if (root->right == nullptr) {
                    BinaryTreeNode* temp = root->left;
                    delete root;
                    return temp;
                }
                BinaryTreeNode* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right, temp->data.flightNumber, temp->data.departureDate);
            }
        }
        return root;
    }

    // Вспомогательная функция для поиска узла с минимальным ключом в поддереве
    BinaryTreeNode* minValueNode(BinaryTreeNode* node) {
        BinaryTreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

public:
    // Конструктор для бинарного дерева
    BinaryTree() {
        root = nullptr;
    }

    // Метод для вставки заявки в дерево
    void insert(Ticket ticket) {
        if (root == nullptr) {
            root = new BinaryTreeNode(ticket);
        }
        else {
            insertHelper(root, ticket);
        }
    }

    // Вспомогательная функция для вставки заявки в дерево
    void insertHelper(BinaryTreeNode* node, Ticket ticket) {
        if (ticket.flightNumber < node->data.flightNumber) {
            if (node->left == nullptr) {
                node->left = new BinaryTreeNode(ticket);
            }
            else {
                insertHelper(node->left, ticket);
            }
        }
        else {
            if (node->right == nullptr) {
                node->right = new BinaryTreeNode(ticket);
            }
            else {
                insertHelper(node->right, ticket);
            }
        }
    }

    // Метод для удаления заявки по номеру рейса и дате вылета
    void deleteByFlightNumberAndDate(int flightNumberToDelete, const string& departureDateToDelete) {
        root = deleteNode(root, flightNumberToDelete, departureDateToDelete);
    }

    // Метод для поиска и вывода заявок по номеру рейса и дате вылета
    void printByFlightNumberAndDate(int flightNumberToFind, const string& departureDateToFind) {
        printByFlightNumberAndDateHelper(root, flightNumberToFind, departureDateToFind);
    }

    // Метод для вывода всех заявок
    void printAll() {
        printAllHelper(root);
    }

private:
    // Вспомогательная функция для вывода заявок по номеру рейса и дате вылета
    void printByFlightNumberAndDateHelper(BinaryTreeNode* node, int flightNumberToFind, const string& departureDateToFind) {
        if (node == nullptr) return;
        printByFlightNumberAndDateHelper(node->left, flightNumberToFind, departureDateToFind);
        if (node->data.flightNumber == flightNumberToFind && node->data.departureDate == departureDateToFind) {
            cout << "Пункт назначения: " << node->data.destination << ", Номер рейса: " << node->data.flightNumber << ", Фамилия и инициалы пассажира: " << node->data.passengerName << ", Желаемая дата вылета: " << node->data.departureDate << endl;
        }
        printByFlightNumberAndDateHelper(node->right, flightNumberToFind, departureDateToFind);
    }

    // Вспомогательная функция для вывода всех заявок
    void printAllHelper(BinaryTreeNode* node) {
        if (node == nullptr) return;
        printAllHelper(node->left);
        cout << "Пункт назначения: " << node->data.destination << ", Номер рейса: " << node->data.flightNumber << ", Фамилия и инициалы пассажира: " << node->data.passengerName << ", Желаемая дата вылета: " << node->data.departureDate << endl;
        printAllHelper(node->right);
    }
};