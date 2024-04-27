#include <iostream>
using namespace std;

// ��������� ��� �������� ���������� � ������ �� ���������
struct Ticket {
    string destination;
    int flightNumber;
    string passengerName;
    string departureDate;
};

// �����, �������������� ���� ��������� ������
class BinaryTreeNode {
public:
    Ticket data; // ���������� � ������
    BinaryTreeNode* left; // ��������� �� ����� ���������
    BinaryTreeNode* right; // ��������� �� ������ ���������

    // ����������� ��� ���� ��������� ������
    BinaryTreeNode(Ticket ticket) {
        data = ticket;
        left = nullptr;
        right = nullptr;
    }
};

// �����, �������������� �������� ������ ��� �������� ������ �� ����������
class BinaryTree {
private:
    BinaryTreeNode* root; // ��������� �� ������ ������

    // ��������������� ������� ��� �������� ���� �� ����� (������ ����� � ���� ������)
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

    // ��������������� ������� ��� ������ ���� � ����������� ������ � ���������
    BinaryTreeNode* minValueNode(BinaryTreeNode* node) {
        BinaryTreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

public:
    // ����������� ��� ��������� ������
    BinaryTree() {
        root = nullptr;
    }

    // ����� ��� ������� ������ � ������
    void insert(Ticket ticket) {
        if (root == nullptr) {
            root = new BinaryTreeNode(ticket);
        }
        else {
            insertHelper(root, ticket);
        }
    }

    // ��������������� ������� ��� ������� ������ � ������
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

    // ����� ��� �������� ������ �� ������ ����� � ���� ������
    void deleteByFlightNumberAndDate(int flightNumberToDelete, const string& departureDateToDelete) {
        root = deleteNode(root, flightNumberToDelete, departureDateToDelete);
    }

    // ����� ��� ������ � ������ ������ �� ������ ����� � ���� ������
    void printByFlightNumberAndDate(int flightNumberToFind, const string& departureDateToFind) {
        printByFlightNumberAndDateHelper(root, flightNumberToFind, departureDateToFind);
    }

    // ����� ��� ������ ���� ������
    void printAll() {
        printAllHelper(root);
    }

private:
    // ��������������� ������� ��� ������ ������ �� ������ ����� � ���� ������
    void printByFlightNumberAndDateHelper(BinaryTreeNode* node, int flightNumberToFind, const string& departureDateToFind) {
        if (node == nullptr) return;
        printByFlightNumberAndDateHelper(node->left, flightNumberToFind, departureDateToFind);
        if (node->data.flightNumber == flightNumberToFind && node->data.departureDate == departureDateToFind) {
            cout << "����� ����������: " << node->data.destination << ", ����� �����: " << node->data.flightNumber << ", ������� � �������� ���������: " << node->data.passengerName << ", �������� ���� ������: " << node->data.departureDate << endl;
        }
        printByFlightNumberAndDateHelper(node->right, flightNumberToFind, departureDateToFind);
    }

    // ��������������� ������� ��� ������ ���� ������
    void printAllHelper(BinaryTreeNode* node) {
        if (node == nullptr) return;
        printAllHelper(node->left);
        cout << "����� ����������: " << node->data.destination << ", ����� �����: " << node->data.flightNumber << ", ������� � �������� ���������: " << node->data.passengerName << ", �������� ���� ������: " << node->data.departureDate << endl;
        printAllHelper(node->right);
    }
};