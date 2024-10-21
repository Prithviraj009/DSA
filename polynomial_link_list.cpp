#include<iostream>
using namespace std;

class node {
public:
    int coeff, exp;  // Coefficient and Exponent
    node* next;

    // Constructor to initialize node
    node(int c, int e) {
        coeff = c;
        exp = e;
        next = nullptr;
    }
};

class implementation {
    node* head;  // Pointer to the first node

public:
    // Constructor to initialize head pointer
    implementation() {
        head = nullptr;
    }

    // Insert a new term in the polynomial
    void insert(int coeff, int exp) {
        node* nn = new node(coeff, exp);  // Create a new node
        if (head == nullptr) {
            head = nn;  // If the list is empty, set the new node as head
        } else {
            node* temp = head;
            while (temp->next != nullptr) {  // Traverse to the end of the list
                temp = temp->next;
            }
            temp->next = nn;  // Add the new node at the end
        }
    }

    // Function to add two polynomials
    implementation add(implementation second) {
        node* firstp = this->head;
        node* secondp = second.head;
        implementation result;

        while (firstp != nullptr && secondp != nullptr) {
            if (firstp->exp == secondp->exp) {
                result.insert(firstp->coeff + secondp->coeff, firstp->exp);
                firstp = firstp->next;
                secondp = secondp->next;
            } else if (firstp->exp > secondp->exp) {
                result.insert(firstp->coeff, firstp->exp);
                firstp = firstp->next;
            } else {
                result.insert(secondp->coeff, secondp->exp);
                secondp = secondp->next;
            }
        }

        // If terms are left in the first polynomial, add them to the result
        while (firstp != nullptr) {
            result.insert(firstp->coeff, firstp->exp);
            firstp = firstp->next;
        }

        // If terms are left in the second polynomial, add them to the result
        while (secondp != nullptr) {
            result.insert(secondp->coeff, secondp->exp);
            secondp = secondp->next;
        }

        return result;
    }

    // Function to display the polynomial
    void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->coeff << "x^" << temp->exp;
            if (temp->next != nullptr)
                cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    implementation poly1, poly2, result;

    // First polynomial: 3x^2 + 5x^1 + 6
    poly1.insert(3, 2);
    poly1.insert(5, 1);
    poly1.insert(6, 0);

    // Second polynomial: 6x^1 + 8
    poly2.insert(6, 1);
    poly2.insert(8, 0);

    // Add two polynomials
    result = poly1.add(poly2);

    // Display the result
    cout << "First polynomial: ";
    poly1.display();

    cout << "Second polynomial: ";
    poly2.display();

    cout << "Resultant polynomial: ";
    result.display();

    return 0;
}
